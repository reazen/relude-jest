open ReJest;
open Describe;
open Expect;

describe("Describe", () => {
  test("test basic", () => {
    expect(42)->toEqual(42)
  });

  // only
  test("test (only)", () => {
    expect(42)->toEqual(42)
  });

  skip("test (skipped)", () => {expect(42)->toEqual(42)});

  (each1([|"a", "b", "c"|]))(. "test", value => {
    expect(value)->toEqual(value)
  });

  (each2([|(1, "1"), (2, "2"), (3, "3")|]))(. "each2", (a, b) => {
    expect(a |> string_of_int)->toEqual(b)
  });
});

describe("Test", () => {
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

/*
 describe("Mock", () =>
   {}
 );
 */
