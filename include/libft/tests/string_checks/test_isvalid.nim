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
  var tmp: string = newString(len)
  for i in 0..<len:
    tmp[i] = char rand(1..255)
  return tmp

proc nimStrIsValid(str: string): bool =
  for c in str:
    if ft_isascii(cint c) == false:
      return false
  return true

var
  tests: seq[string] = @[]

for i in 0..100:
  tests.add(makeRandomString(rand(1..25)))

for i in tests:
  assert(ft_str_is_valid(cstring i, ft_isascii) == nim_str_is_valid(i))
