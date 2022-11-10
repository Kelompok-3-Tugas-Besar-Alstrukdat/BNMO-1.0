#ifndef __DINER_DASH__
#define __DINER_DASH__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../../boolean.h"
#include "../../ADT/Array/arraydin.c"
#include "../../ADT/MesinKata/mesinkata.c"
#include "../../ADT/MesinKarakter/mesinkarakter.c"

#define IDX_UNDEF -1
#define DCAPACITY 20

/* Definisi elemen dan address */
typedef struct
{
    int Elmt[DCAPACITY];
} DinerArr;


typedef struct
{
    int Duration;
    int Resistance;
    int Price;
} DinerQType;

typedef struct
{
	DinerQType buffer[DCAPACITY];
	int idxHead;
	int idxTail;
    int capacity;
} DinerQ;


/* ********* AKSES (Selektor) ********* */
/* Jika dq adalah DinerQ, maka akses elemen : */
#define IDX_HEAD(dq) (dq).idxHead
#define IDX_TAIL(dq) (dq).idxTail
#define     HEAD(dq) (dq).buffer[(dq).idxHead]
#define     TAIL(dq) (dq).buffer[(dq).idxTail]
#define CAPACITY(dq) (dq).capacity


/* *** Kreator *** */
void CreateDinerQ(DinerQ *dq);
/* I.S. sembarang */
/* F.S. Sebuah dq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah dq kosong */

void CreateDinerArr(DinerArr *da);
/* I.S. sembarang */
/* F.S. Sebuah da kosong terbentuk dengan kondisi sbb: */
/* - Elmt bernilai IDX_UNDEF */


/* ********* Prototype ********* */
boolean isEmpty(DinerQ dq);
/* Mengirim true jika dq kosong: lihat definisi di atas */
boolean isFull(DinerQ dq);
/* Mengirim true jika tabel penampung elemen dq sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD */
/* IDX_HEAD selalu bernilai 0 */

int length(DinerQ dq);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika dq kosong */

/* *** Primitif Add/Delete *** */
void enqueue(DinerQ *dq, DinerQType val);
/* Proses: Menambahkan val pada dq dengan aturan FIFO */
/* I.S. dq mungkin kosong, tabel penampung elemen dq mungkin penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL bertambah satu */

void dequeue(DinerQ *dq, DinerQType *val);
/* Proses: Menghapus val pada dq dengan aturan FIFO */
/* I.S. dq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., semua elemen bergeser ke kiri, dan dq mungkin kosong */

/* *** Display DinerQ *** */
void displayQueue(DinerQ dq);
/* Proses : Menuliskan isi DinerQ dengan traversal, DinerQ ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. dq boleh kosong */
/* F.S. Jika dq tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika DinerQ kosong : menulis [] */

void controlRand();

DinerQType randVal();

void run_DinerDash();

#endif