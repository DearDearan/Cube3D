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

var tests: seq[array[2, seq[char]]] = @[]

for i in 0..100:
  var tmp: seq[char] = @[]
  for j in 0..50:
    tmp.add(char rand(254) + 1)
  tests.add([
    tmp,
    newSeq[char](51)
  ])

for i in tests:
  assert(ft_strlcpy(cstring cast[string](i[1]), cstring cast[string](i[0]), 52) == 51)
  assert(i[1] == i[0])
