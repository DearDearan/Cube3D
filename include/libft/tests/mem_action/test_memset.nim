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
  a, b: array[256, uint8]

for t in 0..10:
  let c: uint8 = uint8 rand(255)
  discard ft_memset(addr a[0], int32 c, 256)
  discard memset(addr b[0], int32 c, 256)

  assert(a == b)
  ft_bzero(addr a[0], 256)
  ft_bzero(addr b[0], 256)
