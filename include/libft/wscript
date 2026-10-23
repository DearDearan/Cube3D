import subprocess


APPNAME = "libft"
VERSION = "1.1"
top = "."
out = "wbuild"


def configure(conf):
	conf.env.CC		= subprocess.run("readlink $(which cc)", shell=True, capture_output=True, text=True).stdout[:-1]
	conf.env.CFLAGS = [
		"-Wall",
		"-Wextra",
		"-Werror",
		"-fshort-enums",
		"-O2",
		"-march=native"
	]
	conf.load(conf.env.CC.split("/")[-1])


def build(bld):
	bld.env.append_value("INCLUDES_ROOT", [bld.path.find_dir('includes')])
	bld.recurse("src")
	lft = bld.shlib(
		features	= "c cshlib",
		target		= "ft",
		includes	= bld.env.INCLUDES_ROOT,
		use			= ["ftfle", "ftlst", "ftmem", "ftprt", "ftstr", "ftutl", "ftvfs"]
	)
	lft.post()
