open ReJest;
open Expect;

describe("Describe", () => {
  /* Skip by default (wrapping with skip doesn't work)
     Describe.only("only", () => {
       test("only", () => {
         expect(42)->toEqual(42)
       })
     });
     */

  Describe.skip("skip", () => {
    test("skip", () => {
      expect(42)->toEqual(42)
    })
  });

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

  testPromiseTimeout(
    "testPromiseTimeout",
    () => {Js.Promise.resolve(expect(42)->toEqual(42))},
    ~timeout=0,
  );

  testAsync("testAsync", onDone => {
    expect(42)->toEqual(42);
    onDone();
  });

  testAsyncTimeout(
    "testAsyncTimeout",
    onDone => {
      expect(42)->toEqual(42);
      onDone();
    },
    ~timeout=0,
  );
});

describe("Test", () => {
  Test.it("it", () => {
    expect(42)->toEqual(42)
  });

  Test.itPromise("itPromise", () => {
    Js.Promise.resolve(expect(42)->toEqual(42))
  });

  Test.itPromiseTimeout("itPromise", ~timeout=0, () => {
    Js.Promise.resolve(expect(42)->toEqual(42))
  });

  Test.itAsync("itAsync", onDone => {
    expect(42)->toEqual(42);
    onDone();
  });

  Test.itAsyncTimeout(
    "itAsync",
    onDone => {
      expect(42)->toEqual(42);
      onDone();
    },
    ~timeout=0,
  );

  /* Skip by default (wrapping `only` with `skip` doesn't work)
     Test.only("only", () => {expect(42)->toEqual(42)});

     Test.onlyPromise("onlyPromise", () => {
       Js.Promise.resolve(expect(42)->toEqual(42))
     });

     Test.onlyPromiseTimeout(
       "onlyPromise",
       () => {Js.Promise.resolve(expect(42)->toEqual(42))},
       ~timeout=0,
     );

     Test.onlyAsync("onlyAsync", onDone => {
       expect(42)->toEqual(42);
       onDone();
     });

     Test.onlyAsyncTimeout(
       "onlyAsync",
       onDone => {
         expect(42)->toEqual(42);
         onDone();
       },
       ~timeout=0,
     );
     */

  Test.todo("failing");
  Test.todo("failingPromise");
  Test.todo("failingPromiseTimeout");
  Test.todo("failingAsync");
  Test.todo("failingAsyncTimeout");

  Test.skip("skip", () => {expect(42)->toEqual(42)});

  Test.skipPromise("skipPromise", () => {
    Js.Promise.resolve(expect(42)->toEqual(42))
  });

  Test.skipPromiseTimeout("skipPromise", ~timeout=0, () => {
    Js.Promise.resolve(expect(42)->toEqual(42))
  });

  Test.skipAsync("skipAsync", onDone => {
    expect(42)->toEqual(42);
    onDone();
  });

  Test.skipAsyncTimeout(
    "skipAsyncTimeout",
    onDone => {
      expect(42)->toEqual(42);
      onDone();
    },
    ~timeout=0,
  );

  Test.todo("todo");

  (Test.each1([|"a"|]))(. "each1", a => {expect(a)->toEqual(a)});

  (Test.each2([|("1", 1)|]))(. "each2", (a, b) => {
    expect(a |> int_of_string)->toEqual(b)
  });

  (Test.each3([|("1", 1, "1")|]))(. "each3", (a, _b, c) => {
    expect(a |> int_of_string |> string_of_int)->toEqual(c)
  });

  (Test.each4([|("1", 1, "1", 1)|]))(. "each4", (a, _b, _c, d) => {
    expect(a |> int_of_string |> string_of_int |> int_of_string)->toEqual(d)
  });

  (Test.each5([|("1", 1, "1", 1, "1")|]))(. "each4", (a, _b, _c, _d, e) => {
    expect(
      a |> int_of_string |> string_of_int |> int_of_string |> string_of_int,
    )
    ->toEqual(e)
  });

  (Test.eachPromise1([|"1"|]))(. "eachPromise1", a =>
    Js.Promise.resolve(expect(a)->toEqual(a))
  );

  (Test.eachPromise2([|("1", 1)|]))(. "eachPromise2", (a, b) =>
    Js.Promise.resolve(expect(a |> int_of_string)->toEqual(b))
  );

  (Test.eachPromise3([|("1", 1, "1")|]))(. "eachPromise3", (a, _b, c) =>
    Js.Promise.resolve(
      expect(a |> int_of_string |> string_of_int)->toEqual(c),
    )
  );

  (Test.eachPromise4([|("1", 1, "1", 1)|]))(.
     "eachPromise4", (a, _b, _c, d) =>
    Js.Promise.resolve(
      expect(a |> int_of_string |> string_of_int |> int_of_string)
      ->toEqual(d),
    )
  );

  (Test.eachPromise5([|("1", 1, "1", 1, "1")|]))(.
     "eachPromise5", (a, _b, _c, _d, e) =>
    Js.Promise.resolve(
      expect(
        a |> int_of_string |> string_of_int |> int_of_string |> string_of_int,
      )
      ->toEqual(e),
    )
  );

  (Test.eachPromise1Timeout([|"1"|]))(.
    "eachPromise1Timeout",
    a => Js.Promise.resolve(expect(a)->toEqual(a)),
    ~timeout=0,
  );

  (Test.eachPromise2Timeout([|("1", 1)|]))(.
    "eachPromise2Timeout",
    (a, b) => Js.Promise.resolve(expect(a |> int_of_string)->toEqual(b)),
    ~timeout=0,
  );

  (Test.eachPromise3Timeout([|("1", 1, "1")|]))(.
    "eachPromise3Timeout",
    (a, _b, c) =>
      Js.Promise.resolve(
        expect(a |> int_of_string |> string_of_int)->toEqual(c),
      ),
    ~timeout=0,
  );

  (Test.eachPromise4Timeout([|("1", 1, "1", 1)|]))(.
    "eachPromise4Timeout",
    (a, _b, _c, d) =>
      Js.Promise.resolve(
        expect(a |> int_of_string |> string_of_int |> int_of_string)
        ->toEqual(d),
      ),
    ~timeout=0,
  );

  (Test.eachPromise5Timeout([|("1", 1, "1", 1, "1")|]))(.
    "eachPromise5Timeout",
    (a, _b, _c, _d, e) =>
      Js.Promise.resolve(
        expect(
          a |> int_of_string |> string_of_int |> int_of_string |> string_of_int,
        )
        ->toEqual(e),
      ),
    ~timeout=0,
  );

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
    ~timeout=0,
  );

  (Test.eachAsync2Timeout([|("1", 1)|]))(.
    "eachAsync2Timeout",
    (a, b, onDone) => {
      expect(a |> int_of_string)->toEqual(b);
      onDone();
    },
    ~timeout=0,
  );

  (Test.eachAsync3Timeout([|("1", 1, "1")|]))(.
    "eachAsync3Timeout",
    (a, _b, c, onDone) => {
      expect(a |> int_of_string |> string_of_int)->toEqual(c);
      onDone();
    },
    ~timeout=0,
  );

  (Test.eachAsync4Timeout([|("1", 1, "1", 1)|]))(.
    "eachAsync4Timeout",
    (a, _b, _c, d, onDone) => {
      expect(a |> int_of_string |> string_of_int |> int_of_string)
      ->toEqual(d);
      onDone();
    },
    ~timeout=0,
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
    ~timeout=0,
  );
});

