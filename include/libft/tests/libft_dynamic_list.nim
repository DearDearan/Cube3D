##  **************************************************************************
##
##                                                         :::      ::::::::
##    dynamic_list.h                                      ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀
##                                                     +:+ +:+         +:+
##    By: rboutelo <rboutelo@student.42angouleme.f>  +#+  +:+       +#+
##                                                 +#+#+#+#+#+   +#+
##    Created: 2026/03/17 05:35:19 by rboutelo          #+#    #+#
##    Updated: 2026/07/29 16:37:13 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟
##
##  **************************************************************************

import
  libft

const
  ARR_DEFAULT_SIZE* = 129

type
  t_type* = enum
    N8, N16, N32, N64, PTR, FLOAT, DOUBLE, LDOUBLE
  t_header* {.bycopy.} = object
    count*: uintmax_t
    capacity*: uintmax_t
    `type`*: t_type



type
  u_value* {.bycopy, union.} = object
    c*: char
    u16*: uint16_t
    u32*: uint32_t
    u64*: uint64_t
    `ptr`*: pointer
    f*: cfloat
    d*: cdouble
    ld*: clongdouble

  t_elem* {.bycopy.} = object
    `type`*: t_type
    value*: u_value


proc ft_init_array*(elem: t_elem): pointer
proc ft_extend_array*(arr: ptr pointer): pointer
proc ft_arr_push*(arr: ptr pointer; elem: t_elem)
proc ft_arr_free*(arr: ptr pointer)