open ReJest;
open Expect;

describe("Describe", () => {
  /*
    Describe.only("only", () => {
      test("only", () => {
        expect(42)->toEqual(42)
      })
    });

   Describe.skip("skip", () => {
     test("skip", () => {
       expect(42)->toEqual(42)
     })
   });
    */

  (Describe.each1([|"a", "b", "c"|]))(. "test", value => {
    test("each1", () => {
      expect(value)->toEqual(value)
    })
  });

  (Describe.each2([|(1, "1"), (2, "2"), (3, "3")|]))(. "each2", (a, b) => {
    test("each2", () => {
      expect(a |> string_of_int)->toEqual(b)
    })
  });

  (Describe.each3([|(1, "1", 1), (2, "2", 2), (3, "3", 3)|]))(.
     "each3", (a, _b, c) => {
    test("each3", () => {
      expect(a |> string_of_int |> int_of_string)->toEqual(c)
    })
  });

  (
    Describe.each4([|(1, "1", 1, "1"), (2, "2", 2, "2"), (3, "3", 3, "3")|])
  )(.
     "each4", (a, _b, _c, d) => {
    test("each4", () => {
      expect(a |> string_of_int |> int_of_string |> string_of_int)
      ->toEqual(d)
    })
  });

  (
    Describe.each5([|
      (1, "1", 1, "1", 1),
      (2, "2", 2, "2", 2),
      (3, "3", 3, "3", 3),
    |])
  )(.
     "each5", (a, _b, _c, _d, e) => {
    test("each5", () => {
      expect(
        a |> string_of_int |> int_of_string |> string_of_int |> int_of_string,
      )
      ->toEqual(e)
    })
  });
});

describe("Test globals", () => {
  test("test", () => {
    expect(42)->toEqual(42)
  });

  testPromise("testPromise", () => {
    Js.Promise.resolve(expect(42)->toEqual(42))
  });

  testPromiseTimeout("testPromiseTimeout", ~timeout=0, () => {
    Js.Promise.resolve(expect(42)->toEqual(42))
  });

  testAsync(."testAsync", onDone => {
    expect(42)->toEqual(42);
    onDone();
  });

  testAsyncTimeout(.
    "testAsyncTimeout",
    ~timeout=0,
    onDone => {
      expect(42)->toEqual(42);
      onDone();
    },
  );

  ();
});

