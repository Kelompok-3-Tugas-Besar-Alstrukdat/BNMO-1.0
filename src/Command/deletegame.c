#include <stdio.h>
#include <stdlib.h>
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Array/arraydin.h"

void DeleteGame(ArrayDin *Game)
{
    printf("Masukkan nomor permainan yang akan dihapus: ");
    COMMAND();
    int num = toInt(currentWord);

    if((num > 0) && (num < 8))
    {
        printf("Permainan sistem tidak dapat dihapus.\n");
    }

    else if ((num > 7) && (num < (*Game).Neff))
    {
        DeleteAt(Game, num);
        printf("Prmainan berhasil dihapus.\n");
    }
    else
    {
        printf("Permainan tidak ditemukan.\n");
    }
}
