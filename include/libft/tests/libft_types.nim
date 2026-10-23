##  @doc t_validator
##  @kind type
##  @desc Enum to index into the default validator functions in g_validators.
##  @field DIGIT: uint8_t, Only digits.
##  @field ALPHA: uint8_t, Only alphabetic characters.
##  @field SPACE: uint8_t, Only space characters.
##  @field PRINT: uint8_t, Only printable characters.
##  @field ASCII: uint8_t, Only ascii characters.
##  @field ALNUM: uint8_t, Only alphanumeric characters.

type
  t_validator* = enum
    DIGIT, ALPHA, SPACE, PRINT, ASCII, ALNUM


##  @doc t_validator_fn
##  @kind type
##  @desc Type that describes a validating function for str_is_valid.

type
  t_validator_fn* = proc (val: cint): bool

##  @doc t_ptr
##  @kind type
##  @desc Type that allows for clean pointer to uintptr_t casts. Don't ask.
##  @field ptr: void *, The pointer casted from/to.
##  @field addr: uintptr_t, The uintptr_t representation of the pointer.

type
  t_ptr* {.bycopy, union.} = object
    `ptr`*: pointer
    `addr`*: csize_t


##  @doc t_list
##  @kind type
##  @desc Linked list type.
##  @field content: void *, The content of the node.
##  @field next: t_list *, The next node.

type
  t_list* {.bycopy.} = object
    content*: pointer
    next*: ptr t_list


##  @doc t_ffile
##  @kind type
##  @desc Fake FILE type, I was too lazy to finish my implemenation so this
##  @desc is just a cheap alias for int. oh and it avoids mixing int
##  @desc and int32_t I guess.

type
  t_ffile* = cint

##  @doc t_ffile
##  @kind type
##  @desc Yup, a whole trucking iovec, don't ask.
##  @field iov_base: void *, `man iovec`, stop your suffering.
##  @field iov_len: uintmax_t, Have you read the doc for iov_base?

type
  t_iovec* {.bycopy.} = object
    iov_base*: pointer
    iov_len*: csize_t

