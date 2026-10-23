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
  ../[libft, glibc],
  std/random

randomize()

proc makeRandomString(len: int): string =
  var tmp: string = newString(len)
  for i in 0..<len:
    tmp[i] = char rand(32..126)
  return tmp

var
  tests: seq[string] = @[]

for i in 0..100:
  tests.add(makeRandomString(rand(1..50)))

for i in tests:
  let
    start: int = rand(0..(i.len div 2))
    endi: int = rand((i.len div 2)..i.len)
  var
    subs: string = i.substr(start, endi)
    tmp: cstring = ft_substr(cstring i, cuint(start), csize_t(endi - start + 1))
  assert(tmp == cstring subs)
  free(tmp)
