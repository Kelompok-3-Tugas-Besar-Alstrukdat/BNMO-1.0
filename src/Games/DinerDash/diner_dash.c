#include "diner_dash.h" //ternyata rng.h ilang//copas rng.c ke sini
#include "../../ADT/MesinKata/mesinkata.c"
#include "../../ADT/MesinKarakter/mesinkarakter.c"
#include "../../ADT/Array/arraydin.c"


int random(){
    time_t t;
    srand( (unsigned) time(&t) );
    return( rand() % 100 ) + 1;
}
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


void main(){

    Diner masak, saji, daftar;
    int saldo = 0,Count = 0, i = 0, daftarr = 3, num,awal = 0,x=0, idx = 0;
    char cmd;
    int antri_awal[10];
    for (i=0;i<10;i++){
        antri_awal[i] = -99;
    }

    create_empty(&masak);
    create_empty(&saji);
    create_empty(&daftar);

    system("cls");
    printf("Selamat Datang di Diner Dash Dash!\n\n");
    while ((daftarr < 7) && (Count < 15) ){ 
        printf("Saldo: %d\n\n", saldo);
        printf("Daftar Pesanan\n");
        printf("Makanan\t| Durasi Memasak\t| Ketahanan\t| Harga\n");
        printf("-----------------------------------------------------------\n");
        //Pengisian Komponen - komponen dalam tiap masakan
        random();
        for (i=0;i<daftarr;i++){  
            if (daftar.Elmt[i].Harga == -1){
                x = rand() % 40 + 10;
                daftar.Elmt[i].Harga = x*1000;
                x = rand()%4 + 1;
                daftar.Elmt[i].Dur = x;
                x = rand() % 4 + 1;
                daftar.Elmt[i].Tahan = x;
                daftar.Elmt[i].Mid = i;
                daftar.Jml += 1;
            }
        }
        //Menampilkan daftar pesanan
        for (i=0 ;i<(daftar.Jml);i++){       
            printf("M%d\t| %d\t\t\t| %d\t\t| %d\n", daftar.Elmt[i].Mid, daftar.Elmt[i].Dur, daftar.Elmt[i].Tahan, daftar.Elmt[i].Harga);
        }
        printf("\n");
        printf("Daftar Makanan yang sedang dimasak\n"); 
        printf("Makanan\t| Sisa durasi memasak\n");
        printf("-------------------------------------------\n");
        ////Menampilkan daftar masakan yang sedang dimasak
        if (masak.Jml > 0){
            for (i=0;i<(masak.Jml);i++){ 
                printf("M%d\t| %d\n", masak.Elmt[i].Mid, masak.Elmt[i].Tahan);
            }
        }
        else{
            printf("\t\t|\n"); 
        }
        printf("\n");
        printf("Daftar Makanan yang dapat disajikan\n");
        printf("Makanan\t| Sisa ketahanan makanan\n");
        printf("-------------------------------------------\n");
        //Menampilkan daftar makanan yang sudah bisa di-serve
        if (saji.Jml > 0){ 
            for (i=0;i<(saji.Jml);i++){
                printf("M%d\t| %d\n", saji.Elmt[i].Mid, saji.Elmt[i].Tahan);
            }      
        }
        else{
            printf("\t\t|\n");
        }
        
        //Memasukkan Command
        printf("MASUKKAN COMMAND: ");
        COMMAND();
        //Command COOK
        Word cmd;
        Word angka;
        

        i = 0;
        if (currentWord.Length == 4){
            for(i=0;i<4;i++){
            cmd.TabWord[i] = currentWord.TabWord[i];
            }
            cmd.Length = 4;
        }
        else{
            
            while(currentWord.TabWord[i] != ' '){
                cmd.TabWord[i] = currentWord.TabWord[i];
                i++;
            }

            cmd.Length = i;
            i++;
            int num;
            if (currentWord.TabWord[i] != 'M'){
                printf("ID makanan salah!\n");
            }
            else{
                idx = 0;
                i++;
                while(i<currentWord.Length){
                    angka.TabWord[idx] = currentWord.TabWord[i];
                    i++;
                    idx++;
                }
                angka.Length = idx;
                num = toInt(angka);
            }
        }
        char cmdc[5] = "COOK";
        char cmds[6] = "SERVE";
        char cmdsk[5] = "SKIP";

        ArrayDin cmd_c = MakeArrayDin();
        cmd_c.Neff = 3;
        for(i = 0; i<4; i++){
            cmd_c.Elmt[0].TabWord[i] = cmdc[i];
        }
        cmd_c.Elmt[0].Length = i;
        for(i = 0; i<5; i++){
            cmd_c.Elmt[1].TabWord[i] = cmds[i];
        }
        cmd_c.Elmt[1].Length = i;
        for(i = 0; i<4; i++){
            cmd_c.Elmt[2].TabWord[i] = cmdsk[i];
        }
        cmd_c.Elmt[2].Length = i;

        if ( isWordEqual(cmd,cmd_c.Elmt[0])){
            if(((num>=0) && (num<=6)) && ((masak.Jml) <= 5) && (num < (daftar.Jml))){ 
                printf("Berhasil memasak M%d\n",num);
                antri_awal[awal] = num;
                awal += 1;
                printf("=============================\n");
                    //ini kayak insert lah pokoknya, insert dari Q daftar ke Q masak.
                masak.Elmt[masak.Jml].Mid = daftar.Elmt[num].Mid;
                masak.Elmt[masak.Jml].Dur = daftar.Elmt[num].Dur;
                masak.Elmt[masak.Jml].Harga = daftar.Elmt[num].Harga;
                masak.Elmt[masak.Jml].Tahan = daftar.Elmt[num].Tahan;
                masak.Jml += 1;
                daftarr += 1; //daftar pesanan nanti bakal nambah 1

                    //Mengurangi semua durasi dan ketahanan makanan di daftar serve dan masak
                for (i = 0;i<(masak.Jml);i++){
                    masak.Elmt[i].Dur -= 1;
                }
                for (i = 0;i<(saji.Jml);i++){
                    saji.Elmt[i].Tahan -= 1;
                }
                printf("Berhasil memasak M%d.\n",num);
            }
            else{
                printf("Masakan belum masuk pesanan atau kompor sedang penuh, ulangi lagi!\n");
            }
                
        }
            //Command SERVE
        else if(isWordEqual(cmd,cmd_c.Elmt[1])){
                
            if((num>=0) && (num<=6)) {
                if((antri_awal[idx] == num) && (saji.Elmt[0].Mid == num))  {
                    saldo += saji.Elmt[0].Harga;
                    diner_del (&saji, num, saji.Elmt[num].Dur);
                    Count += 1;
                    daftarr+= 1;
                    idx += 1;
                        //Mengurangi semua durasi dan ketahanan makanan di daftar serve dan masak
                    for (i = 0;i<(masak.Jml);i++){
                        masak.Elmt[i].Dur -= 1;
                    }
                    for (i = 0;i<(saji.Jml);i++){
                        saji.Elmt[i].Tahan -= 1;
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
        else if (isWordEqual(cmd,cmd_c.Elmt[2])){
                //Mengurangi semua durasi dan ketahanan makanan di daftar serve dan masak
            for (i = 0;i<(masak.Jml);i++){
                masak.Elmt[i].Dur -= 1;
            }
            for (i = 0;i<(saji.Jml);i++){
                saji.Elmt[i].Tahan -= 1;
            }
            daftarr+= 1;
            printf("Berhasil SKIP!\n");
        }
        else{
            printf("Command tidak dikenali, input salah!\n");
        }

            //Cek apakah ada masakan yang sudah bisa pindah ke Serve dan apakah ada makanan di Serve yang sudah tidak layak
        for(i=0;i<(masak.Jml);i++){
            if (masak.Elmt[i].Dur == 0){
                printf("Berhasil memasak M%d.\n",masak.Elmt[i].Mid);
                masak.Elmt[i].Dur == daftar.Elmt[masak.Elmt[i].Mid].Dur;
                diner_ins (&saji,&masak,i);
                diner_del (&masak,i,masak.Elmt[i].Dur);
            }
        }

        for(i=0;i<(saji.Jml);i++){
            if (saji.Elmt[i].Dur == 0){
                printf("Makanan M%d sudah busuk, harus dibuang.\n",saji.Elmt[i].Mid);
                diner_del(&saji,saji.Elmt[i].Mid,saji.Elmt[i].Dur);
                    

            }
        }
        printf("=======================================\n");
    }
      
}

