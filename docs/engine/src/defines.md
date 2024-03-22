# Defines Docs

## Module Gaurd with pragma once

## Type Definitions

typedef can be used to alias existing types in C. Here I'm using it to redefine types such as:  
unsigned char  
unsigned short  
unsigned int and so on..  
The same goes for signed, floats, and boolean values.

## Static Assertions

I still have some trouble understanding this concept, but I have this set up to detect which compiler is being used at compile time, then they will behave accordingly. For instance, I bound the _Static_assert keyword to a STATIC_ASSERT macro I created. If the compiler is not clang or gcc then the STATIC_ASSERT macro will use the static_assert predefined macro which expands to _Static_assert? Maybe this is done so it can be compatible with C++ compilers? This is a good resource that quickly explains defining macros and checking if the macros exists at compile time [4.2.3 Defined](https://gcc.gnu.org/onlinedocs/gcc-7.5.0/cpp/Defined.html) 

### Weird sizeof Caveat

I ran into warnings from the compiler about my static assertions not being correct when verifying u64 and i64 data types. I expected them to be 8 bytes long, but on my system (x64 Windows 10) they are 4 bytes long. I found this site that may be helpful in the future [C-integer types](https://michas.eu/blog/c_ints.php?lang=en)

## Platform Detection

Right now we're only detecting Windows systems

## Exporting and Importing dll Functions

If we want to import and export functions from our dll, we have to use ```__declspec(dllexport) / __declspec(dllimport)```
