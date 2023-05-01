open ReJest;
open Expect;

describe("Describe", () => {
  test("test basic", () => {
    expect(42)->toEqual(42)
  });

  // only (change the test to `only` to try it)
  test("test (only)", () => {
    expect(42)->toEqual(42)
  });

  Describe.skip("test (skipped)", () => {expect(42)->toEqual(42)});

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

  testAsyncTimeout("testAsyncTimeout", ~timeout=0, () => {
    Js.Promise.resolve(expect(42)->toEqual(42))
  });
});

describe("Test", () => {
  Test.it(."it", onDone => {
    expect(42)->toEqual(42);
    onDone();
  });

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
