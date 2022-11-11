#include <stdio.h>
#include <stdlib.h>
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Array/arraydin.h"

//Menghapus game dalam daftar game
void DeleteGame(ArrayDin *Game, Queue *Gameq)
{
    printf("Masukkan nomor permainan yang akan dihapus: ");
    COMMAND();
    int num = toInt(currentWord);

    //Syarat game yang dapat dihapus
    //Game sistem berjumlah 7 dan tidak dapat dihapus
    if((num > 0) && (num < 8))
    {
        printf("Permainan sistem tidak dapat dihapus.\n");
    }

    //Selain game sistem dapat dihapus namun tidak dapat dihapus jika game berada dalam antrian game
    else if ((num > 7) && (num < (*Game).Neff))
    {
        boolean check = true;
        int i = 0;
        while (check && (i <= IDX_TAIL(*Gameq)))
        {
            if (isWordEqual((*Game).Elmt[num], (*Gameq).buffer[i]))
            {
                check = false;
            }
            i++;
        }
        if (check)
        {
            DeleteAt(Game, num);
            printf("Permainan berhasil dihapus.\n");
        }
        else
        {
            printf("Permainan yang sedang dalam antrian tidak dapat dihapus.\n");
        }
    }
    //Game tidak dapat dihapus jika tidak ada di daftar game
    else
    {
        printf("Permainan tidak ditemukan.\n");
    }
}
