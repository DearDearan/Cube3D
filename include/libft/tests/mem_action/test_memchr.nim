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
import ../[libft, glibc]

let s: array[6, uint8] = [0, 1, 2, 3, 4, 5]

assert(memchr(addr s[0], 0, 0)        == ft_memchr(addr s[0], 0, 0))
assert(memchr(addr s[0], 0, 1)        == ft_memchr(addr s[0], 0, 1))
assert(memchr(addr s[0], 2, 3)        == ft_memchr(addr s[0], 2, 3))
assert(memchr(addr s[0], 6, 6)        == ft_memchr(addr s[0], 6, 6))
assert(memchr(addr s[0], 2 + 256, 3)  == ft_memchr(addr s[0], 2 + 256, 3))
