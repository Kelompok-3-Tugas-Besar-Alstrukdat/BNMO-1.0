#ifndef __DINER_DASH__
#define __DINER_DASH__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../../boolean.h"
#include "../../ADT/Array/arraydin.h"
#include "../../ADT/MesinKata/mesinkata.h"

#define Idx_Undef -999
#define DCapacity 20

/* Definisi elemen dan address */
typedef struct
{
    int Elmt[DCapacity];
} DinerArr;


typedef struct
{
    int Duration;
    int Resistance;
    int Price;
} DinerQType;

typedef struct
{
	DinerQType buffer[DCapacity];
	int idxHead;
	int idxTail;
    int Capacity;
} DinerQ;


/* ********* AKSES (Selektor) ********* */
/* Jika dq adalah DinerQ, maka akses elemen : */
#define Idx_Head(dq) (dq).idxHead
#define Idx_Tail(dq) (dq).idxTail
#define     Head(dq) (dq).buffer[(dq).idxHead]
#define     Tail(dq) (dq).buffer[(dq).idxTail]
#define Capacity(dq) (dq).Capacity


/* *** Kreator *** */
void CreateDinerQ(DinerQ *dq);
/* I.S. sembarang */
/* F.S. Sebuah dq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai Idx_Undef */
/* - Index Tail bernilai Idx_Undef */
/* Proses : Melakukan alokasi, membuat sebuah dq kosong */

void CreateDinerArr(DinerArr *da);
/* I.S. sembarang */
/* F.S. Sebuah da kosong terbentuk dengan kondisi sbb: */
/* - Elmt bernilai Idx_Undef */


/* ********* Prototype ********* */
boolean isEmptyDQ(DinerQ dq);
/* Mengirim true jika dq kosong: lihat definisi di atas */
boolean isFullDQ(DinerQ dq);
/* Mengirim true jika tabel penampung elemen dq sudah penuh */
/* yaitu Idx_Tail akan selalu di belakang Idx_Head */
/* Idx_Head selalu bernilai 0 */

int lengthDQ(DinerQ dq);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika dq kosong */

/* *** Primitif Add/Delete *** */
void enqueueDQ(DinerQ *dq, DinerQType val);
/* Proses: Menambahkan val pada dq dengan aturan FIFO */
/* I.S. dq mungkin kosong, tabel penampung elemen dq mungkin penuh */
/* F.S. val menjadi Tail yang baru, Idx_Tail bertambah satu */

void dequeueDQ(DinerQ *dq, DinerQType *val);
/* Proses: Menghapus val pada dq dengan aturan FIFO */
/* I.S. dq tidak mungkin kosong */
/* F.S. val = nilai elemen Head pd I.S., semua elemen bergeser ke kiri, dan dq mungkin kosong */

/* *** Display DinerQ *** */
void displayQueueDQ(DinerQ dq);
/* Proses : Menuliskan isi DinerQ dengan traversal, DinerQ ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. dq boleh kosong */
/* F.S. Jika dq tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika DinerQ kosong : menulis [] */

void controlRand();

DinerQType randVal();

void runDinerDash();

#endif