#include "diner_dash.h"

void diner_dash(){
    int i = 0;
    printf("Selamat Datang di Diner Dash Dash!\n\n");
    printf("Saldo: %d\n\n", saldo);
    printf("Daftar Pesanan\n");
    printf("Makanan\t| Durasi Memasak\t| Ketahanan\t| Harga\n");
    printf("-----------------------------------------------------------");
    for (i=1 ;i<=3;i++){
        printf("M%d\t| %d\t| %d\t| %d\n", id, durasi, resist, price);
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