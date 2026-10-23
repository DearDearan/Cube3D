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
  std/[random, strutils]

randomize()

var tests: seq[string] = @[]

for i in 0..50:
  tests.add(string ($ rand(10000000000)))
  tests[i] &= " " & $ rand(10000000000)

for i in tests:
  assert(csize_t(ft_fwlen(cstring i)) == csize_t(i.split()[0].len))
