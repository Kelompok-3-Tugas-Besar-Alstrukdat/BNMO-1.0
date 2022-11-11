#ifndef __POINT__
#define __POINT__

#include <stdio.h>
#include "../../boolean.h"
#include "../MesinKata/mesinkata.h"

/**** Definisi Abstract Data Type POINT ****/
typedef struct
{
    int x; /* absis */
    int y; /* ordinat */
} Point;

/**** Selektor point ****/
#define ABSIS(p) (p).x
#define ORDINAT(p) (p).y

/**** Konstruktor POINT ****/
void CreatePoint(Point* p, int x, int y);
/* Membentuk sebuah point dari x dan y dengan x sebagai absis dan y sebagai ordinat */

/**** Predikat ****/
boolean isOrigin (Point p);
/* Mengirimkan nilai benar jika p adalah titik origin yaitu titik <0,0> */

/**** Prosedur - Interaksi dengan I/O device ****/
void displayPoint (Point p);
/* Nilai p ditulis ke layar dg format "(X,Y)" */

/**** Fungsi/Operasi lain terhadap point ****/
Point move (Point p, int dx, int dy);
/* Menghasilkan point yang merupakan hasil penggeseran p */
/* sebesar dx arah sumbu x dan dy arah sumbu y */

#endif