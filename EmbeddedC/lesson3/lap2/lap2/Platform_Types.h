
#ifndef _PLATFORM_TYPES_H_
#define _PLATFORM_TYPES_H_

//-------------------------------------------------------------------------------
//  Platform Data Types
//-------------------------------------------------------------------------------
typedef unsigned char           boolean;
typedef unsigned char           uint8;
typedef signed char             sint8;
typedef unsigned short int      uint16;
typedef signed short int        sint16;
typedef unsigned long int       uint32;
typedef signed long int         sint32;
typedef unsigned long long int  uint64;
typedef signed long long int    sint64;
typedef float                   float32;
typedef double                  float64;
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
//  Volatile Platform Data Types
//-------------------------------------------------------------------------------
typedef volatile unsigned char           vuint8;
typedef volatile signed char             vsint8;
typedef volatile unsigned short int      vuint16;
typedef volatile signed short int        vsint16;
typedef volatile unsigned long int       vuint32;
typedef volatile signed long int         vsint32;
typedef volatile unsigned long long int  vuint64;
typedef volatile signed long long int    vsint64;
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
//  TRUE & FALSE
//-------------------------------------------------------------------------------
#ifndef TRUE
#define TRUE    ((boolean) 1)
#endif

#ifndef FALSE
#define FALSE   ((boolean) 0)
#endif
//-------------------------------------------------------------------------------

#endif