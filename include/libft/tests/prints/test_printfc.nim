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

assert(printf("%c\n", 0) ==   ft_printf("%c\n", 0))
assert(printf("%c\n", 10) ==  ft_printf("%c\n", 10))
assert(printf("%c\n", 20) ==  ft_printf("%c\n", 20))
assert(printf("%c\n", 30) ==  ft_printf("%c\n", 30))
assert(printf("%c\n", 40) ==  ft_printf("%c\n", 40))
assert(printf("%c\n", 50) ==  ft_printf("%c\n", 50))
assert(printf("%c\n", 60) ==  ft_printf("%c\n", 60))
assert(printf("%c\n", 70) ==  ft_printf("%c\n", 70))
assert(printf("%c\n", 80) ==  ft_printf("%c\n", 80))
assert(printf("%c\n", 90) ==  ft_printf("%c\n", 90))
assert(printf("%c\n", 100) == ft_printf("%c\n", 100))
