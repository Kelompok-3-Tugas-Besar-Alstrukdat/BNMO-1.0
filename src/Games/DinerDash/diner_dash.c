#include "diner_dash.h"


/* *** Kreator *** */
void CreateDinerQ(DinerQ *dq)
{
    CAPACITY(*dq) = DCAPACITY;
    for (int i = 0; i < DCAPACITY; i++)
    {
        (*dq).buffer[i].Duration = IDX_UNDEF;
        (*dq).buffer[i].Resistance = IDX_UNDEF;
        (*dq).buffer[i].Price = IDX_UNDEF;
    }
    IDX_HEAD(*dq) = IDX_UNDEF;
    IDX_TAIL(*dq) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah dq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah dq kosong */

void CreateDinerArr(DinerArr *da)
{
    for (int i = 0; i  < DCAPACITY; i++)
    {
        (*da).Elmt[i] = IDX_UNDEF;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah da kosong terbentuk dengan kondisi sbb: */
/* - Elmt bernilai IDX_UNDEF */


/* ********* Prototype ********* */
boolean isEmpty(DinerQ dq)
{
    return (IDX_HEAD(dq) == IDX_UNDEF) && (IDX_TAIL(dq) == IDX_UNDEF);
}
/* Mengirim true jika dq kosong: lihat definisi di atas */
boolean isFull(DinerQ dq)
{
    return (IDX_HEAD(dq) == 0) && (IDX_TAIL(dq) == (CAPACITY(dq) - 1));
}
/* Mengirim true jika tabel penampung elemen dq sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD */
/* IDX_HEAD selalu bernilai 0 */

int length(DinerQ dq)
{
    return IDX_TAIL(dq) - IDX_HEAD(dq) + 1;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika dq kosong */

/* *** Primitif Add/Delete *** */
void enqueue(DinerQ *dq, DinerQType val)
{
    if (isEmpty(*dq))
    {
        IDX_HEAD(*dq) = 0;
    }
    IDX_TAIL(*dq)++;
    TAIL(*dq).Duration = val.Duration;
    TAIL(*dq).Resistance = val.Resistance;
    TAIL(*dq).Price = val.Price;
}
/* Proses: Menambahkan val pada dq dengan aturan FIFO */
/* I.S. dq mungkin kosong, tabel penampung elemen dq mungkin penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL bertambah satu */

void dequeue(DinerQ *dq, DinerQType *val)
{
    (*val).Duration = HEAD(*dq).Duration;
    (*val).Resistance = HEAD(*dq).Resistance;
    (*val).Price = HEAD(*dq).Price;
    if (IDX_TAIL(*dq) == IDX_HEAD(*dq))
    {
        IDX_HEAD(*dq) = IDX_UNDEF;
        IDX_TAIL(*dq) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD(*dq)++;
    }
}
/* Proses: Menghapus val pada dq dengan aturan FIFO */
/* I.S. dq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., semua elemen bergeser ke kiri, dan dq mungkin kosong */

/* *** Display DinerQ *** */
void displayQueue(DinerQ dq)
{
    for (int i = IDX_HEAD(dq); i <= IDX_TAIL(dq); i++)
    {
        printf("M%d\t| %d\t\t | %d\t     | %d\t\n", i, dq.buffer[i].Duration, dq.buffer[i].Resistance, dq.buffer[i].Price);
    }
}
/* Proses : Menuliskan isi DinerQ dengan traversal, DinerQ ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. dq boleh kosong */
/* F.S. Jika dq tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika DinerQ kosong : menulis [] */

void controlRand()
{
    time_t t;
    srand(time(&t));
}

DinerQType randVal()
{
    DinerQType val;
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            val.Duration = (rand() % 5) + 1;
        }
        else if (i == 1)
        {
            val.Resistance = (rand() % 5) + 1;
        }
        else
        {
            val.Price = ((rand() % 40) + 10) * 1000;
        }
    }
    return val;
}

void main()
{
    printf("Selamat Datang di Diner Dash!\n");
    int Saldo = 0;
    DinerQ DQDash;
    DinerArr DACook, DAServe;
    
    // Control random number generator
    controlRand();

    CreateDinerQ(&DQDash);
    for (int i = 0; i < 3; i++)
    {
        enqueue(&DQDash, randVal());
    }

    CreateDinerArr(&DACook);
    CreateDinerArr(&DAServe);
    
    while ((length(DQDash) < 8) && (IDX_HEAD(DQDash) < 16))
    {
        printf("\nSALDO: %d\n", Saldo);
        printf("\nDaftar Pesanan\n");
        printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
        printf("--------------------------------------------\n");
        displayQueue(DQDash);

        printf("\nDaftar Makanan yang sedang dimasak\n");
        printf("Makanan | Sisa durasi memasak\n");
        printf("--------------------------------\n");
        for (int i = 0; i < DCAPACITY; i++)
        {
            if (DACook.Elmt[i] != IDX_UNDEF)
            {
                printf("M%d\t| %d\t\n", i, DACook.Elmt[i]);
            }
        }

        printf("\nDaftar Makanan yang dapat disajikan\n");
        printf("Makanan | Sisa ketahanan makanan\n");
        printf("--------------------------------\n");
        for (int i = 0; i < DCAPACITY; i++)
        {
            if (DAServe.Elmt[i] != IDX_UNDEF)
            {
                printf("M%d\t| %d\t\n", i, DAServe.Elmt[i]);
            }
        }

        ArrayDin command = MakeArrayDin();
        // COOK
        command.Elmt[0].Length = 4;
        char CMDCOOK[10] = "COOK";
        for (int i = 0; i < 4; i++)
        {
            command.Elmt[0].TabWord[i] = CMDCOOK[i];
        }
        // SERVE
        command.Elmt[1].Length = 5;
        char CMDSERVE[10] = "SERVE";
        for (int i = 0; i < 5; i++)
        {
            command.Elmt[1].TabWord[i] = CMDSERVE[i];
        }
        // SKIP
        command.Elmt[2].Length = 4;
        char CMDSKIP[10] = "SKIP";
        for (int i = 0; i < 4; i++)
        {
            command.Elmt[2].TabWord[i] = CMDSKIP[i];
        }

        Word Input;
        int N;
        printf("\nMASUKKAN COMMAND: ");
        COMMAND();
        system("cls");
        if (currentWord.Length > 4)
        {
            int i = 0;
            while ((currentWord.TabWord[i] != ' ') && (i < currentWord.Length))
            {
                Input.TabWord[i] = currentWord.TabWord[i];
                i++;
            }
            Input.Length = i;

            i++;
            if (currentWord.TabWord[i] == 'M')
            {
                i++;
                Word TN;
                for (int j = i; j < currentWord.Length; j++)
                {
                    TN.TabWord[j-i] = currentWord.TabWord[j];
                }
                TN.Length = currentWord.Length - i;
                N = toInt(TN);
            }
            
        }
        else
        {
            for (int i = 0; i < currentWord.Length; i++)
            {
                Input.TabWord[i] = currentWord.TabWord[i];
            }
            Input.Length = currentWord.Length;
        }

        // Data Ketahanan Makanan yang Telah Siap Disajikan
        for (int i = 0; i < DCAPACITY; i++)
        {
            if (DAServe.Elmt[i] > 0)
            {
                DAServe.Elmt[i]--;
            }
            if (DAServe.Elmt[i] == 0)
            {
                DAServe.Elmt[i] = IDX_UNDEF;
                printf("Makanan M%d telah basi dan harus dimasak kembali\n", i);
            }
        }

        // Proses Memasak Makanan
        for (int i = 0; i < DCAPACITY; i++)
        {
            if (DACook.Elmt[i] > 0)
            {
                DACook.Elmt[i]--;
            }
            if (DACook.Elmt[i] == 0)
            {
                DACook.Elmt[i] = IDX_UNDEF;
                DAServe.Elmt[i] = DQDash.buffer[i].Resistance;
                printf("Makanan M%d telah selesai dimasak\n", i);
            }
        }

        // Input == COOK
        if (isWordEqual(Input, command.Elmt[0]) && (N >= IDX_HEAD(DQDash) && N <= IDX_TAIL(DQDash)))
        {
            if (DACook.Elmt[N] != IDX_UNDEF)
            {
                printf("Makanan M%d sudah dimasak\n", N);
            }
            else
            {
                DACook.Elmt[N] = DQDash.buffer[N].Duration;
                printf("Berhasil memasak M%d\n", N);
            }
        }
        // Input == SERVE
        else if (isWordEqual(Input, command.Elmt[1]) && (N >= IDX_HEAD(DQDash) && N <= IDX_TAIL(DQDash)))
        {
            if (IDX_HEAD(DQDash) == N)
            {
                DinerQType val;
                dequeue(&DQDash, &val);
                Saldo += val.Price;
                DAServe.Elmt[N] = IDX_UNDEF;
                printf("Berhasil mengantar M%d\n", N);
            }
            else
            {
                printf("M%d belum dapat disajikan karena M%d belum selesai\n", N, IDX_HEAD(DQDash));
            }
        }
        // Input == SKIP
        else if (isWordEqual(Input, command.Elmt[2]))
        {
            
        }
        // Input tidak valid
        else
        {
            printf("Command yang Anda masukkan tidak valid\n");
        }
        // Pelanggan bertambah
        enqueue(&DQDash, randVal());
        printf("=======================================================\n");
    }
    if (length(DQDash) > 7)
    {
        printf("Permainan telah selesai karena antrian Anda telah melebihi 7 pelanggan\n");
    }
    else
    {
        printf("Permainan telah selesai karena Anda telah melayani 15 pelanggan\n");
    }
}