describe("beforeEach", () => {
  let count = ref(0);

  beforeEach(() => {count := count^ + 1});

  test("beforeEach 1", () => {
    expect(count^)->toEqual(1)
  });

  test("beforeEach 2", () => {
    expect(count^)->toEqual(2)
  });
});

describe("beforeEachPromise", () => {
  let count = ref(0);

  beforeEachPromise(() => {
    count := count^ + 1;
    Js.Promise.resolve();
  });

  test("beforeEachPromise 1", () => {
    expect(count^)->toEqual(1)
  });

  test("beforeEachPromise 2", () => {
    expect(count^)->toEqual(2)
  });
});

describe("beforeEachPromiseTimeout", () => {
  let count = ref(0);

  beforeEachPromiseTimeout(
    () => {
      count := count^ + 1;
      Js.Promise.resolve();
    },
    ~timeout=0,
  );

  test("beforeEachPromiseTimeout 1", () => {
    expect(count^)->toEqual(1)
  });

  test("beforeEachPromiseTimeout 2", () => {
    expect(count^)->toEqual(2)
  });
});

describe("beforeEachAsync", () => {
  let count = ref(0);

  beforeEachAsync(onDone => {
    count := count^ + 1;
    onDone();
  });

  test("beforeEachAsync 1", () => {
    expect(count^)->toEqual(1)
  });

  test("beforeEachAsync 2", () => {
    expect(count^)->toEqual(2)
  });
});

