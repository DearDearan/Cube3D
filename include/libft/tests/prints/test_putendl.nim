discard """
  action: "compile"
  exitcode: 0

  output:'''
Hello World
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
import
    ../[libft, glibc]

var
    testFile: File = open("/tmp/strendltests", fmWrite)
    testFileHandle: t_ffile = testFile.getFileHandle()

assert(ft_putendl_fd("Hello World", testFileHandle)         == 12)
assert(ft_putendl_fd(nil, testFileHandle)                   == 0)
assert(ft_putendl_fd("Hello World", stdout.getFileHandle()) == 12)
assert(ft_putendl_fd("Hello World", -1)                     == -2)
