#pragma once // prevents the header file from being included multiple times (header Guard)

// This allows us to us short names instead of saying unsigned *

// Unsigned int types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed int types
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// Floating point types
typedef float f32;
typedef double f64;

// Boolean types
typedef int b32;
typedef char b8;

// Define static assertions
#if defined(__clang__) || defined(__GNUC__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Ensure all types are of the correct size based on the platform
STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte");
STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes");
STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes");
STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes");

STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte");
STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes");
STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes");
STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes");

STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes");
STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes");

#define TRUE 1
#define FALSE 0

// Platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define LPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required on Windows!"
#endif
#else
#error "Unknown Platform"
#endif

#ifdef LEXPORT
// EXPORTS
#ifdef _MSC_VER
#define LAPI __declspec(dllexport)
#else
#define LAPI __attribute__((visibility("default")))
#endif
#else
// IMPORTS
#ifdef _MSC_VER
#define LAPI __declspec(dllimport)
#else
#define LAPI
#endif
#endif