describe("beforeEachAsyncTimeout", () => {
  let count = ref(0);

  beforeEachAsyncTimeout(
    onDone => {
      count := count^ + 1;
      onDone();
    },
    ~timeout=0,
  );

  test("beforeEachAsyncTimeout 1", () => {
    expect(count^)->toEqual(1)
  });

  test("beforeEachAsyncTimeout 2", () => {
    expect(count^)->toEqual(2)
  });
});

describe("beforeAll", () => {
  let count = ref(0);

  beforeAll(() => {count := count^ + 1});

  test("beforeAll 1", () => {
    expect(count^)->toEqual(1)
  });

  test("beforeAll 2", () => {
    expect(count^)->toEqual(1)
  });
});

describe("beforeAllPromise", () => {
  let count = ref(0);

  beforeAllPromise(() => {
    count := count^ + 1;
    Js.Promise.resolve();
  });

  test("beforeAllPromise 1", () => {
    expect(count^)->toEqual(1)
  });

  test("beforeAllPromise 2", () => {
    expect(count^)->toEqual(1)
  });
});

describe("beforeAllPromiseTimeout", () => {
  let count = ref(0);

  beforeAllPromiseTimeout(
    () => {
      count := count^ + 1;
      Js.Promise.resolve();
    },
    ~timeout=0,
  );

  test("beforeAllPromiseTimeout 1", () => {
    expect(count^)->toEqual(1)
  });

  test("beforeAllPromiseTimeout 2", () => {
    expect(count^)->toEqual(1)
  });
});

describe("beforeAllAsync", () => {
  let count = ref(0);

  beforeAllAsync(onDone => {
    count := count^ + 1;
    onDone();
  });

  test("beforeAllAsync 1", () => {
    expect(count^)->toEqual(1)
  });

  test("beforeAllAsync 2", () => {
    expect(count^)->toEqual(1)
  });
});

describe("beforeAllAsyncTimeout", () => {
  let count = ref(0);

  beforeAllAsyncTimeout(
    onDone => {
      count := count^ + 1;
      onDone();
    },
    ~timeout=0,
  );

  test("beforeAllAsyncTimeout 1", () => {
    expect(count^)->toEqual(1)
  });

  test("beforeAllAsyncTimeout 2", () => {
    expect(count^)->toEqual(1)
  });
});

describe("afterEach", () => {
  let count = ref(0);

  afterEach(() => {count := count^ + 1});

  test("afterEach 1", () => {
    expect(count^)->toEqual(0)
  });

  test("afterEach 2", () => {
    expect(count^)->toEqual(1)
  });
});

describe("afterEachPromise", () => {
  let count = ref(0);

  afterEachPromise(() => {
    count := count^ + 1;
    Js.Promise.resolve();
  });

  test("afterEachPromise 1", () => {
    expect(count^)->toEqual(0)
  });

  test("afterEachPromise 2", () => {
    expect(count^)->toEqual(1)
  });
});

describe("afterEachPromiseTimeout", () => {
  let count = ref(0);

  afterEachPromiseTimeout(
    () => {
      count := count^ + 1;
      Js.Promise.resolve();
    },
    ~timeout=0,
  );

  test("afterEachPromiseTimeout 1", () => {
    expect(count^)->toEqual(0)
  });

  test("afterEachPromiseTimeout 2", () => {
    expect(count^)->toEqual(1)
  });
});

describe("afterEachAsync", () => {
  let count = ref(0);

  afterEachAsync(onDone => {
    count := count^ + 1;
    onDone();
  });

  test("afterEachAsync 1", () => {
    expect(count^)->toEqual(0)
  });

  test("afterEachAsync 2", () => {
    expect(count^)->toEqual(1)
  });
});

