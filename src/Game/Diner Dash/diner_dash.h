#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef int keytype;
typedef int valuetype;
typedef int address;
typedef int Price;
typedef int Resist;
typedef int Duration;
typedef int Id;
typedef int Count;

typedef struct
{
	Id Mid;
	Duration Dur;
    Resist Tahan;
    Price Harga; 

} infotype;

typedef struct
{
	infotype Elmt[10];
    Count Jml;
} Diner_d;

#ifndef Diner_Dash
#define Diner_Dash

#endif