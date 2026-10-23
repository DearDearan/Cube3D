discard """
  action: "compile"
  exitcode: 0

  output:'''
999
999
0
0
4294967295
4294967295
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

assert(printf("%u\n", 999) ==                          ft_printf("%u\n", 999))
assert(printf("%u\n", 0) ==                            ft_printf("%u\n", 0))
assert(printf("%u\n", 4294967295) ==                   ft_printf("%u\n", 4294967295))
assert(printf("I am a student at %u school\n", 42) ==  ft_printf("I am a student at %u school\n", 42))
