discard """
  action: "compile"
  exitcode: 0

  # On Linux 64-bit machines, whether to use Valgrind to check for bad memory
  # accesses or memory leaks. On other architectures, the test will be run
  # as-is, without Valgrind.
  # Options:
  #   true: run the test with Valgrind
  #   false: run the without Valgrind
  #   "leaks": run the test with Valgrind, but do not check for memory leaks
  valgrind: false

  # Targets to run the test into (c, cpp, objc, js). Defaults to c.
  targets: "c"

  # Conditions that will skip this test. Use of multiple "disabled" clauses
  # is permitted.
  disabled: "win"
"""

import
  ../libft,
  std/random

randomize()

var
  tests_true: array[5, array[2, string]] = [
    ["Hello World", "Hell"],
    ["Hello World", "o Wor"],
    ["Hello World", "Hello World"],
    ["Hello World", "Worl"],
    ["Hello\nWorld", "\n"]
  ]
  tests_false: array[5, array[2, string]] = [
    ["Hell", "Hello"],
    ["Hello Worl", "World"],
    ["Hello World", "gesh"],
    ["Hello World", "tHello"],
    ["Hello World", "Hell© World"]
  ]

for i in tests_true:
  assert(ft_strnstr(cstring i[0], cstring i[1], csize_t i[0].len) != cstring nil)

for i in tests_false:
  assert(ft_strnstr(cstring i[0], cstring i[1], csize_t i[0].len) == cstring nil)