describe("afterEachAsyncTimeout", () => {
  let count = ref(0);

  afterEachAsyncTimeout(
    onDone => {
      count := count^ + 1;
      onDone();
    },
    ~timeout=0,
  );

  test("afterEachAsyncTimeout 1", () => {
    expect(count^)->toEqual(0)
  });

  test("afterEachAsyncTimeout 2", () => {
    expect(count^)->toEqual(1)
  });
});

describe("afterAll", () => {
  let count = ref(0);

  afterAll(() => {count := count^ + 1});

  test("afterAll 1", () => {
    expect(count^)->toEqual(0)
  });

  test("afterAll 2", () => {
    expect(count^)->toEqual(0)
  });
});

describe("afterAllPromise", () => {
  let count = ref(0);

  afterAllPromise(() => {
    count := count^ + 1;
    Js.Promise.resolve();
  });

  test("afterAllPromise 1", () => {
    expect(count^)->toEqual(0)
  });

  test("afterAllPromise 2", () => {
    expect(count^)->toEqual(0)
  });
});

describe("afterAllPromiseTimeout", () => {
  let count = ref(0);

  afterAllPromiseTimeout(
    () => {
      count := count^ + 1;
      Js.Promise.resolve();
    },
    ~timeout=0,
  );

  test("afterAllPromiseTimeout 1", () => {
    expect(count^)->toEqual(0)
  });

  test("afterAllPromiseTimeout 2", () => {
    expect(count^)->toEqual(0)
  });
});

describe("afterAllAsync", () => {
  let count = ref(0);

  afterAllAsync(onDone => {
    count := count^ + 1;
    onDone();
  });

  test("afterAllAsync 1", () => {
    expect(count^)->toEqual(0)
  });

  test("afterAllAsync 2", () => {
    expect(count^)->toEqual(0)
  });
});

describe("afterAllAsyncTimeout", () => {
  let count = ref(0);

  afterAllAsyncTimeout(
    onDone => {
      count := count^ + 1;
      onDone();
    },
    ~timeout=0,
  );

  test("afterAllAsyncTimeout 1", () => {
    expect(count^)->toEqual(0)
  });

  test("afterAllAsyncTimeout 2", () => {
    expect(count^)->toEqual(0)
  });
});

describe("Mock", () => {
  Test.todo("fn");

  Test.todo("empty");

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
  });

  Test.todo("make2");
  Test.todo("make3");
  Test.todo("spyOn");
  Test.todo("spyOnGetter");
  Test.todo("spyOnSetter");
  Test.todo("return_node");
  Test.todo("calls");
  Test.todo("callsWrapArray");
  Test.todo("_results");
  Test.todo("results_type");
  Test.todo("results");
  Test.todo("instances");
  Test.todo("lastCall");
  Test.todo("lastCallWrapArray");
  Test.todo("getMockName");
  Test.todo("setMockname");
  Test.todo("mockClear");
  Test.todo("mockReset");
  Test.todo("mockRestore");
  Test.todo("mockImplementation");
  Test.todo("mockImplementationOnce");
  Test.todo("mockReturnValue");
  Test.todo("mockReturnValueOnce");
  Test.todo("mockResolvedValue");
  Test.todo("mockResolvedValueOnce");
  Test.todo("mockRejectedValue");
  Test.todo("mockRejectedValueOnce");
});

