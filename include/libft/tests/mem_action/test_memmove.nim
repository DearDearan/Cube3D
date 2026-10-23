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
  valgrind: true

  # Targets to run the test into (c, cpp, objc, js). Defaults to c.
  targets: "c"

  # Conditions that will skip this test. Use of multiple "disabled" clauses
  # is permitted.
  disabled: "win"
"""

import
  std/random,
  ../[libft, glibc]

var
  a, b: array[384, uint8]

for t in 0..10:
  for i in 0..255:
    a[i] = uint8 rand(255)
    b[i] = a[i]

  discard ft_memmove(addr a[128], addr a[0], 256)
  discard memmove(addr b[128], addr b[0], 256)

  assert(a == b)
