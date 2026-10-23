##  **************************************************************************
##
##                                                         :::      ::::::::
##    file.h                                              ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀
##                                                     +:+ +:+         +:+
##    By: rboutelo <rboutelo@student.42angouleme.f>  +#+  +:+       +#+
##                                                 +#+#+#+#+#+   +#+
##    Created: 2026/02/17 22:09:10 by rboutelo          #+#    #+#
##    Updated: 2026/08/01 17:25:20 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟
##
##  **************************************************************************

when defined(AUTHORIZED_READV):
  discard
else:
  import
    syscalls

import
  types

when defined(TRUE_FILE):
  ##  Values used in musl
  when not defined(UNGET):
    const
      UNGET* = 8
  when not defined(BUFSIZE):
    const
      BUFSIZE* = 1024
  when not defined(EOF):
    const
      EOF* = -1
  when not defined(F_NORD):
    const
      F_NORD* = 4
  when not defined(F_NOWR):
    const
      F_NOWR* = 8
  when not defined(F_EOF):
    const
      F_EOF* = 16
  when not defined(F_ERR):
    const
      F_ERR* = 32
  when not defined(F_APP):
    const
      F_APP* = 128
const
  WE* = 1
  RE* = 0

##  ***************
##       OPEN
##  ***************

proc ft_ffopen*(filename: cstring; mode: cstring): t_ffile
proc ft_to_ffile*(fd: t_ffile): t_ffile
##  ***************
##       READ
##  ***************

proc ft_ffread*(file: t_ffile; buf: pointer; nbyte: intmax_t): intmax_t
proc get_next_line*(fd: cint): cstring
proc ft_ffreadall*(file: t_ffile; buf: ptr pointer): intmax_t
##  ***************
##       WRITE
##  ***************

proc ft_ffwrite*(file: t_ffile; buf: pointer; nbyte: intmax_t): intmax_t
##  ***************
##       CLOSE
##  ***************

proc ft_ffclose*(file: t_ffile)
proc ft_close_pipe*(fds: array[2, t_ffile])
##  ***************
##      CLEANUP
##  ***************

proc ft_clear_filelist*()