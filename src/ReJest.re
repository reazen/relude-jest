// Global Functions
[@bs.val]
external describe: (string, [@bs.uncurry] (unit => unit)) => unit = "describe";

module Describe = {
  [@bs.val] [@bs.scope "describe"]
  external only: (string, [@bs.uncurry] (unit => unit)) => unit = "only";

  [@bs.val] [@bs.scope "describe"]
  external skip: (string, [@bs.uncurry] (unit => unit)) => unit = "skip";

  [@bs.val] [@bs.scope "describe"]
  external each1: array('a) => (. string, 'a => unit) => unit = "each";

  [@bs.val] [@bs.scope "describe"]
  external each2: array(('a, 'b)) => (. string, ('a, 'b) => unit) => unit =
    "each";

  [@bs.val] [@bs.scope "describe"]
  external each3:
    array(('a, 'b, 'c)) => (. string, ('a, 'b, 'c) => unit) => unit =
    "each";

  [@bs.val] [@bs.scope "describe"]
  external each4:
    array(('a, 'b, 'c, 'd)) => (. string, ('a, 'b, 'c, 'd) => unit) => unit =
    "each";

  [@bs.val] [@bs.scope "describe"]
  external each5:
    array(('a, 'b, 'c, 'd, 'e)) =>
    (. string, ('a, 'b, 'c, 'd, 'e) => unit) => unit =
    "each";
};

[@bs.val]
external test: (string, [@bs.uncurry] (unit => unit)) => unit = "test";

[@bs.val]
external testPromise:
  (string, [@bs.uncurry] (unit => Js.Promise.t('a))) => unit =
  "test";

[@bs.val]
external testPromiseTimeout:
  (string, [@bs.uncurry] (unit => Js.Promise.t('a)), ~timeout: int) => unit =
  "test";

[@bs.val]
external testAsync: (. string, (unit => unit) => unit) => unit = "test";

[@bs.val]
external testAsyncTimeout:
  (string, [@bs.uncurry] (unit => Js.Promise.t('a)), ~timeout: int) => unit =
  "test";

// test closure
module Test = {
  [@bs.val] external it: (. string, (unit => unit) => unit) => unit = "test";

  [@bs.val]
  external itPromise:
    (string, [@bs.uncurry] (unit => Js.Promise.t('a))) => unit =
    "test";

  [@bs.val]
  external itPromiseTimeout:
    (string, [@bs.uncurry] (unit => Js.Promise.t('a)), ~timeout: int) => unit =
    "test";

  [@bs.val]
  external itAsync: (string, [@bs.uncurry] ((unit, unit) => unit)) => unit =
    "test";

  [@bs.val]
  external itAsyncTimeout:
    (string, [@bs.uncurry] ((unit, unit) => unit), ~timeout: int) => unit =
    "test";

  [@bs.val] [@bs.scope "test"]
  external only: (string, [@bs.uncurry] (unit => unit)) => unit = "only";

  [@bs.val] [@bs.scope "test"]
  external onlyPromise:
    (string, [@bs.uncurry] (unit => Js.Promise.t('a))) => unit =
    "only";

  [@bs.val] [@bs.scope "test"]
  external onlyPromiseTimeout:
    (string, [@bs.uncurry] (unit => Js.Promise.t('a)), ~timeout: int) => unit =
    "only";

  [@bs.val] [@bs.scope "test"]
  external onlyAsync: (string, [@bs.uncurry] ((unit, unit) => unit)) => unit =
    "only";

  [@bs.val] [@bs.scope "test"]
  external onlyAsyncTimeout:
    (string, [@bs.uncurry] ((unit, unit) => unit), ~timeout: int) => unit =
    "only";

  [@bs.val] [@bs.scope "test"]
  external failing: (string, [@bs.uncurry] (unit => unit)) => unit = "failing";

  [@bs.val] [@bs.scope "test"]
  external failingPromise:
    (string, [@bs.uncurry] (unit => Js.Promise.t('a))) => unit =
    "failing";

  [@bs.val] [@bs.scope "test"]
  external failingPromiseTimeout:
    (string, [@bs.uncurry] (unit => Js.Promise.t('a)), ~timeout: int) => unit =
    "failing";

  [@bs.val] [@bs.scope "test"]
  external failingAsync: (string, [@bs.uncurry] ((unit, unit) => unit)) => unit =
    "failing";

  [@bs.val] [@bs.scope "test"]
  external failingAsyncTimeout:
    (string, [@bs.uncurry] ((unit, unit) => unit), ~timeout: int) => unit =
    "failing";

  [@bs.val] [@bs.scope "test"]
  external skip: (string, [@bs.uncurry] (unit => unit)) => unit = "skip";

  [@bs.val] [@bs.scope "test"]
  external skipPromise:
    (string, [@bs.uncurry] (unit => Js.Promise.t('a))) => unit =
    "skip";

  [@bs.val] [@bs.scope "test"]
  external skipPromiseTimeout:
    (string, [@bs.uncurry] (unit => Js.Promise.t('a)), ~timeout: int) => unit =
    "skip";

  [@bs.val] [@bs.scope "test"]
  external skipAsync: (string, [@bs.uncurry] ((unit, unit) => unit)) => unit =
    "skip";

  [@bs.val] [@bs.scope "test"]
  external skipAsyncTimeout:
    (string, [@bs.uncurry] ((unit, unit) => unit), ~timeout: int) => unit =
    "skip";

  [@bs.val] [@bs.scope "test"] external todo: string => unit = "todo";

  [@bs.val] [@bs.scope "test"]
  external each1: array('a) => (. string, 'a => unit) => unit = "each";

  [@bs.val] [@bs.scope "test"]
  external each2: array(('a, 'b)) => (. string, ('a, 'b) => unit) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external each3:
    array(('a, 'b, 'c)) => (. string, ('a, 'b, 'c) => unit) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external each4:
    array(('a, 'b, 'c, 'd)) => (. string, ('a, 'b, 'c, 'd) => unit) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external each5:
    array(('a, 'b, 'c, 'd, 'e)) =>
    (. string, ('a, 'b, 'c, 'd, 'e) => unit) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachPromise1:
    array('a) => (. string, 'a => Js.Promise.t(unit)) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachPromise2:
    array(('a, 'b)) => (. string, ('a, 'b) => Js.Promise.t(unit)) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachPromise3:
    array(('a, 'b, 'c)) =>
    (. string, ('a, 'b, 'c) => Js.Promise.t(unit)) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachPromise4:
    array(('a, 'b, 'c, 'd)) =>
    (. string, ('a, 'b, 'c, 'd) => Js.Promise.t(unit)) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachPromise5:
    array(('a, 'b, 'c, 'd, 'e)) =>
    (. string, ('a, 'b, 'c, 'd, 'e) => Js.Promise.t(unit)) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachPromise1Timeout:
    array('a) => (. string, 'a => Js.Promise.t(unit), ~timeout: int) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachPromise2Timeout:
    array(('a, 'b)) =>
    (. string, ('a, 'b) => Js.Promise.t(unit), ~timeout: int) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachPromise3Timeout:
    array(('a, 'b, 'c)) =>
    (. string, ('a, 'b, 'c) => Js.Promise.t(unit), ~timeout: int) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachPromise4Timeout:
    array(('a, 'b, 'c, 'd)) =>
    (. string, ('a, 'b, 'c, 'd) => Js.Promise.t(unit), ~timeout: int) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachPromise5Timeout:
    array(('a, 'b, 'c, 'd, 'e)) =>
    (. string, ('a, 'b, 'c, 'd, 'e) => Js.Promise.t(unit), ~timeout: int) =>
    unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachAsync1:
    array('a) => (. string, ('a, unit => unit) => unit) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachAsync2:
    array(('a, 'b)) => (. string, ('a, 'b, unit => unit) => unit) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachAsync3:
    array(('a, 'b, 'c)) =>
    (. string, ('a, 'b, 'c, unit => unit) => unit) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachAsync4:
    array(('a, 'b, 'c, 'd)) =>
    (. string, ('a, 'b, 'c, 'd, unit => unit) => unit) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachAsync5:
    array(('a, 'b, 'c, 'd, 'e)) =>
    (. string, ('a, 'b, 'c, 'd, 'e, unit => unit) => unit) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachAsync1Timeout:
    array('a) =>
    (. string, 'a) => (. unit => unit, unit, ~timeout: int) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachAsync2Timeout:
    array(('a, 'b)) =>
    (. string, ('a, 'b) => (. (unit => unit)) => unit, ~timeout: int) => unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachAsync3Timeout:
    array(('a, 'b, 'c)) =>
    (. string, ('a, 'b, 'c) => (. (unit => unit)) => unit, ~timeout: int) =>
    unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachAsync4Timeout:
    array(('a, 'b, 'c, 'd)) =>
    (
      . string,
      ('a, 'b, 'c, 'd) => (. (unit => unit)) => unit,
      ~timeout: int
    ) =>
    unit =
    "each";

  [@bs.val] [@bs.scope "test"]
  external eachAsync5Timeout:
    array(('a, 'b, 'c, 'd, 'e)) =>
    (
      . string,
      ('a, 'b, 'c, 'd, 'e) => (. (unit => unit)) => unit,
      ~timeout: int
    ) =>
    unit =
    "each";
};

[@bs.val]
external beforeEach: ([@bs.uncurry] (unit => unit)) => unit = "beforeEach";

[@bs.val]
external beforeEachPromise: ([@bs.uncurry] (unit => Js.Promise.t('a))) => unit =
  "beforeEach";

[@bs.val]
external beforeEachPromiseTimeout:
  ([@bs.uncurry] (unit => Js.Promise.t('a)), ~timeout: int) => unit =
  "beforeEach";

[@bs.val]
external beforeEachAsync: ([@bs.uncurry] ((unit => unit) => unit)) => unit =
  "beforeEach";

[@bs.val]
external beforeEachAsyncTimeout:
  ([@bs.uncurry] ((unit => unit) => unit), ~timeout: int) => unit =
  "beforeEach";

[@bs.val]
external beforeAll: ([@bs.uncurry] (unit => unit)) => unit = "beforeAll";

[@bs.val]
external beforeAllPromise: ([@bs.uncurry] (unit => Js.Promise.t('a))) => unit =
  "beforeAll";

[@bs.val]
external beforeAllPromiseTimeout:
  ([@bs.uncurry] (unit => Js.Promise.t('a)), ~timeout: int) => unit =
  "beforeAll";

[@bs.val]
external beforeAllAsync: ([@bs.uncurry] ((unit => unit) => unit)) => unit =
  "beforeAll";

[@bs.val]
external beforeAllAsyncTimeout:
  ([@bs.uncurry] ((unit => unit) => unit), ~timeout: int) => unit =
  "beforeAll";

[@bs.val]
external afterEach: ([@bs.uncurry] (unit => unit)) => unit = "afterEach";

[@bs.val]
external afterEachPromise: ([@bs.uncurry] (unit => Js.Promise.t('a))) => unit =
  "afterEach";

[@bs.val]
external afterEachPromiseTimeout:
  ([@bs.uncurry] (unit => Js.Promise.t('a)), ~timeout: int) => unit =
  "afterEach";

[@bs.val]
external afterEachAsync: ([@bs.uncurry] ((unit => unit) => unit)) => unit =
  "afterEach";

[@bs.val]
external afterEachAsyncTimeout:
  ([@bs.uncurry] ((unit, unit) => unit), ~timeout: int) => unit =
  "afterEach";

[@bs.val]
external afterAll: ([@bs.uncurry] (unit => unit)) => unit = "afterAll";

[@bs.val]
external afterAllPromise: ([@bs.uncurry] (unit => Js.Promise.t('a))) => unit =
  "afterAll";

[@bs.val]
external afterAllPromiseTimeout:
  ([@bs.uncurry] (unit => Js.Promise.t('a)), ~timeout: int) => unit =
  "afterAll";

[@bs.val]
external afterAllAsync: ([@bs.uncurry] ((unit, unit) => unit)) => unit =
  "afterAll";

[@bs.val]
external afterAllAsyncTimeout:
  ([@bs.uncurry] ((unit, unit) => unit), ~timeout: int) => unit =
  "afterAll";

// Mock Module
module Mock = {
  type t('fn, 'args, 'return);

  external fn: t('fn, _, _) => 'fn = "%identity";

  [@bs.val] [@bs.scope "jest"]
  external empty: unit => t(unit => unit, unit, unit) = "fn";

  [@bs.val] [@bs.scope "jest"]
  external make: ('a => 'b) => t('a => 'b, 'a, 'b) = "fn";

  [@bs.val] [@bs.scope "jest"]
  external make2:
    (('a, 'b) => 'return) => t(('a, 'b) => 'return, ('a, 'b), 'return) =
    "fn";

  [@bs.val] [@bs.scope "jest"]
  external make3:
    (('a, 'b, 'c) => 'return) =>
    t(('a, 'b, 'c) => 'return, ('a, 'b, 'c), 'return) =
    "fn";

  [@bs.val] [@bs.scope "jest"]
  external spyOn: ('spy, string) => t('a, 'b, 'c) = "spyOn";

  // TODO
  //[@bs.scope "jest"]
  //external spyOnGetter: ('spy, string, [@bs.as] ("json`'get'`") _) => t('a, 'b, 'c) = "spyOn";

  //[@bs.scope "jest"]
  //external spyOnSetter: ('spy, string, [@bs.as] ("json`'set'`") _) => t('a, 'b, 'c) = "spyOn";

  // mock property
  type return_node('a) = {
    [@bs.as "type"]
    type_: [ | `return | `throw | `incomplete],
    value: 'a,
  };

  [@bs.get] [@bs.scope "mock"]
  external calls: t(_, 'args, _) => array('args) = "calls";

  [@bs.get] [@bs.scope "mock"]
  external callsWrapArray: t(_, 'args, _) => array(array('args)) = "calls";

  [@bs.get] [@bs.scope "mock"]
  external _results: t(_, _, 'return) => array(return_node('return)) =
    "results";

  type result_type('return, 'error) =
    | Return('return)
    | Throw('error)
    | Imcomplete;

  let results =
      (mock: t(_, _, 'return)): array(result_type('return, 'error)) => {
    mock
    ->_results
    ->Belt.Array.map(result =>
        switch (result.type_) {
        | `return => Return(result.value)
        | `throw => Throw(result.value)
        | `incomplete => Imcomplete
        }
      );
  };

  [@bs.get] [@bs.scope "mock"]
  external instances: t(_, _, 'return) => array('return) = "instances";

  external lastCall: t(_, 'args, _) => option('args) = "lastCall";

  external lastCallWrapArray: t(_, 'args, _) => option(array('args)) =
    "lastCall";

  // functions
  [@bs.send] external getMockName: t(_, _, _) => string = "getMockName";

  [@bs.send] external setMockname: (t(_, _, _), string) => unit = "mockName";

  [@bs.send] external mockClear: t(_, _, _) => unit = "mockClear";

  [@bs.send] external mockReset: t(_, _, _) => unit = "mockReset";

  [@bs.send] external mockRestore: t(_, _, _) => unit = "mockRestore";

  [@bs.send]
  external mockImplementation: (t('fn, _, _), 'fn) => unit =
    "mockImplementation";

  [@bs.send]
  external mockImplementationOnce: (t('fn, _, _), 'fn) => unit =
    "mockImplementationOnce";

  [@bs.send]
  external mockReturnValue: (t(_, _, 'return), 'return) => unit =
    "mockReturnValue";

  [@bs.send]
  external mockReturnValueOnce: (t(_, _, 'return), 'return) => unit =
    "mockReturnValueOnce";

  [@bs.send]
  external mockResolvedValue:
    (t(_, _, Js.Promise.t('return)), 'return) => unit =
    "mockResolvedValue";

  [@bs.send]
  external mockResolvedValueOnce:
    (t(_, _, Js.Promise.t('return)), 'return) => unit =
    "mockResolvedValueOnce";

  [@bs.send]
  external mockRejectedValue: (t(_, _, _), 'b) => unit = "mockRejectedValue";

  [@bs.send]
  external mockRejectedValueOnce: (t(_, _, _), 'b) => unit =
    "mockRejectedValueOnce";
};

type expect('r, 'expect_ret);

module Expect = {
  [@bs.get]
  external not: expect('value, 'expect_ret) => expect('value, 'expect_ret) =
    "not";

  [@bs.get]
  external unsafe: expect('value, 'expect_ret) => expect('b, 'expect_ret) =
    "%identity";

  [@bs.get]
  external resolves:
    expect(Js.Promise.t('value), 'expect_ret) =>
    expect('value, Js.Promise.t(unit)) =
    "resolves";

  [@bs.get]
  external rejects:
    expect(Js.Promise.t('value), 'expect_ret) =>
    expect('error, Js.Promise.t(unit)) =
    "rejects";

  [@bs.send]
  external toBe: (expect('value, 'expect_ret), 'value) => 'expect_ret =
    "toBe";

  [@bs.send]
  external toEqual: (expect('value, 'expect_ret), 'value) => 'expect_ret =
    "toEqual";

  [@bs.send]
  external toStrictEqual: (expect('value, 'expect_ret), 'value) => 'expect_ret =
    "toStrictEqual";

  /* TODO
     let toHaveBeenLastCalledWith:
       (expect(Mock.t(_, 'arg, _), 'expect_ret), 'arg) => 'expect_ret = [%bs.raw
       "function (fn, args) {
          return expect(fn).toHaveBeenLastCalledWith(...(Array.isArray(args) ? args : [args]));
        }"
     ];
     */

  [@bs.send]
  external toHaveBeenLastCalledWith1:
    (expect(Mock.t(_, 'arg1, _), 'expect_ret), 'arg1) => 'expect_ret =
    "toHaveBeenLastCalledWith";

  [@bs.send]
  external toHaveBeenLastCalledWith2:
    (expect(Mock.t(_, ('arg1, 'arg2), _), 'expect_ret), 'arg1, 'arg2) =>
    'expect_ret =
    "toHaveBeenLastCalledWith";

  [@bs.send]
  external toHaveBeenLastCalledWith3:
    (
      expect(Mock.t(_, ('arg1, 'arg2), _), 'expect_ret),
      'arg1,
      'arg2,
      'arg3
    ) =>
    'expect_ret =
    "toHaveBeenLastCalledWith";

  [@bs.send]
  external toHaveBeenLastCalledWith4:
    (
      expect(Mock.t(_, ('arg1, 'arg2, 'arg3, 'arg4), _), 'expect_ret),
      'arg1,
      'arg2,
      'arg3,
      'arg4
    ) =>
    'expect_ret =
    "toHaveBeenLastCalledWith";

  [@bs.send]
  external toHaveBeenLastCalledWith5:
    (
      expect(Mock.t(_, ('arg1, 'arg2, 'arg3, 'arg4, 'arg5), _), 'expect_ret),
      'arg1,
      'arg2,
      'arg3,
      'arg4,
      'arg5
    ) =>
    'expect_ret =
    "toHaveBeenLastCalledWith";

  [@bs.send]
  external toHaveLastReturnedWith:
    (expect(Mock.t(_, _, 'return), 'expect_ret), 'return) => 'expect_ret =
    "toHaveLastReturnedWith";

  /* TODO
     let toHaveBeenNthCalledWith:
       (expect(Mock.t(_, 'arg, _), 'expect_ret), int, 'arg) => 'expect_ret = [%bs.raw
       {|
           function (fn, nth, args) {
             return expect(fn).toHaveBeenNthCalledWith(nth, ...(Array.isArray(args) ? args : [args]));
           }
         |}
     ];
     */

  [@bs.send]
  external toHaveBeenNthCalledWith1:
    (expect(Mock.t(_, 'arg1, _), 'expect_ret), int, 'arg1) => 'expect_ret =
    "toHaveBeenNthCalledWith";

  [@bs.send]
  external toHaveBeenNthCalledWith2:
    (
      expect(Mock.t(_, ('arg1, 'arg2), _), 'expect_ret),
      int,
      'arg1,
      'arg2
    ) =>
    'expect_ret =
    "toHaveBeenNthCalledWith";

  [@bs.send]
  external toHaveBeenNthCalledWith3:
    (
      expect(Mock.t(_, ('arg1, 'arg2), _), 'expect_ret),
      int,
      'arg1,
      'arg2,
      'arg3
    ) =>
    'expect_ret =
    "toHaveBeenNthCalledWith";

  [@bs.send]
  external toHaveBeenNthCalledWith4:
    (
      expect(Mock.t(_, ('arg1, 'arg2, 'arg3, 'arg4), _), 'expect_ret),
      int,
      'arg1,
      'arg2,
      'arg3,
      'arg4
    ) =>
    'expect_ret =
    "toHaveBeenNthCalledWith";

  [@bs.send]
  external toHaveBeenNthCalledWith5:
    (
      expect(Mock.t(_, ('arg1, 'arg2, 'arg3, 'arg4, 'arg5), _), 'expect_ret),
      int,
      'arg1,
      'arg2,
      'arg3,
      'arg4,
      'arg5
    ) =>
    'expect_ret =
    "toHaveBeenNthCalledWith";

  [@bs.send]
  external toHaveNthReturnedWith:
    (expect(Mock.t(_, _, 'return), 'expect_ret), int, 'return) => 'expect_ret =
    "toHaveNthReturnedWith";

  [@bs.send]
  external toBeCalled: expect(Mock.t(_, _, _), 'expect_ret) => 'expect_ret =
    "toBeCalled";

  [@bs.send]
  external toBeCalledTimes:
    (expect(Mock.t(_, _, _), 'expect_ret), int) => 'expect_ret =
    "toBeCalledTimes";

  /* Warning: if your mock function argument length is 1 and type is array, use 'toHaveBeenCalledWith1' safety */
  /* TODO
     let toHaveBeenCalledWith: (
       expect(Mock.t(_, 'arg, _), 'expect_ret),
       'arg,
     ) => 'expect_ret = %raw(`function (fn, args) {
       return expect(fn).toHaveBeenCalledWith(...(Array.isArray(args) ? args : [args]));
     }`)
     */

  [@bs.send]
  external toHaveBeenCalledWith1:
    (expect(Mock.t(_, 'arg1, _), 'expect_ret), 'arg1) => 'expect_ret =
    "toHaveBeenCalledWith";

  [@bs.send]
  external toHaveBeenCalledWith2:
    (expect(Mock.t(_, ('arg1, 'arg2), _), 'expect_ret), 'arg1, 'arg2) =>
    'expect_ret =
    "toHaveBeenCalledWith";

  [@bs.send]
  external toHaveBeenCalledWith3:
    (
      expect(Mock.t(_, ('arg1, 'arg2), _), 'expect_ret),
      'arg1,
      'arg2,
      'arg3
    ) =>
    'expect_ret =
    "toHaveBeenCalledWith";

  [@bs.send]
  external toHaveBeenCalledWith4:
    (
      expect(Mock.t(_, ('arg1, 'arg2, 'arg3, 'arg4), _), 'expect_ret),
      'arg1,
      'arg2,
      'arg3,
      'arg4
    ) =>
    'expect_ret =
    "toHaveBeenCalledWith";

  [@bs.send]
  external toHaveBeenCalledWith5:
    (
      expect(Mock.t(_, ('arg1, 'arg2, 'arg3, 'arg4, 'arg5), _), 'expect_ret),
      'arg1,
      'arg2,
      'arg3,
      'arg4,
      'arg5
    ) =>
    'expect_ret =
    "toHaveBeenCalledWith";

  [@bs.send]
  external toHaveReturned:
    expect(Mock.t(_, _, _), 'expect_ret) => 'expect_ret =
    "toHaveReturned";

  [@bs.send]
  external toHaveReturnedWith:
    (expect(Mock.t(_, _, 'return), 'expect_ret), 'return) => 'expect_ret =
    "toHaveReturnedWith";

  [@bs.send]
  external toBeCloseTo: (expect(float, 'expect_ret), float) => 'expect_ret =
    "toBeCloseTo";

  [@bs.send]
  external toBeCloseToWithDigit:
    (expect(float, 'expect_ret), float, int) => 'expect_ret =
    "toBeCloseTo";

  [@bs.send]
  external toBeDefined: expect('value, 'expect_ret) => 'expect_ret =
    "toBeDefined";

  [@bs.send]
  external toBeFalsy: expect('value, 'expect_ret) => 'expect_ret =
    "toBeFalsy";

  [@bs.send]
  external toBeTruthy: expect('value, 'expect_ret) => 'expect_ret =
    "toBeTruthy";

  [@bs.send]
  external toBeGreaterThan: (expect(int, 'expect_ret), int) => 'expect_ret =
    "toBeGreaterThan";

  [@bs.send]
  external toBeGreaterThanOrEqual:
    (expect(int, 'expect_ret), int) => 'expect_ret =
    "toBeGreaterThanOrEqual";

  [@bs.send]
  external toBeGreaterThanFloat:
    (expect(float, 'expect_ret), float) => 'expect_ret =
    "toBeGreaterThan";

  [@bs.send]
  external toBeGreaterThanOrEqualFloat:
    (expect(float, 'expect_ret), float) => 'expect_ret =
    "toBeGreaterThanOrEqual";

  [@bs.send]
  external toBeLessThan: (expect(int, 'expect_ret), int) => 'expect_ret =
    "toBeLessThan";

  [@bs.send]
  external toBeLessThanOrEqual: (expect(int, 'expect_ret), int) => 'expect_ret =
    "toBeLessThanOrEqual";

  [@bs.send]
  external toBeLessThanFloat:
    (expect(float, 'expect_ret), float) => 'expect_ret =
    "toBeLessThan";

  [@bs.send]
  external toBeLessThanOrEqualFloat:
    (expect(float, 'expect_ret), float) => 'expect_ret =
    "toBeLessThanOrEqual";

  [@bs.send]
  external toBeNull:
    expect(Js.Nullable.t('value), 'expect_ret) => 'expect_ret =
    "toBeNull";

  [@bs.send]
  external toBeUndefined:
    expect(Js.Undefined.t('value), 'expect_ret) => 'expect_ret =
    "toBeUndefined";

  [@bs.send]
  external toBeNaN: expect(int, 'expect_ret) => 'expect_ret = "toBeNaN";

  [@bs.send]
  external toBeNaNFloat: expect(float, 'expect_ret) => 'expect_ret =
    "toBeNaN";

  [@bs.send]
  external toContain:
    (expect(array('value), 'expect_ret), 'value) => 'expect_ret =
    "toContain";

  [@bs.send]
  external toContainEqual:
    (expect(array('value), 'expect_ret), 'value) => 'expect_ret =
    "toContainEqual";

  [@bs.send]
  external toHaveLength:
    (expect(array('value), 'expect_ret), int) => 'expect_ret =
    "toHaveLength";

  [@bs.send]
  external toHaveProperty:
    (expect('value, 'expect_ret), string) => 'expect_ret =
    "toHaveProperty";

  [@bs.send]
  external toHavePropertyValue:
    (expect('value, 'expect_ret), string, 'b) => 'expect_ret =
    "toHaveProperty";

  [@bs.send]
  external toMatch: (expect(string, 'expect_ret), Js.Re.t) => 'expect_ret =
    "toMatch";

  [@bs.send]
  external toMatchString: (expect(string, 'expect_ret), string) => 'expect_ret =
    "toMatch";

  [@bs.send]
  external toMatchObject: (expect('value, 'expect_ret), {..}) => 'expect_ret =
    "toMatchObject";

  [@bs.send]
  external toMatchSnapshot: expect('value, 'expect_ret) => 'expect_ret =
    "toMatchSnapshot";

  [@bs.send]
  external toMatchInlineSnapshot: expect('value, 'expect_ret) => 'expect_ret =
    "toMatchInlineSnapshot";

  [@bs.send]
  external toThrow: expect('value, 'expect_ret) => 'expect_ret = "toThrow";

  [@bs.send]
  external toThrowString: (expect('value, 'expect_ret), string) => 'expect_ret =
    "toThrow";

  [@bs.send]
  external toThrowRegexp:
    (expect('value, 'expect_ret), Js.Re.t) => 'expect_ret =
    "toThrow";

  [@bs.send]
  external toThrowError:
    (expect('value, 'expect_ret), Js.Exn.t) => 'expect_ret =
    "toThrow";
};

[@bs.val] external expect: 'value => expect('value, unit) = "expect";

module ExpectStatic = {
  [@bs.val] [@bs.scope "expect"] external anything: unit => 'a = "anything";

  let anyInt: unit => int = [%raw "function () { return expect.any(Number) }"];

  let anyFloat: unit => float = [%raw
    "function () { return expect.any(Number) }"
  ];

  let anyString: unit => float = [%raw
    "function () { return expect.any(String) }"
  ];

  [@bs.val] [@bs.scope "expect"] external any: 'b => 'a = "any";

  [@bs.val] [@bs.scope "expect"]
  external arrayContaining: array('a) => array('a) = "arrayContaining";

  [@bs.val] [@bs.scope "expect"]
  external objectContaining: {..} => 'a = "objectContaining";

  [@bs.val] [@bs.scope "expect"]
  external stringContaining: string => string = "stringContaining";

  [@bs.val] [@bs.scope "expect"]
  external stringMatching: Js.Re.t => string = "stringMatching";

  [@bs.val] [@bs.scope ("expect", "not")]
  external notArrayContaining: array('a) => array('a) = "arrayContaining";

  [@bs.val] [@bs.scope ("expect", "not")]
  external notObjectContaining: {..} => 'a = "objectContaining";

  [@bs.val] [@bs.scope ("expect", "not")]
  external notStringContaining: string => string = "stringContaining";

  [@bs.val] [@bs.scope ("expect", "not")]
  external notStringMatching: Js.Re.t => string = "stringMatching";

  [@bs.val] [@bs.scope "expect"] external closeTo: float => float = "closeTo";

  [@bs.val] [@bs.scope "expect"]
  external closeToWithDigit: (float, int) => float = "closeTo";

  [@bs.val] [@bs.scope "expect"]
  external assertions: int => unit = "assertions";

  [@bs.val] [@bs.scope "expect"]
  external hasAssertions: unit => unit = "hasAssertions";
};

// Jest Module
module JestJs = {
  external require: string => 'a = "require";

  [@bs.val] [@bs.scope "jest"]
  external requireActual: string => 'a = "requireActual";

  [@bs.val] [@bs.scope "jest"]
  external requireMock: string => 'a = "requireMock";

  // mock packages
  [@bs.val] [@bs.scope "jest"] external mock: string => unit = "mock";

  [@bs.val] [@bs.scope "jest"]
  external mockFactoryUnsafe: (string, unit => 'a) => unit = "mock";

  type factoryResult('mod_) =
    | Default('mod_)
    | EsModule('mod_)
    | WithActual('mod_)
    | WithActualEsModule('mod_);

  /* TODO
     let mockFactory = (name: string, callback: unit => factoryResult('mod_)) => {
       mockFactoryUnsafe(name, () => {
         switch callback() {
         | Default(mod_) => mod_
         | EsModule(mod_) => Js.Obj.assign({"__esModule": true}, mod_)
         | WithActual(mod_) => Js.Obj.assign(requireActual(name), mod_)
         | WithActualEsModule(mod_) =>
           Js.Obj.assign({"__esModule": true}, requireActual(name))->Js.Obj.assign(mod_)
         };
       });
     };
     */

  /* TODO
     [@bs.scope "jest"]
     external mockFactoryVirtual: (string, unit => 'a, [@bs.as] (json`{virtual: true }`) _) => unit = "mock";
     */

  [@bs.val] [@bs.scope "jest"] external dontMock: string => unit = "dontMock";

  [@bs.val] [@bs.scope "jest"] external doMock: string => unit = "doMock";

  [@bs.val] [@bs.scope "jest"]
  external doMockFactoryUnsafe: (string, unit => 'a) => unit = "doMock";

  /* TODO
     let doMockFactory = (name: string, callback: unit => factoryResult('mod_)) => {
       doMockFactoryUnsafe(name, () => {
         switch (callback()) {
         | Default(mod_) => mod_
         | EsModule(mod_) => Js.Obj.assign({"__esModule": true}, mod_)
         | WithActual(mod_) => Js.Obj.assign(requireActual(name), mod_)
         | WithActualEsModule(mod_) =>
           Js.Obj.assign({"__esModule": true}, requireActual(name))->Js.Obj.assign(mod_)
         };
       });
     };
     */

  /* TODO
     [@bs.scope "jest"]
     external doMockFactoryVirtual: (string, unit => 'a, [@bs.as] (json`{virtual: true }`) _) => unit =
       "doMock";
       */

  // global functions
  [@bs.val] [@bs.scope "jest"]
  external autoMockOff: unit => unit = "autoMockOff";

  [@bs.val] [@bs.scope "jest"]
  external autoMockOn: unit => unit = "autoMockOn";

  [@bs.val] [@bs.scope "jest"]
  external clearAllMocks: unit => unit = "clearAllMocks";

  [@bs.val] [@bs.scope "jest"]
  external resetAllMocks: unit => unit = "resetAllMocks";

  [@bs.val] [@bs.scope "jest"]
  external restoreAllMocks: unit => unit = "restoreAllMocks";

  [@bs.val] [@bs.scope "jest"]
  external clearAllTimers: unit => unit = "clearAllTimers";

  [@bs.val] [@bs.scope "jest"]
  external getTimerCount: unit => unit = "getTimerCount";

  [@bs.val] [@bs.scope "jest"]
  external setSystemTime: int => unit = "setSystemTime";

  [@bs.val] [@bs.scope "jest"]
  external setSystemDate: Js.Date.t => unit = "setSystemTime";

  [@bs.val] [@bs.scope "jest"]
  external getRealSystemTime: unit => int = "getRealSystemTime";

  [@bs.val] [@bs.scope "jest"]
  external disableAutomock: unit => unit = "disableAutomock";

  [@bs.val] [@bs.scope "jest"]
  external enableAutomock: unit => unit = "enableAutomock";

  [@bs.val] [@bs.scope "jest"]
  external resetModules: unit => unit = "resetModules";

  [@bs.val] [@bs.scope "jest"]
  external isolateModules: ([@bs.uncurry] (unit => unit)) => unit =
    "isolateModules";

  [@bs.val] [@bs.scope "jest"]
  external runAllImmediates: unit => unit = "runAllImmediates";

  [@bs.val] [@bs.scope "jest"]
  external runAllTicks: unit => unit = "runAllTicks";

  [@bs.val] [@bs.scope "jest"]
  external runAllTimers: unit => unit = "runAllTimers";

  [@bs.val] [@bs.scope "jest"]
  external runOnlyPendingTimers: unit => unit = "runOnlyPendingTimers";

  [@bs.val] [@bs.scope "jest"]
  external advanceTimersByTime: int => unit = "advanceTimersByTime";

  [@bs.val] [@bs.scope "jest"]
  external advanceTimersToNextTimer: int => unit = "advanceTimersToNextTimer";

  [@bs.val] [@bs.scope "jest"] external setTimeout: int => unit = "setTimeout";

  [@bs.val] [@bs.scope "jest"]
  external useFakeTimers: unit => unit = "useFakeTimers";

  [@bs.val] [@bs.scope "jest"]
  external useRealTimers: unit => unit = "useRealTimers";

  [@bs.deriving abstract]
  type fakeTimerConfig = {
    [@bs.optional]
    advanceTimers: bool,
    [@bs.optional]
    doNotFake:
      array(
        [
          | `Date
          | `hrtime
          | `nextTick
          | `performance
          | `queueMicrotask
          | `requestAnimationFrame
          | `cancelAnimationFrame
          | `requestIdleCallback
          | `cancelIdleCallback
          | `setImmediate
          | `clearImmediate
          | `setInterval
          | `clearInterval
          | `setTimeout
          | `clearTimeout
        ],
      ),
    [@bs.optional]
    legacyFakeTimers: bool,
    [@bs.optional]
    now: [ | `Int(int) | `Date(Js.Date.t)],
    timerLimit: int,
  };

  [@bs.val] [@bs.scope "jest"]
  external useFakeTimersWithConfig: fakeTimerConfig => unit = "useFakeTimers";
};
