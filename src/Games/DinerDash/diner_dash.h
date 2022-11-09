#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#ifndef Diner_Dash
#define Diner_Dash


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
	Count Jml; // Jumlah antrian masak(pelanggan) dan antrian served (makanan jadi)
} Diner;

void create_empty(Diner *X);
void diner_del(Diner *X, Id xid, Duration d);
void diner_ins(Diner*X, Diner *Y, Id xid);
void diner_dash();

#endif