#include "diner_dash.h"

void diner_dash(){
    Diner_d masak, saji,daftar;
    int saldo = 0,Count = 0;
    int i = 0;
    printf("Selamat Datang di Diner Dash Dash!\n\n");
    while ((masak.Jml < 7) && (Count < 15) ){ //Jika pelanggan lebih dari 7 atau sudah melayari 15 orang (15 persons served, then game ends)
        printf("Saldo: %d\n\n", saldo);
        printf("Daftar Pesanan\n");
        printf("Makanan\t| Durasi Memasak\t| Ketahanan\t| Harga\n");
        printf("-----------------------------------------------------------");
        for (i=0 ;i<=3;i++){
            printf("M%d\t| %d\t| %d\t| %d\n", daftar.Elmt[i].Mid, daftar.Elmt[i].Dur, daftar.Elmt[i].Tahan, daftar.Elmt[i].Harga);
        }
        printf("\n");
        printf("Daftar Makanan yang sedang dimasak\n"); 
        printf("Makanan\t| Sisa durasi memasak\n");
        printf("-------------------------------------------");
        if (masak.Jml > 0){
            for (i=1;i<=masak.Jml;i++){ //ini buat antrian masakan yang lagi dimasak
                printf("M%d\t| %d\n", masak.Elmt[i-1].Mid, masak.Elmt[i-1].Tahan);
            }
        
        }
        else{
            printf("\t\t|\n");
        }

        printf("\n");
        printf("Daftar Makanan yang dapat disajikan\n");
        printf("Makanan\t| Sisa ketahanan makanan\n");
        printf("-------------------------------------------");
        if (saji.Jml > 0){ //ini buat masakan yang udah jadi gitu
            for (i=1;i<=saji.Jml;i++){
                printf("M%d\t| %d\n", saji.Elmt[i-1].Mid, saji.Elmt[i-1].Tahan);
            }
        
        }
        else{
            printf("\t\t|\n");
        }
        
        printf("MASUKKAN COMMAND: ");
        /* scanf("%s",&cmd); */
        
    }
}