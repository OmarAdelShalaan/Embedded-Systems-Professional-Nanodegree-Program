/*
 * Platform_Types.h
 *
 * Created: 8/24/2022 2:39:54 AM
 *  Author: Omar
 */ 


#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

typedef unsigned char         uint8_t;          /*           0 .. 255             */
typedef signed char           sint8_t;          /*        -128 .. +127            */
typedef unsigned short        uint16_t;         /*           0 .. 65535           */
typedef signed short          sint16_t;         /*      -32768 .. +32767          */
typedef unsigned long         uint32_t;         /*           0 .. 4294967295      */
typedef signed long           sint32_t;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64_t;         /*       0..18446744073709551615  */
typedef signed long long      sint64_t;
typedef float                 float32_t;
typedef double                float64_t;

#define High  1
#define LOW   0
typedef enum{
	False = 0,
	True = 1
}bool;


#endif /* PLATFORM_TYPES_H_ */
