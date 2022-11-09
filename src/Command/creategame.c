#include <stdio.h>
#include <stdlib.h>
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Array/arraydin.h"


void Create(){
    char inp[20];
    ArrayDin Game = MakeArrayDin();
    char filename[50] = "docs/";
    int i = 0;
    int j = 0,cek=0,leng;
    int prin=0;

    STARTWORD("docs/config.txt");
    while (!EndWord){
        Game.Elmt[i].Length = currentWord.Length;
        for (int j = 0; j < currentWord.Length; j++){
            Game.Elmt[i].TabWord[j] = currentWord.TabWord[j];
        }
        ADVWORD();
        i++;
    }
    Game.Neff = i;
    
    printf("Masukkan nama game yang akan ditambahkan: ");
    scanf("%s",&inp);


    for (i=0;i<Game.Neff;i++){
        if (cek == 0){

            for (j = 0; j < Game.Elmt[i].Length;j++){
                if(Game.Elmt[i].TabWord[j] == inp[j]){
                    cek += 1;
                }
                leng += 1;
            }

            if (cek == Game.Elmt[i].Length){
                //printf("Game dengan nama tersebut sudah ada\n");
                cek = 0;
                leng = 0;
                
            }
            else{
                cek = -99;
            }
            if (cek==-99){
                printf("Game berhasil ditambahkan!\n");
                cek = -1;
                for (int k = 0; k<leng;k++){
                    Game.Elmt[Game.Neff].TabWord[k] = inp[k];
                }
                Game.Elmt[Game.Neff].Length = leng;
                Game.Neff+=1;
                prin = -99;
                break;
            }            

        }
    }
    if (prin != -99){
        printf("Game dengan nama tersebut sudah ada\n");
    }
        
    
}