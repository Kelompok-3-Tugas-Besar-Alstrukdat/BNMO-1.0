#include <stdio.h>
#include <stdlib.h>
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Array/arraydin.h"

void DeleteGame(ArrayDin *Game)
{
    printf("Masukkan nomor game yang akan dihapus: ");
    COMMAND();
    int num = toInt(currentWord);

    if((num >= 1) && (num <= 5))
    {
        printf("Game gagal dihapus \n");
    }

    else if ((num > 5) && (num < (*Game).Neff))
    {
        DeleteAt(Game, num);
        printf("Game berhasil dihapus \n");
    }
    else
    {
        printf("Game tidak ditemukan \n");
    }
}
