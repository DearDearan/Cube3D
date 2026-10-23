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
  tests: seq[char] = @[]

for i in 0..200:
  tests.add(char rand(0..255))

for i in tests:
  assert(ft_isspace(cint i) == (9 <= uint8(i) and uint8(i) <= 13 or uint8(i) == 32))
