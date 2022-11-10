#include "../ADT/Array/arraydin.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/MesinKarakter/mesinkarakter.h"

void Queue(ArrayDin *Game, ArrayDin *Q){
    int i = 0;
    printf("Berikut adalah daftar antrian game-mu\n");
    if (Q->Neff == 0){
        printf("==Game Tidak Ada==\n");
        printf("Daftar antrian mu masih kosong, silakan tambahkan game ke antrian!\n");
    }
    else{
        for (i=0;i<(Q->Neff);i++){
            printf("%d.  ",(i+1));
            printWord(Q->Elmt[i]);
        }
    }
    printf("Berikut adalah game yang tersedia: \n");
    for (i=0;i < (Game->Neff);i++){
            printf("M%d.  ",(i+1));
            printWord(Game->Elmt[i]);
    }
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    COMMAND();
    int a;
    a = toInt(currentWord);
    if ( (a>0) && (a <= (Game->Neff)) ){
        printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");
        InsertLast(Q,Game->Elmt[a-1]);
    }
    else{
        print("Nomor permainan tidak valid, silakan masukkan nomor game pada list.\n");
    }
}