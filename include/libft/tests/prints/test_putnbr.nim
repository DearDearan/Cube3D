discard """
  action: "compile"
  exitcode: 0

  output: "158"
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
    ../[libft, glibc]

var
    testFile: File = open("/tmp/nbrtests", fmWrite)
    testFileHandle: t_ffile = testFile.getFileHandle()

assert(ft_putnbr_fd(132, testFileHandle)          == 3)
assert(ft_putnbr_fd(2147483647, testFileHandle)   == 10)
assert(ft_putnbr_fd(-2147483648, testFileHandle)  == 11)
assert(ft_putnbr_fd(0, testFileHandle)            == 1)
assert(ft_putnbr_fd(158, stdout.getFileHandle())  == 3)
assert(ft_putnbr_fd(-15, -1)                      == -3)
