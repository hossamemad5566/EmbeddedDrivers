#ifndef  _STD_TYPES_H_
#define  _STD_TYPES_H_

#define CPU_TYPE_8 8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64
/*==========================================*/
#define CPU_TYPE (CPU_TYPE_8)
/*==========================================*/
#if(CPU_TYPE==CPU_TYPE_8)
typedef unsigned char boolean;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;

typedef  float f32;
typedef  double f64;


#elif (CPU_TYPE==CPU_TYPE_16)
typedef unsigned char boolean;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;

typedef  float f32;
typedef  double f64;



#elif (CPU_TYPE==CPU_TYPE_32)
typedef unsigned char boolean;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;

typedef  float f32;
typedef  double f64;



#elif (CPU_TYPE==CPU_TYPE_64)
typedef unsigned char boolean;
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;

typedef  float f32;
typedef  double f64;

#endif
/*==========================================*/
/*Macros for functions return state*/
#define STD_TYPE_OK  1
#define STD_TYPE_NOK 0

/*NULL pointer to address zero*/
#define NULL ((void*)0)

#endif
