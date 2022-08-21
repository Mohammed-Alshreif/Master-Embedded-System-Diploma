#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#include <stdio.h>
#include <stdbool.h>

#ifndef _Bool
#define _Bool unsigned char
#endif

#define CPU_TYPE  CPU_TYPE_32
#define CPU_BIT_ORDED  MSB_FIRST
#define CPU_BYTE_ORDED  HIGH_BYTE_FIRST

#ifndef FALSE
#define FALSE  (boolean)false
#endif

#ifndef TRUE
#define TRUE   (boolean)true
#endif

typedef _Bool 			boolean_t;
typedef signed char 	sint8_t;
typedef unsigned char 	uint8_t;
typedef char 			char_t_t;
typedef signed short 	sint16_t;
typedef unsigned short 	uint16_t;
typedef int 			sint32_t;
typedef unsigned  		uint32_;
typedef signed long long 	sint64_t;
typedef unsigned long long	uint64_t;


typedef volatile signed char 		vint8_t;
typedef volatile unsigned char 		vuint8_t;

typedef volatile signed short 		vint16_t;
typedef volatile unsigned short 	vuint16_t;

typedef volatile int 				vint32_t;
typedef volatile unsigned  			vuint32_t;

typedef volatile signed long 	vint64_t;
typedef volatile unsigned long 	vuint64_t;

#endif /* PLATFORM_TYPES_H_ */
