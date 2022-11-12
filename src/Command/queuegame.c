// Include Header
#include "commands.h"

void QueueGame(ArrayDin *Game, Queue *Q){
    int i = 0;
    printf("Berikut adalah daftar antrian permainanmu: \n");
    if (lengthQueue(*Q) == 0){
        printf("\n-- Permainan Tidak Ada --\n");
        printf("\nDaftar antrian permainanmu masih kosong, silakan tambahkan permainan terlebih dahulu!\n");
    }
    else{
        for (i = 0; i < lengthQueue(*Q); i++){
            printf("%d.  ",(i+1));
            printWord(Q->buffer[i]);
        }
    }
    printf("\n\nBerikut adalah permainan yang tersedia: \n");
    for (i=1;i < (Game->Neff);i++){
            printf("%d.  ",i);
            printWord(Game->Elmt[i]);
    }
    printf("Nomor permainan yang mau ditambahkan ke antrian: ");
    COMMAND();
    int a;
    a = toInt(currentWord);
    if ( (a>0) && (a < (Game->Neff)) ){
        printf("Permainan berhasil ditambahkan ke dalam daftar antrian.\n");
        enqueueQ(Q,Game->Elmt[a]);
    }
    else{
        printf("Nomor permainan tidak valid, silakan masukkan nomor permainan yang ada pada list.\n");
    }
}