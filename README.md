# E
Simple set of macros for primitive error handling.

# Table of contents

<!-- mdtoc-start -->
&bull; [E](#e)  
&bull; [Table of contents](#table-of-contents)  
&bull; [Introduction](#introduction)  
&bull; [Macros](#macros)  
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


# License

I want there to be NO barriers to using this code, so I am releasing it to the public domain.  But "public domain" does not have an internationally agreed upon definition, so I use CC0:

Copyright 2021-2022 Steven Ford http://geeky-boy.com and licensed
"public domain" style under
[CC0](http://creativecommons.org/publicdomain/zero/1.0/):
![CC0](https://licensebuttons.net/p/zero/1.0/88x31.png "CC0")

To the extent possible under law, the contributors to this project have
waived all copyright and related or neighboring rights to this work.
In other words, you can use this code for any purpose without any
restrictions.  This work is published from: United States.  The project home
is https://github.com/fordsfords/E

To contact me, Steve Ford, project owner, you can find my email address
at http://geeky-boy.com.  Can't see it?  Keep looking.
