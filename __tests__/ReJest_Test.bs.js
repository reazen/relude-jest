// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Caml_format = require("bs-platform/lib/js/caml_format.js");

describe("Describe", (function () {
        test("test basic", (function () {
                return expect(42).toEqual(42);
              }));
        test("test (only)", (function () {
                return expect(42).toEqual(42);
              }));
        describe.skip("test (skipped)", (function () {
                return expect(42).toEqual(42);
              }));
        describe.each([
                "a",
                "b",
                "c"
              ])("test", (function (value) {
                return expect(value).toEqual(value);
              }));
        return describe.each([
                      [
                        1,
                        "1"
                      ],
                      [
                        2,
                        "2"
                      ],
                      [
                        3,
                        "3"
                      ]
                    ])("each2", (function (a, b) {
                      return expect(String(a)).toEqual(b);
                    }));
      }));

describe("Test", (function () {
        test.each([
                "a",
                "b"
              ])("eachAsync1", (function (a, onDone) {
                setTimeout((function (param) {
                        expect(a).toEqual(a);
                        return Curry._1(onDone, undefined);
                      }), 0);
                
              }));
        test.each([
                [
                  1,
                  "1"
                ],
                [
                  2,
                  "2"
                ]
              ])("eachAsync2", (function (a, b, onDone) {
                setTimeout((function (param) {
                        expect(String(a)).toEqual(b);
                        return Curry._1(onDone, undefined);
                      }), 0);
                
              }));
        test.each([
                [
                  1,
                  "1",
                  1
                ],
                [
                  2,
                  "2",
                  2
                ]
              ])("eachAsync3", (function (a, _b, c, onDone) {
                setTimeout((function (param) {
                        expect(Caml_format.caml_int_of_string(String(a))).toEqual(c);
                        return Curry._1(onDone, undefined);
                      }), 0);
                
              }));
        test.each([
                [
                  1,
                  "1",
                  1,
                  "1"
                ],
                [
                  2,
                  "2",
                  2,
                  "2"
                ]
              ])("eachAsync4", (function (a, _b, _c, d, onDone) {
                setTimeout((function (param) {
                        expect(String(Caml_format.caml_int_of_string(String(a)))).toEqual(d);
                        return Curry._1(onDone, undefined);
                      }), 0);
                
              }));
        return test.each([
                      [
                        1,
                        "1",
                        1,
                        "1",
                        1
                      ],
                      [
                        2,
                        "2",
                        2,
                        "2",
                        2
                      ]
                    ])("eachAsync5", (function (a, _b, _c, _d, e, onDone) {
                      setTimeout((function (param) {
                              expect(Caml_format.caml_int_of_string(String(Caml_format.caml_int_of_string(String(a))))).toEqual(e);
                              return Curry._1(onDone, undefined);
                            }), 0);
                      
                    }));
      }));

/*  Not a pure module */