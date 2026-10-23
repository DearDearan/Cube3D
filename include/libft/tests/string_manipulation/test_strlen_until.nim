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
  std/strutils

let tests: seq[array[3, cstring]] = @[
  ["Hello World!", "W", "6"],
  ["yfusqhdeisfh", "h", "5"],
  ["Should work?", "", "12"]
]

for i in tests:
  assert(ft_strlen_until(i[0], i[1][0]) == parseUInt($ i[2]))
