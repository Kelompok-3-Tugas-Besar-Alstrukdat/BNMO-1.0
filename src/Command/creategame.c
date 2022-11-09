#include <stdio.h>
#include <stdlib.h>
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Array/arraydin.h"


void Create(ArrayDin *Game){
    int i = 1;
    boolean cek = true;
    printf("Masukkan nama game yang akan ditambahkan: ");
    COMMAND();
    while((cek == true) && (i < Game->Neff)) {
        if (isWordEqual(currentWord,Game->Elmt[i]){
            cek = false;
        }
        i++;
    }
    if (cek == true){
        printf("Game dengan nama tersebut sudah ada!\n");
    }
    else{
        printf("Berhasil menambahkan game!\n");
        for (i=0;i < currentWord.Length;i++){
            Game->Elmt[Game->Neff].TabWord[i] = currentWord.TabWord[i];
        }
        Game->Neff++;
        int n = toInt (Game->Elmt[0]);
        n++;
        int dig = 0;
        while(n>0){
            n = n/10;
            dig +=1 ;
        }
        for (i=0;i<dig;i++){
            Game->Elmt[0].TabWord[i] = toChar().[i];
        }
        
    }


}
