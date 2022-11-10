#include "arraydin.c"
#include "../MesinKarakter/mesinkarakter.c"
#include "../MesinKata/mesinkata.c"
#include "../../Command/another_command.c"
int main()
{
    //Deklarasi Variabel
    ArrayDin array1,array2;
    ElType el1,el2,el3,el4,el5;
    char kata1[7] = "WILDHAN";
    char kata2[4] = "REZA";
    char kata3[6] = "NABILA";
    char kata4[4] = "NISA";
    char kata5[5] = "VASYA";

    //Insert isi array oleh array char di atas
    for(int i = 0; i < 7; i++)
    {
        el1.TabWord[i] = kata1[i];
    }
    el1.Length = 7;
    for(int i = 0; i < 4; i++)
    {
        el2.TabWord[i] = kata2[i];
    }
    el2.Length = 4;
    for(int i = 0; i < 6; i++)
    {
        el3.TabWord[i] = kata3[i];
    }
    el3.Length = 6;
    for(int i = 0; i < 4; i++)
    {
        el4.TabWord[i] = kata4[i];
    }
    el4.Length = 4;
    for(int i = 0; i < 5; i++)
    {
        el5.TabWord[i] = kata5[i];
    }
    el5.Length = 5;

    array1 = MakeArrayDin();
    array2 = MakeArrayDin();

    //Penggunaan isEmpty
    if (IsEmpty(array1))
    {
        printf("Array1 ini kosong loh ! \n");
    }

    //Menambahkan Elemen ke array1 dan array2
    InsertLast(&array1, el1);
    InsertLast(&array1, el2);
    InsertLast(&array1,el3);
    InsertLast(&array2, el4);
    InsertLast(&array2, el5);

    //Mem-print panjang array1 dan array2
    printf("Ini banyak isi array 1 : %d, kalau ini banyak isi array2 : %d \n",Length(array1), Length(array2));
    
    //Mem-print elemen ke 2 dari array1 dan array2 menggunakan Get
    printWord( Get(array1,1) );
    printf("Di atas tuh, isi Elemen ke - 2 dari array 1\n");
    printWord( Get(array2,1) );
    printf("Di atas tuh, isi Elemen ke - 2 dari array 2.\n");

    //Meng-update elemen menggunakan Set
    Set(&array1, el5, 1);
    printf("Update nilai array1 indeks ke 2\n");
    countdown();
    printWord( Get(array1,1) );
    printf("Nahh sekarang, isi array1 indeks 2 jadi ituu\n");

    //Melihat kapasistas array
    printf("Ini adalah kapasistas dari array1; %d.\n",GetCapacity(array1));

    //Men-Delete Element di indeks ke i
    printWord( Get(array1, Length(array1)-1) );
    printf("Ini isi elemen array1 indeks terakhir sebelum di delete\n");
    DeleteAt( &array1 , Length(array1) - 1 );
    printWord( Get(array1,Length(array1) - 1 ));
    printf("Ini isi elemen array1 indeks terakhir setelah di delete\n");

    //Deallocate
    printf("Mau di dealocate nihh\n Dealocate");
    countdown();
    DeallocateArrayDin(&array1);
    DeallocateArrayDin(&array2);
    printf("Berhasil Deallocate!\n");
}