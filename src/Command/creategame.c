#include <stdio.h>
#include <stdlib.h>
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Array/arraydin.h"

void Create(ArrayDin *Game){
    int i = 1;
    boolean cek = true;
    printf("Masukkan nama game yang akan ditambahkan: ");
    COMMAND();
    while((cek == true) && (i < (*Game).Neff)) {
        if (isWordEqual(currentWord,(*Game).Elmt[i])){
            cek = false;
        }
        i++;
    }
    if (cek == false){
        printf("Game dengan nama tersebut sudah ada!\n");
    }
    else{
        InsertLast(&(*Game), currentWord);
        int n = toInt((*Game).Elmt[0]);
        n++;
        for (i=0;i<toWord(n).Length;i++){
            (*Game).Elmt[0].TabWord[i] = toWord(n).TabWord[i];
        }
        (*Game).Elmt[0].Length = toWord(n).Length;
        printf("Berhasil menambahkan game!\n");
    }


}
