{.passL: "-lc".}
proc setbuf*(stream: File, buf: cstring) {.importc: "setbuf",  header: "<stdio.h>".}
proc printf*(format: cstring): cint {.varargs, importc: "printf",  header: "<stdio.h>".}
proc dprintf*(fd: cint; fmt: cstring): cint {.varargs, importc: "dprintf",  header: "<stdio.h>".}
proc memchr*(s: pointer; c: cint; n: csize_t): pointer {.importc, header:"<string.h>".}
proc bzero*(s: pointer; n: csize_t) {.importc, header:"<string.h>".}
proc memcmp*(s1: pointer; s2: pointer; n: csize_t): cint {.importc, header:"<string.h>".}
proc memcpy*(dest: pointer; src: pointer; n: csize_t): pointer {.importc, header:"<string.h>".}
proc memmove*(dest: pointer; src: pointer; n: csize_t): pointer {.importc, header:"<string.h>".}
proc memset*(s: pointer; c: cint; n: csize_t): pointer {.importc, header:"<string.h>".}
proc free*(p: pointer) {.importc, header:"<stdlib.h>".}
