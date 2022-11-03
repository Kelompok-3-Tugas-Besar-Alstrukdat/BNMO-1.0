#include "diner_dash.h"

void diner_dash(){
    Diner_d masak, sajikan;
    int i = 0;
    printf("Selamat Datang di Diner Dash Dash!\n\n");
    while ((Pelanggan < 7) && (Count < 15) ){ //Jika pelanggan lebih dari 7 atau sudah melayari 15 orang (15 persons served, then game ends)
        printf("Saldo: %d\n\n", saldo);
        printf("Daftar Pesanan\n");
        printf("Makanan\t| Durasi Memasak\t| Ketahanan\t| Harga\n");
        printf("-----------------------------------------------------------");
        for (i=1 ;i<=3;i++){
            printf("M%d\t| %d\t| %d\t| %d\n", Diner_d.Elmt[i-1].Mid, Diner_d.Elmt[i-1].Dur, Diner_d.Elmt[i-1].Tahan, Diner_d.Elmt[i-1].Harga);
        }
        printf("\n");
        printf("Daftar Makanan yang sedang dimasak\n");
        printf("Makanan\t| Sisa durasi memasak\n");
        printf("-------------------------------------------");
        if (t_c > 0){
            for (i=1;i<=t_c;i++){
                printf("M%d\t| %d\n");
            }
        
        }

        printf("\n");
        printf("Daftar Makanan yang dapat disajikan\n");
        printf("Makanan\t| Sisa ketahanan makanan\n");
        printf("-------------------------------------------");
        if (served > 0){
            for (i=1;i<=served;i++){
                printf("M%d\t| %d\n");
            }
        
        }
        
        printf("MASUKKAN COMMAND: ");
        scanf("%s",&cmd);
        
    }
}