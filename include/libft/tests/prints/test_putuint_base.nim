discard """
  action: "compile"
  exitcode: 0

  output: "10011110"
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
  errorThingy: bool

errorThingy = false
assert(ft_putuint_base_fd(132, "0123456789", testFileHandle, addr errorThingy)               == 3)
assert(errorThingy == false)
assert(ft_putuint_base_fd(2147483647, "0123456789ABCDEF", testFileHandle, addr errorThingy)  == 8)
assert(errorThingy == false)
assert(ft_putuint_base_fd(0, "01", testFileHandle, addr errorThingy)                         == 1)
assert(errorThingy == false)
assert(ft_putuint_base_fd(158, "01", stdout.getFileHandle(), addr errorThingy)               == 8)
assert(errorThingy == false)
assert(ft_putuint_base_fd(15, "1564489", -1, addr errorThingy)                               == -2)
assert(errorThingy == true)
