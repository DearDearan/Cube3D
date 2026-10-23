discard """
  action: "compile"
  exitcode: 0

  output:'''
999
999
8BA
8BA
0
0
FFFFFFFF
FFFFFFFF
I am a student at 42 school
I am a student at 42 school
'''

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

setbuf(stdout, nil)

assert(printf("%X\n", 0x999) ==                         ft_printf("%X\n", 0x999))
assert(printf("%X\n", 0x8BA) ==                         ft_printf("%X\n", 0x8BA))
assert(printf("%X\n", 0x0) ==                           ft_printf("%X\n", 0x0))
assert(printf("%X\n", 0xFFFFFFFF) ==                    ft_printf("%X\n", 0xFFFFFFFF))
assert(printf("I am a student at %X school\n", 0x42) == ft_printf("I am a student at %X school\n", 0x42))
