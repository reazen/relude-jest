open ReJest;
open Expect;

////////////////////////////////////////////////////////////////////////////////
// Domain types
////////////////////////////////////////////////////////////////////////////////

module User = {
  type t = {
    id: string,
    name: string,
    phone: string,
  };
};

module Shift = {
  type t = {
    id: string,
    title: string,
    hourlyRateCents: int,
  };
};

module WorkerShift = {
  type t = {
    id: string,
    userId: string,
    shiftId: string,
  };
};

////////////////////////////////////////////////////////////////////////////////
// Utility service interfaces
////////////////////////////////////////////////////////////////////////////////

type logLevel = [ | `debug | `info | `warn | `error];

module type LOGGER = {
  type level = logLevel;

  let log: (~level: level, string) => unit;
};

////////////////////////////////////////////////////////////////////////////////
// Data access service interfaces
//
// These are trying to emulate having a shared "connection" type that is threaded
// through all the functions, like a db connection/transaction
////////////////////////////////////////////////////////////////////////////////

// This is emulating the interface for the shared connection type
// For the real implementation, this would be like a pg connection
// For the mock implementation, it can be anything
module type CONNECTION = {type t;};

module type USER_REPO = {
  type connection;

  let getUser: (~id: string, connection) => Js.Promise.t(User.t);
};

module type SHIFT_REPO = {
  type connection;

  let getShift: (~id: string, connection) => Js.Promise.t(Shift.t);
};

module type WORKER_SHIFT_REPO = {
  type connection;

  let createWorkerShift:
    (~user: User.t, ~shift: Shift.t, connection) =>
    Js.Promise.t(WorkerShift.t);
};

////////////////////////////////////////////////////////////////////////////////
// "Business logic" services - these tend to combine multiple lower-level services
// to accomplish some bigger workflow
////////////////////////////////////////////////////////////////////////////////

module type SHIFT_SERVICE = {
  type connection;

  let acceptShift:
    (~userId: string, ~shiftId: string, connection) =>
    Js.Promise.t(WorkerShift.t);
};

////////////////////////////////////////////////////////////////////////////////
// Module under test
////////////////////////////////////////////////////////////////////////////////

// This is a "real" implementation of a business workflow, using some abstract lower-level
// services. This is the function we are aiming to test.
// Use `with type` to align all the internal connection types
module ShiftService =
       (
         Connection: CONNECTION,
         Logger: LOGGER,
         UserRepo: USER_REPO with type connection = Connection.t,
         ShiftRepo: SHIFT_REPO with type connection = Connection.t,
         WorkerShiftRepo:
           WORKER_SHIFT_REPO with type connection = Connection.t,
       )
       : (SHIFT_SERVICE with type connection = Connection.t) => {
  type connection = Connection.t;

  let acceptShift =
      (~userId: string, ~shiftId: string, connection)
      : Js.Promise.t(WorkerShift.t) =>
    UserRepo.getUser(~id=userId, connection)
    |> Js.Promise.then_((user: User.t) =>
         ShiftRepo.getShift(~id=shiftId, connection)
         |> Js.Promise.then_((shift: Shift.t) => {
              Logger.log(~level=`debug, "accepted");
              WorkerShiftRepo.createWorkerShift(~user, ~shift, connection);
            })
       );
};

////////////////////////////////////////////////////////////////////////////////
// Mock implementations
////////////////////////////////////////////////////////////////////////////////

// Dummy data

let testUser: User.t = {id: "user1", name: "Bob", phone: "5555555555"};

let testShift: Shift.t = {
  id: "shift1",
  title: "Dishwasher",
  hourlyRateCents: 2000,
};

let testWorkerShift: WorkerShift.t = {
  id: "workerShift1",
  userId: testUser.id,
  shiftId: testShift.id,
};

module MockConnection: CONNECTION with type t = string = {
  type t = string;
};

let testConnection: MockConnection.t = "xyz";

// Mock functions

let mockLog = Mock.make2((_level, _message) => ());

let mockGetUser =
  Mock.make2((_id: string, _connection: MockConnection.t) =>
    Js.Promise.resolve(testUser)
  );

let mockGetShift =
  Mock.make2((_id: string, _connection: MockConnection.t) =>
    Js.Promise.resolve(testShift)
  );

let mockCreateWorkerShift =
  Mock.make3((_user: User.t, _shift: Shift.t, _connection: MockConnection.t) =>
    Js.Promise.resolve(testWorkerShift)
  );

// Mocked implementations of low-level services

module MockLogger: LOGGER = {
  type level = logLevel;

  let log = (~level: level, message) => mockLog->Mock.fn(level, message);
};

module MockUserRepo: USER_REPO with type connection = MockConnection.t = {
  type connection = MockConnection.t;

  let getUser = (~id: string, connection: MockConnection.t) =>
    mockGetUser->Mock.fn(id, connection);
};

module MockShiftRepo: SHIFT_REPO with type connection = MockConnection.t = {
  type connection = MockConnection.t;

  let getShift = (~id: string, connection: MockConnection.t) =>
    mockGetShift->Mock.fn(id, connection);
};

module MockWorkerShiftRepo:
  WORKER_SHIFT_REPO with type connection = MockConnection.t = {
  type connection = MockConnection.t;

  let createWorkerShift =
      (~user: User.t, ~shift: Shift.t, connection: MockConnection.t) =>
    mockCreateWorkerShift->Mock.fn(user, shift, connection);
};

// Create a real instance of the `ShiftService`, but using all mock dependencies.
// The idea here is to make sure the `ShiftService` logic does what we expect, but
// without actually calling real versions of the dependencies.

// NB: there are many different ways of doing this with mocks - this is just an example

module TestShiftService =
  ShiftService(
    MockConnection,
    MockLogger,
    MockUserRepo,
    MockShiftRepo,
    MockWorkerShiftRepo,
  );

describe("ShiftService", () => {
  beforeEach(() => {
    // Since the mock functions are "global" we need to reset/clear them
    // between each test
    mockLog->Mock.mockClear;
    mockGetUser->Mock.mockClear;
    mockGetShift->Mock.mockClear;
    mockCreateWorkerShift->Mock.mockClear;
  });

  testPromise("acceptShift", () => {
    TestShiftService.acceptShift(
      ~userId=testUser.id,
      ~shiftId=testShift.id,
      testConnection,
    )
    |> Js.Promise.then_(workerShift => {
         expect(workerShift)->toEqual(testWorkerShift);

         expect(mockGetUser)
         ->toHaveBeenCalledWith2(testUser.id, testConnection);

         expect(mockGetShift)
         ->toHaveBeenCalledWith2(testShift.id, testConnection);

         expect(mockCreateWorkerShift)
         ->toHaveBeenCalledWith3(testUser, testShift, testConnection);

         expect(mockLog)->toBeCalledTimes(1);
         expect(mockLog)->toHaveBeenCalledWith2(`debug, "accepted");

         Js.Promise.resolve();
       })
  });

  // Just another example to show that the mocks are being cleared between each test
  test("log", () => {
    MockLogger.log(~level=`info, "info");
    MockLogger.log(~level=`warn, "warn");

    expect(mockLog)->toBeCalledTimes(2);
    expect(mockLog)->toHaveBeenNthCalledWith2(1, `info, "info");
    expect(mockLog)->toHaveBeenNthCalledWith2(2, `warn, "warn");
  });
});
