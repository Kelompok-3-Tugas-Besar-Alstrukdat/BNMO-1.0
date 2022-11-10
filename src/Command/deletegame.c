#include <stdio.h>
#include <stdlib.h>
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Array/arraydin.h"

void DELETEGAME (ArrayDin *Game)
{
    int a, i;

    printf("Masukkan nomor game yang akan dihapus: ");
    scanf("%d", &a);

    if((a>=1) && (a<=5))
    {
        printf("Game gagal dihapus \n");
    }

    else if (a>5 && a<*Game.Neff-1)
    {
        i=a-1;
        DeleteAt(Game, i);
        printf("Game berhasil dihapus \n");
    }

    else
    {
        printf("Game tidak ditemukan \n");
    }
}
