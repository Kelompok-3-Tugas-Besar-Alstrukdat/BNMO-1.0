#include "diner_dash.h"
#include "../RNG/rng.c" //ternyata rng.h ilang

void create_empty(Diner *X){
    int i = 0;
    for (i;i<10;i++){
        X->Elmt[i].Dur = -1;
        X->Elmt[i].Harga = -1;
        X->Elmt[i].Mid = -1;
        X->Elmt[i].Tahan = -1;
    }
    X->Jml = 0;
}

void diner_del(Diner *X, Id xid, Duration d){
    if(X->Jml != 1){
        int cek = 0;
        for (int i = 0;i<(X->Jml);i++){
            if( (X->Elmt[i].Mid == xid) && (X->Elmt[i].Dur == d) && (cek == 0)){
                for (int j = i; j<(X->Jml) - 1;j++){
                    X->Elmt[j].Dur = X->Elmt[j+1].Dur;
                    X->Elmt[j].Mid = X->Elmt[j+1].Mid;
                    X->Elmt[j].Tahan = X->Elmt[j+1].Tahan;
                    X->Elmt[j].Harga = X->Elmt[j+1].Harga;
                }
                cek = -1;   
            }
        
    }
    }
    X->Elmt[(X->Jml)-1].Dur = -1;
    X->Elmt[(X->Jml)-1].Harga = -1;
    X->Elmt[(X->Jml)-1].Tahan = -1;
    X->Elmt[(X->Jml)-1].Mid = -1;
    X->Jml -= 1;
}

void diner_ins(Diner *X,Diner *Y, Id xid){
    X->Elmt[X->Jml].Dur = Y->Elmt[xid].Dur;
    X->Elmt[X->Jml].Harga = Y->Elmt[xid].Harga;
    X->Elmt[X->Jml].Tahan = Y->Elmt[xid].Tahan;
    X->Elmt[X->Jml].Mid = Y->Elmt[xid].Mid;
    X->Jml += 1;        
}


