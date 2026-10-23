discard """
  action: "compile"
  exitcode: 0

  output: '''
42 school
42 school


(null)
(null)
(null)
(null)
We are 42 school students
We are 42 school students
We are 42 school students and I love nim
We are 42 school students and I love nim
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
assert(printf("%s\n", "42 school") ==                                      ft_printf("%s\n", "42 school"))
assert(printf("%s\n", "") ==                                               ft_printf("%s\n", ""))
assert(printf("%s\n", nil) ==                                              ft_printf("%s\n", nil))
assert(printf("%s\n", "(null)") ==                                         ft_printf("%s\n", "(null)"))
assert(printf("We are %s students\n", "42 school") ==                      ft_printf("We are %s students\n", "42 school"))
assert(printf("We are %s students and I love %s\n", "42 school", "nim") == ft_printf("We are %s students and I love %s\n", "42 school", "nim"))
