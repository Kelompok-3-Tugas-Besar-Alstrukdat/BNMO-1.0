#include "queue.h"

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]
#define CAPACITY(q) (q).capacity

/* *** Kreator *** */
void CreateQueue(Queue *q)
{
    do
    {
        (*q).buffer = (QueueType *) malloc (INIT_CAPACITY * sizeof(QueueType));
    }
    while ((*q).buffer == NULL);
    (*q).capacity = INIT_CAPACITY;
    (*q).idxHead = IDX_UNDEF;
    (*q).idxTail = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/**
 * Destruktor
 * I.S. Queue terdefinisi
 * F.S. q.buffer terdealokasi
 */
void DeallocateQueue(Queue *q)
{
    free((*q).buffer);
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
{
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Queue q)
{
    return IDX_TAIL(q) == (CAPACITY(q) - 1);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD */
/* IDX_HEAD selalu bernilai 0 */

int length(Queue q)
{
    return IDX_TAIL(q) + 1;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, QueueType val)
{
    if (isFull(*q))
    {
        CAPACITY(*q) *= 2;
        realloc((*q).buffer, CAPACITY(*q));
    }
    if (isEmpty(*q))
    {
        IDX_HEAD(*q) = 0;
    }
    IDX_TAIL(*q)++;
    TAIL(*q) = val;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q mungkin penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL bertambah satu */

void dequeue(Queue *q, QueueType *val)
{
    (*val) = HEAD(*q);
    if (IDX_TAIL(*q) == 0)
    {
        IDX_HEAD(*q) = IDX_UNDEF;
    }
    else
    {
        for (int i = 0; i < IDX_TAIL(*q); i++)
        {
            (*q).buffer[i] = (*q).buffer[i + 1];
        }
    }
    IDX_TAIL(*q)--;
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., semua elemen bergeser ke kiri, dan q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q)
{
    if (isEmpty(q))
    {
        printf("[]\n");
    }
    else
    {
        printf("[");
        for (int i = 0; i < IDX_TAIL(q); i++)
        {
            printf("%d,", q.buffer[i]);
        }
        printf("%d]\n", TAIL(q));
    }
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */