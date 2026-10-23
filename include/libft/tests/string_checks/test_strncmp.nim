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

proc makeRandomString(len: int): string =
  var tmp: seq[char] = @[]
  for i in 0..len:
    tmp.add(char rand(1..255))
  return cast[string](tmp)

var tests_true: seq[array[2, string]] = @[]
var tests_false: seq[array[2, string]] = @[]

for i in 0..50:
  var tmp: string = makeRandomString(rand(1..100))
  tests_true.add([
    tmp,
    tmp
  ])

for i in 0..50:
  tests_false.add([
    makeRandomString(rand(1..100)),
    makeRandomString(rand(101..200))
  ])

for i in tests_true:
  assert(ft_strncmp(cstring i[0], cstring i[1], cint i[0].len - 1) == 0)

for i in tests_false:
  assert(ft_strncmp(cstring i[0], cstring i[1], cint i[0].len - 1) != 0)
