#include "diner_dash.h"

void diner_dash(){
    Diner masak, saji,daftar;
    int saldo = 0,Count = 0;
    int i = 0;
    int daftarr = 2;
    system("cls");
    printf("Selamat Datang di Diner Dash Dash!\n\n");
    while ((daftarr < 7) && (Count < 15) ){ //Jika pelanggan lebih dari 7 atau sudah melayari 15 orang (15 persons served, then game ends)

        printf("Saldo: %d\n\n", saldo);
        printf("Daftar Pesanan\n");
        printf("Makanan\t| Durasi Memasak\t| Ketahanan\t| Harga\n");
        printf("-----------------------------------------------------------");
        for (i=0 ;i<daftarr;i++){
            //intinya disini harus insert id, harga, ketahanan, durasi masak
            printf("M%d\t| %d\t| %d\t| %d\n", daftar.Elmt[i].Mid, daftar.Elmt[i].Dur, daftar.Elmt[i].Tahan, daftar.Elmt[i].Harga);
        }
        printf("\n");
        printf("Daftar Makanan yang sedang dimasak\n"); 
        printf("Makanan\t| Sisa durasi memasak\n");
        printf("-------------------------------------------");
        if (masak.Jml > 0){
            for (i=0;i<masak.Jml;i++){ //ini buat antrian masakan yang lagi dimasak
                printf("M%d\t| %d\n", masak.Elmt[i].Mid, masak.Elmt[i].Tahan);
            }
        
        }
        else{
            printf("\t\t|\n"); //ini kalo misal masih kosong masakan yang mau dimasak
        }

        printf("\n");
        printf("Daftar Makanan yang dapat disajikan\n");
        printf("Makanan\t| Sisa ketahanan makanan\n");
        printf("-------------------------------------------");
        if (saji.Jml > 0){ //ini buat masakan yang udah jadi gitu
            for (i=0;i<saji.Jml;i++){
                printf("M%d\t| %d\n", saji.Elmt[i].Mid, saji.Elmt[i].Tahan);
            }
        
        }
        else{
            printf("\t\t|\n");//kalo belum ada yg bisa di-serve
        }
        

        printf("MASUKKAN COMMAND: ");

        /* scanf("%s",&cmd);    // anggep ada masukkan dulu, ini belum tau apa soalnya :"D ,, misal variabel penampung command = cmd, dan buat nomor = num */ 
        if (cmd == "COOK"){
            if(((num>=0) && (num<=6)) && (masak.Jml <= 5)){ //Syarat masak, cuma bisa sampai 7 pokoknya
                printf("Berhasil memasak M%d\n",num);
                printf("=============================\n");
                //ini kayak insert lah pokoknya, insert dari Q daftar ke Q masak.
                masak.Elmt[masak.Jml].Mid = num;
                masak.Elmt[masak.Jml].Dur = //dari rng;
                masak.Elmt[masak.Jml].Harga = //dari rng;
                masak.Elmt[masak.Jml].Tahan = //dari rng;
                masak.Jml += 1;
                daftarr += 1;

                //ini buat ngurangin semua durasi dan ketahanan masakan saat command berhasil
                for (i = 0;i<masak.Jml;i++){
                    masak.Elmt[i].Dur -= 1;
                }
                for (i = 0;i<saji.Jml;i++){
                    saji.Elmt[i].Tahan -= 1;
                }
                printf("Berhasil memasak M%d.\n",num);

            }
            else{
                printf("Inputan salah, ulangi lagi!\n");
            }

        }
        else if(cmd == "SERVE"){
            if((num>=0) && (num<=5)){
                if(antri_awal == num){  // antri_awal adalah masakan yang pertama kali dipesan namun belum di-serve
                    saldo += saji.Elmt[0].Harga;
                    //intinya disini dequeue si saji, ;
                    Count += 1;
                    daftarr+= 1;

                //ini buat ngurangin semua durasi dan ketahanan masakan saat command berhasil    
                    for (i = 0;i<masak.Jml;i++){
                        masak.Elmt[i].Dur -= 1;
                    }
                    for (i = 0;i<saji.Jml;i++){
                        saji.Elmt[i].Tahan -= 1;
                    }
                    printf("Berhasil mengantar M%d.\n",num);

                }


                else{
                    printf("M%d belum dapat disajikan karena M%d belum selesai\n",num,antri_awal);
                }

            }
            else{
                printf("Masakan M%d tidak ada di menu!\n",num);
            }
            
        }
        else{
            printf("Masukkan salah!\n");
        }
        for(i=0;i<masak.Jml;i++){
            if (masak.Elmt[i].Dur == 0){
                printf("Berhasil memasak M%d.\n",masak.Elmt[i].Mid);
                //disini delete dulu si masakan dari Q masak, pindahin ke Q served

            }
        }
        printf("=======================================");
        
    }
}


//yang belum dipikirkan : 
//1. cara biar tau urutan pesanan dari awal-akhir, jadi ntar pas served harus nungguin dulu
//sesuai urutannya
//2. cara mengisi  variabel"cmd" sama "num" dari file.txt nya
//3. *baca2 dulu... 