describe("Expect", () => {
  Test.todo("not");
  Test.todo("unsafe");
  Test.todo("resolves");
  Test.todo("rejects");
  Test.todo("toBe");
  Test.todo("toEqual");
  Test.todo("toStrictEqual");
  Test.todo("toHaveBeenLastCalledWith");
  Test.todo("toHaveBeenLastCalledWith1");
  Test.todo("toHaveBeenLastCalledWith2");
  Test.todo("toHaveBeenLastCalledWith3");
  Test.todo("toHaveBeenLastCalledWith4");
  Test.todo("toHaveBeenLastCalledWith5");
  Test.todo("toHaveLastReturnedWith");
  Test.todo("toHaveBeenNthCalledWith");
  Test.todo("toHaveBeenNthCalledWith1");
  Test.todo("toHaveBeenNthCalledWith2");
  Test.todo("toHaveBeenNthCalledWith3");
  Test.todo("toHaveBeenNthCalledWith4");
  Test.todo("toHaveBeenNthCalledWith5");
  Test.todo("toHaveNthReturnedWith");
  Test.todo("toBeCalled");
  Test.todo("toBeCalledTimes");
  Test.todo("toHaveBeenCalledWith");
  Test.todo("toHaveBeenCalledWith1");
  Test.todo("toHaveBeenCalledWith2");
  Test.todo("toHaveBeenCalledWith3");
  Test.todo("toHaveBeenCalledWith4");
  Test.todo("toHaveBeenCalledWith5");
  Test.todo("toHaveReturned");
  Test.todo("toHaveReturnedWith");
  Test.todo("toBeCloseTo");
  Test.todo("toBeCloseToWithDigit");
  Test.todo("toBeDefined");
  Test.todo("toBeFalsy");
  Test.todo("toBeTruthy");
  Test.todo("toBeGreaterThan");
  Test.todo("toBeGreaterThanOrEqual");
  Test.todo("toBeGreaterThanFloat");
  Test.todo("toBeGreaterThanOrEqualFloat");
  Test.todo("toBeLessThan");
  Test.todo("toBeLessThanOrEqual");
  Test.todo("toBeLessThanFloat");
  Test.todo("toBeLessThanOrEqualFloat");
  Test.todo("toBeNull");
  Test.todo("toBeUndefined");
  Test.todo("toBeNaN");
  Test.todo("toBeNaNFloat");
  Test.todo("toContain");
  Test.todo("toContainEqual");
  Test.todo("toHaveLength");
  Test.todo("toHaveProperty");
  Test.todo("toHavePropertyValue");
  Test.todo("toMatch");
  Test.todo("toMatchString");
  Test.todo("toMatchObject");
  Test.todo("toMatchSnapshot");
  Test.todo("toMatchInlineSnapshot");
  Test.todo("toThrow");
  Test.todo("toThrowString");
  Test.todo("toThrowRegexp");
  Test.todo("toThrowError");
});

describe("ExpectStatic", () => {
  Test.todo("anything");
  Test.todo("anyInt");
  Test.todo("anyFloat");
  Test.todo("anyString");
  Test.todo("any");
  Test.todo("arrayContaining");
  Test.todo("objectContaining");
  Test.todo("stringContaining");
  Test.todo("stringMatching");
  Test.todo("notArrayContaining");
  Test.todo("notObjectContaining");
  Test.todo("notStringContaining");
  Test.todo("notStringMatching");
  Test.todo("closeTo");
  Test.todo("closeToWithDigit");
  Test.todo("assertions");
  Test.todo("hasAssertions");
});

describe("JestJs", () => {
  Test.todo("require");
  Test.todo("requireActual");
  Test.todo("requireMock");
  Test.todo("mock");
  Test.todo("mockFactoryUnsafe");
  Test.todo("mockFactory");
  Test.todo("mockFactoryVirtual");
  Test.todo("dontMock");
  Test.todo("doMock");
  Test.todo("doMockFactoryUnsafe");
  Test.todo("doMockFactory");
  Test.todo("doMockFactoryVirtual");
  Test.todo("autoMockOff");
  Test.todo("autoMockOn");
  Test.todo("clearAllMocks");
  Test.todo("resetAllMocks");
  Test.todo("restoreAllMocks");
  Test.todo("clearAllTimers");
  Test.todo("getTimerCount");
  Test.todo("setSystemTime");
  Test.todo("setSystemDate");
  Test.todo("getRealSystemTime");
  Test.todo("disableAutomock");
  Test.todo("enableAutomock");
  Test.todo("resetModules");
  Test.todo("isolateModules");
  Test.todo("runAllImmediates");
  Test.todo("runAllTicks");
  Test.todo("runAllTimers");
  Test.todo("runOnlyPendingTimers");
  Test.todo("advanceTimersByTime");
  Test.todo("advanceTimersToNextTimer");
  Test.todo("setTimeout");
  Test.todo("useFakeTimers");
  Test.todo("useRealTimers");
  Test.todo("useFakeTimersWithConfig");
});
