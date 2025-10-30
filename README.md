# E
Simple set of macros for primitive error handling.

# Table of contents

<!-- mdtoc-start -->
&bull; [E](#e)  
&bull; [Table of contents](#table-of-contents)  
&bull; [Introduction](#introduction)  
&bull; [Macros](#macros)  
&bull; [Coding Notes](#coding-notes)  
&bull; [License](#license)  
<!-- TOC created by '../mdtoc/mdtoc.pl README.md' (see https://github.com/fordsfords/mdtoc) -->
<!-- mdtoc-end -->


# Introduction

The file e.h defines a very simple set of error checking macros intended
primarily for Linux system/libc functions that set "errno".

The general intended use is to enclose the function call as a parameter
of the macro.
For example:
````
ENULL(my_ptr = malloc(sizeof(my_type)));
````
This will call malloc, assigning its return pointer to `my_ptr`.
If the result in NULL, it prints an error message to stderr and exits
with a status of 1.

As part of the error message, it lists the source file name and line
number, and also the text of the macro's input parameter, and a short
description of what `errno` is set to.

For example, given line 9 in file "x.c":
````
  ENULL(ptr = malloc(0x1fffffffffffffff));
````
produces this output:
````
Error x.c:9 - 'ptr = malloc(0x1fffffffffffffff)' is NULL: Cannot allocate memory
````


# Macros

* `EOK0` - Error if result is non-zero.
* `EOK1` - Error if result is not 1.
* `ENULL` - Error if result is NULL.
* `EM1` - Error if result is -1.


# Coding Notes

The source file `tst.c` is intentionally very simple.
It does not include any header files except `e.h`.
This is to ensure that the header files included by `e.h` are
sufficient for everything that `e.h` subsequently uses.
For example, `e.h` uses `perror()`.
Building tst.c ensures that `e.h` includes `errno.h`.


# License

I want there to be NO barriers to using this code, so I am releasing it to the public domain.  But "public domain" does not have an internationally agreed upon definition, so I use CC0:

This work is dedicated to the public domain under CC0 1.0 Universal:
http://creativecommons.org/publicdomain/zero/1.0/

To the extent possible under law, Steven Ford has waived all copyright
and related or neighboring rights to this work. In other words, you can 
use this code for any purpose without any restrictions.
This work is published from: United States.
Project home: https://github.com/fordsfords/E