void diner_dash(){

    Diner *masak, *saji, *daftar;
    int saldo = 0,Count = 0, i = 0, daftarr = 2, num,awal = 0,x, idx = 0;
    char cmd;
    int antri_awal[10] = 0;

    create_empty(masak);
    create_empty(saji);
    create_empty(daftar);

    system("cls");
    printf("Selamat Datang di Diner Dash Dash!\n\n");

    while ((daftarr < 7) && (Count < 15) ){ 

        printf("Saldo: %d\n\n", saldo);
        printf("Daftar Pesanan\n");
        printf("Makanan\t| Durasi Memasak\t| Ketahanan\t| Harga\n");
        printf("-----------------------------------------------------------");
        //Pengisian Komponen - komponen dalam tiap masakan
        for (i=0;i<daftarr;i++){  
            if (daftar->Elmt[i].Harga == -1){
                x = RandomNumber();
                while ((x < 10) || (x > 50)){
                    x = RandomNumber();
                }
                daftar->Elmt[i].Harga = x*1000;
                x = RandomNumber();
                while ((x == 0) && (x >  5)){
                    x = RandomNumber();
                }
                daftar->Elmt[i].Dur = x;
                x = RandomNumber();
                while ((x == 0) && (x >  5)){
                    x = RandomNumber();
                }
                daftar->Elmt[i].Tahan = x;
                daftar->Elmt[i].Mid = i;
                daftar->Jml += 1;
            }
        }
        //Menampilkan daftar pesanan
        for (i=0 ;i<(daftar->Jml);i++){       
            printf("M%d\t| %d\t| %d\t| %d\n", daftar->Elmt[i].Mid, daftar->Elmt[i].Dur, daftar->Elmt[i].Tahan, daftar->Elmt[i].Harga);
        }
        printf("\n");
        printf("Daftar Makanan yang sedang dimasak\n"); 
        printf("Makanan\t| Sisa durasi memasak\n");
        printf("-------------------------------------------");
        ////Menampilkan daftar masakan yang sedang dimasak
        if (masak->Jml > 0){
            for (i=0;i<masak->Jml;i++){ 
                printf("M%d\t| %d\n", masak->Elmt[i].Mid, masak->Elmt[i].Tahan);
            }
        }
        else{
            printf("\t\t|\n"); 
        }
        printf("\n");
        printf("Daftar Makanan yang dapat disajikan\n");
        printf("Makanan\t| Sisa ketahanan makanan\n");
        printf("-------------------------------------------");
        //Menampilkan daftar makanan yang sudah bisa di-serve
        if (saji->Jml > 0){ 
            for (i=0;i<saji->Jml;i++){
                printf("M%d\t| %d\n", saji->Elmt[i].Mid, saji->Elmt[i].Tahan);
            }      
        }
        else{
            printf("\t\t|\n");
        }
        
        //Memasukkan Command
        printf("MASUKKAN COMMAND: ");
        scanf("%s %d",&cmd,&num);  // MASIH BELUM NGERTI PAKE MESIN KATANYA GIMANA
        //Command COOK
        if (cmd == "COOK"){
            if(((num>=0) && (num<=6)) && (masak->Jml <= 5) && (num < daftar->Jml)){ 
                printf("Berhasil memasak M%d\n",num);
                antri_awal[awal] = num;
                awal += 1;
                printf("=============================\n");
                //ini kayak insert lah pokoknya, insert dari Q daftar ke Q masak.
                masak->Elmt[masak->Jml].Mid = daftar->Elmt[num].Mid;
                masak->Elmt[masak->Jml].Dur = daftar->Elmt[num].Dur;
                masak->Elmt[masak->Jml].Harga = daftar->Elmt[num].Harga;
                masak->Elmt[masak->Jml].Tahan = daftar->Elmt[num].Tahan;
                masak->Jml += 1;
                daftarr += 1; //daftar pesanan nanti bakal nambah 1

                //Mengurangi semua durasi dan ketahanan makanan di daftar serve dan masak
                for (i = 0;i<(masak->Jml);i++){
                    masak->Elmt[i].Dur -= 1;
                }
                for (i = 0;i<(saji->Jml);i++){
                    saji->Elmt[i].Tahan -= 1;
                }
                printf("Berhasil memasak M%d.\n",num);
            }
            else{
                printf("Masakan belum masuk pesanan atau kompor sedang penuh, ulangi lagi!\n");
            }
            
        }
        //Command SERVE
        else if(cmd == "SERVE"){
            if((num>=0) && (num<=6)) {
                if((antri_awal[idx] == num) && (saji->Elmt[0].Mid == num))  {
                    saldo += saji->Elmt[0].Harga;
                    diner_del (saji, num, saji->Elmt[num].Dur);
                    Count += 1;
                    daftarr+= 1;
                    idx += 1;
                    //Mengurangi semua durasi dan ketahanan makanan di daftar serve dan masak
                    for (i = 0;i<(masak->Jml);i++){
                        masak->Elmt[i].Dur -= 1;
                    }
                    for (i = 0;i<(saji->Jml);i++){
                        saji->Elmt[i].Tahan -= 1;
                    }
                    printf("Berhasil mengantar M%d.\n",num);
                }
                else{
                    printf("M%d belum dapat disajikan karena M%d belum selesai\n",num,antri_awal[0]);
                }
            }
            else{
                printf("Masakan M%d tidak ada di menu!\n",num);
            }
        }
        // Command SKIP
        else if (cmd=="SKIP"){
            //Mengurangi semua durasi dan ketahanan makanan di daftar serve dan masak
            for (i = 0;i<(masak->Jml);i++){
                masak->Elmt[i].Dur -= 1;
            }
            for (i = 0;i<(saji->Jml);i++){
                saji->Elmt[i].Tahan -= 1;
            }
            daftarr+= 1;
            printf("Berhasil SKIP!\n");
        }
        else{
            printf("Masukkan salah!\n");
        }

        //Cek apakah ada masakan yang sudah bisa pindah ke Serve dan apakah ada makanan di Serve yang sudah tidak layak
        for(i=0;i<masak->Jml;i++){
            if (masak->Elmt[i].Dur == 0){
                printf("Berhasil memasak M%d.\n",masak->Elmt[i].Mid);
                masak->Elmt[i].Dur == daftar->Elmt[masak->Elmt[i].Mid].Dur;
                diner_ins (saji,masak,i);
                diner_del (masak,i,masak->Elmt[i].Dur);
            }
        }

        for(i=0;i<(saji->Jml);i++){
            if (saji->Elmt[i].Dur == 0){
                printf("Makanan M%d sudah busuk, harus dibuang.\n",saji->Elmt[i].Mid);
                diner_del(saji,saji->Elmt[i].Mid,saji->Elmt[i].Dur);
                

            }
        }
        printf("=======================================");      
    }
}
