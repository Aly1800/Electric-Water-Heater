#ifndef STD_TYPE_H
#define STD_TYPE_H

typedef unsigned char           u8;
typedef unsigned short int      u16;
typedef unsigned long int       u32;
typedef unsigned long long int  u64;

typedef signed char             s8;
typedef signed short int        s16;
typedef signed long int         s32;
typedef signed long long int    s64;

typedef float                   f32;
typedef double                  f64;

typedef void (*void_func_ptr)(void);

#define NULL ((void*)0)

#endif