describe("Test", () => {
  Test.it(."it", onDone => {
    expect(42)->toEqual(42);
    onDone();
  });

  Test.itPromise("itPromise", () => {
    Js.Promise.resolve(expect(42)->toEqual(42))
  });

  Test.itPromiseTimeout("itPromise", ~timeout=0, () => {
    Js.Promise.resolve(expect(42)->toEqual(42))
  });

  Test.itAsync(."itAsync", onDone => {
    expect(42)->toEqual(42);
    onDone();
  });

  Test.itAsyncTimeout(.
    "itAsync",
    ~timeout=0,
    onDone => {
      expect(42)->toEqual(42);
      onDone();
    },
  );

  // TODO:
  // only
  // onlyPromise
  // onlyPromiseTimeout
  // onlyAsync
  // onlyAsyncTimeout

  // TODO:
  // failing
  // failingPromise
  // failingPromiseTimeout
  // failingAsync
  // failingAsyncTimeout
  /*
   Test.failing(."failing", onDone => {
     expect(42)->toEqual(43);
     onDone();
   });

   Test.failingPromise("failingPromise", () => {
     Js.Promise.reject(Obj.magic("test error"))
   });
   */

  // TODO:
  // skip
  // skipPromise
  // skipPromiseTimeout
  // skipAsync
  // skipAsyncTimeout

  // TODO:
  // todo

  // TODO:
  // each1
  // each2
  // each3
  // each4
  // each5
  // eachPromise1
  // eachPromise2
  // eachPromise3
  // eachPromise4
  // eachPromise5
  // eachPromise1Timeout
  // eachPromise2Timeout
  // eachPromise3Timeout
  // eachPromise4Timeout
  // eachPromise5Timeout

  (Test.eachAsync1([|"a", "b"|]))(. "eachAsync1", (a, onDone) => {
    Js.Global.setTimeout(
      () => {
        expect(a)->toEqual(a);
        onDone();
      },
      0,
    )
    |> ignore
  });

  (Test.eachAsync2([|(1, "1"), (2, "2")|]))(. "eachAsync2", (a, b, onDone) => {
    Js.Global.setTimeout(
      () => {
        expect(a |> string_of_int)->toEqual(b);
        onDone();
      },
      0,
    )
    |> ignore
  });

  (Test.eachAsync3([|(1, "1", 1), (2, "2", 2)|]))(.
     "eachAsync3", (a, _b, c, onDone) => {
    Js.Global.setTimeout(
      () => {
        expect(a |> string_of_int |> int_of_string)->toEqual(c);
        onDone();
      },
      0,
    )
    |> ignore
  });

  (Test.eachAsync4([|(1, "1", 1, "1"), (2, "2", 2, "2")|]))(.
     "eachAsync4", (a, _b, _c, d, onDone) => {
    Js.Global.setTimeout(
      () => {
        expect(a |> string_of_int |> int_of_string |> string_of_int)
        ->toEqual(d);
        onDone();
      },
      0,
    )
    |> ignore
  });

  (Test.eachAsync5([|(1, "1", 1, "1", 1), (2, "2", 2, "2", 2)|]))(.
     "eachAsync5", (a, _b, _c, _d, e, onDone) => {
    Js.Global.setTimeout(
      () => {
        expect(
          a |> string_of_int |> int_of_string |> string_of_int |> int_of_string,
        )
        ->toEqual(e);
        onDone();
      },
      0,
    )
    |> ignore
  });

  (Test.eachAsync1Timeout([|"a", "b"|]))(.
    "eachAsync1Timeout",
    (a, onDone) => {
      expect(a)->toEqual(a);
      onDone();
    },
    0,
  );

  (Test.eachAsync2Timeout([|("1", 1)|]))(.
    "eachAsync2Timeout",
    (a, b, onDone) => {
      expect(a |> int_of_string)->toEqual(b);
      onDone();
    },
    0,
  );

  (Test.eachAsync3Timeout([|("1", 1, "1")|]))(.
    "eachAsync3Timeout",
    (a, _b, c, onDone) => {
      expect(a |> int_of_string |> string_of_int)->toEqual(c);
      onDone();
    },
    0,
  );

  (Test.eachAsync4Timeout([|("1", 1, "1", 1)|]))(.
    "eachAsync4Timeout",
    (a, _b, _c, d, onDone) => {
      expect(a |> int_of_string |> string_of_int |> int_of_string)
      ->toEqual(d);
      onDone();
    },
    0,
  );

  (Test.eachAsync5Timeout([|("1", 1, "1", 1, "1")|]))(.
    "eachAsync5Timeout",
    (a, _b, _c, _d, e, onDone) => {
      expect(
        a |> int_of_string |> string_of_int |> int_of_string |> string_of_int,
      )
      ->toEqual(e);
      onDone();
    },
    0,
  );
});

describe("Mock", () =>
  test("make", () => {
    let mock = Mock.make(str => str ++ "");

    mock->Mock.fn("Hello")->ignore;
    mock->Mock.fn("Green")->ignore;
    mock->Mock.fn("Last")->ignore;

    expect(mock)->toBeCalled;
    expect(mock)->toBeCalledTimes(3);

    expect(mock)->toHaveBeenNthCalledWith1(1, "Hello");
    expect(mock)->toHaveNthReturnedWith(1, "Hello");

    expect(mock)->toHaveBeenNthCalledWith1(2, "Green");
    expect(mock)->toHaveNthReturnedWith(2, "Green");

    expect(mock)->toHaveBeenLastCalledWith1("Last");
    expect(mock)->toHaveLastReturnedWith("Last");
  })
);
