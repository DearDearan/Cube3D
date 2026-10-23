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
  tests_true: seq[char] = @[]
  tests_false: seq[char] = @[]

for i in 0..100:
  tests_true.add(char rand(0..127))

for i in 0..100:
  tests_false.add(char rand(128..255))

for i in tests_true:
  assert(ft_isascii(cint i) == (uint8(i) < 128))

for i in tests_false:
  assert(ft_isascii(cint i) == (uint8(i) < 128))
