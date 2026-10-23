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
import ../[libft, glibc]

let
  a: int32 = 0
  b: char = 'A'
  c: cstring = "hilmi"
  d: pointer = alloc sizeof(int32)
  e: ptr char = nil

assert(printf("%p\n", addr(a)) == ft_printf("%p\n", addr(a)))
assert(printf("%p\n", addr(b)) == ft_printf("%p\n", addr(b)))
assert(printf("%p\n", c) ==       ft_printf("%p\n", c))
assert(printf("%p\n", d) ==       ft_printf("%p\n", d))
assert(printf("%p\n", e) ==       ft_printf("%p\n", e))
