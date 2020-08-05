/* 

  Author /el_abbas Salah Hatata
  Date  / 
  Time  /

*/
#ifndef __Std_Type__
#define __Std_Type__
//boolleen

#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

//void 
typedef void    _void ;

//unsigned Type
#define _uint8 unsigned char           // 0 ...... 255 //
#define _uint16 unsigned short int     // 0 ...... 65536 //
#define _uint32 unsigned long int      // 0 ...... 4294967296 //
#define _uint64 unsigned long long int // 0 ...... 18446744073709551615 //
#define _float32 float
#define _float64 double

//signed Type
#define _sint8 signed char           // -128 ...... +127 //
#define _sint16 signed short int     // -32768 ...... +32767 //
#define _sint32 signed long int      // -2147483648 ...... +2147483647     //
#define _sint64 signed long long int // -9223372037709551618 ...... +9223372037709551617 //

#endif