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
  ../libft

proc makeMutableCString(s: string): cstring =
  result = cast[cstring](alloc(s.len + 1))
  copyMem(result, s.cstring, s.len + 1)

var
  tests: array[4, array[2, cstring]] = [
    [makeMutableCString("I like nim."),       "Hello World"],
    [makeMutableCString("fghcjghjkhyj"),      "Hello World!"],
    [makeMutableCString("I"),                 "H"],
    [makeMutableCString("frbehjfgzeuihbui"),  "Hello World!"]
  ]


for i in tests:
  proc toHelloWorld(index: cuint, cptr: var cchar) {.closure.} =
    const hello: cstring = "Hello World!"
    if index < hello.len:
      cptr = hello[index]
    else:
      cptr = cchar(0)
  ft_striteri(i[0], toHelloWorld)
  assert(i[0] == i[1])
