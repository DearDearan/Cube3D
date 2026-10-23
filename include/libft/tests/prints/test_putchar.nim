discard """
  action: "compile"
  exitcode: 0

  output: "`"
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
    testFile: File = open("/tmp/chartests", fmWrite)
    testFileHandle: t_ffile = testFile.getFileHandle()

assert(ft_putchar_fd(cchar 0, testFileHandle)           == 1)
assert(ft_putchar_fd(cchar 9, testFileHandle)           == 1)
assert(ft_putchar_fd(cchar 10, testFileHandle)          == 1)
assert(ft_putchar_fd(cchar 64, testFileHandle)          == 1)
assert(ft_putchar_fd(cchar 32, testFileHandle)          == 1)
assert(ft_putchar_fd(cchar 123, testFileHandle)         == 1)
assert(ft_putchar_fd(cchar 96, testFileHandle)          == 1)
assert(ft_putchar_fd(cchar 96, stdout.getFileHandle())  == 1)
assert(ft_putchar_fd(cchar 96, -1)                      == -1)
