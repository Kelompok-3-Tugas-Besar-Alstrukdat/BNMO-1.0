#include <stdio.h>
#include "../boolean.h"
#include "../Games/DinerDash/diner_dash.c"
#include "../Games/RNG/rng.c"
#include "../Games/MagicShell/magic_shell.c"
#include "../Games/HideInCartesian/hide_in_cartesian.c"

//Menjalankan permainan sesuai antrian permainan
void PlayGame (Queue *q){
    ArrayDin game = MakeArrayDin();
    game.Neff = 7;
    int i;

    // RNG
    // Menyimpan nama permainan "RNG" ke dalam array game indeks 0
    game.Elmt[0].Length = 3;
    char GMRNG[20] = "RNG";
    for (i = 0; i < 3; i++)
    {
        game.Elmt[0].TabWord[i] = GMRNG[i];
    }
    // DINER DASH
    // Menyimpan nama permainan "DINER DASH" ke dalam array game indeks 1
    game.Elmt[1].Length = 10;
    char GMDD[20] = "DINER DASH";
    for (i = 0; i < 10; i++)
    {
        game.Elmt[1].TabWord[i] = GMDD[i];
    }
    // DINOSAUR IN EARTH
    // Menyimpan nama permainan "DINOSAUR IN EARTH" ke dalam array game indeks 2
    game.Elmt[2].Length = 17;
    char GMDIE[20] = "DINOSAUR IN EARTH";
    for (i = 0; i < 17; i++)
    {
        game.Elmt[2].TabWord[i] = GMDIE[i];
    }
    // RISEWOMAN
    // Menyimpan nama permainan "RISEWOMAN" ke dalam array game indeks 3
    game.Elmt[3].Length = 9;
    char GMRW[20] = "RISEWOMAN";
    for (i = 0; i < 9; i++)
    {
        game.Elmt[3].TabWord[i] = GMRW[i];
    }
    // EIFFEL TOWER
    // Menyimpan nama permainan "EIFFEL TOWER" ke dalam array game indeks 4
    game.Elmt[4].Length = 12;
    char GMET[20] = "EIFFEL TOWER";
    for (i = 0; i < 12; i++)
    {
        game.Elmt[4].TabWord[i] = GMET[i];
    }
    // HIDE IN CARTESIAN
    // Menyimpan nama permainan "HIDE IN CARTESIAN" ke dalam array game indeks 5
    game.Elmt[5].Length = 17;
    char GMHIC[20] = "HIDE IN CARTESIAN";
    for (i = 0; i < 17; i++)
    {
        game.Elmt[5].TabWord[i] = GMHIC[i];
    }
    // MAGIC SHELL
    // Menyimpan nama permainan "MAGIC SHELL" ke dalam array game indeks 6
    game.Elmt[6].Length = 11;
    char GMMS[20] = "MAGIC SHELL";
    for (i = 0; i < 11; i++)
    {
        game.Elmt[6].TabWord[i] = GMMS[i];
    }

    //Menjalankan permainan sesuai antrian permainan
    if (!isEmptyQueue(*q)){
        if (isWordEqual(HEAD(*q), game.Elmt[0])){
            runRNG();
        }
        else if (isWordEqual(HEAD(*q), game.Elmt[1])){
            runDinerDash();
        }
        else if (isWordEqual(HEAD(*q), game.Elmt[2])){
            printf("Permainan sedang dalam perbaikan.\n");
        }
        else if (isWordEqual(HEAD(*q), game.Elmt[3])){
            printf("Permainan sedang dalam perbaikan.\n");
        }
        else if (isWordEqual(HEAD(*q), game.Elmt[4])){
            printf("Permainan sedang dalam perbaikan.\n");
        }
        else if (isWordEqual(HEAD(*q), game.Elmt[5])){
            runHideInCartesian();
        }
        else if (isWordEqual(HEAD(*q), game.Elmt[6])){
            magic_shell();
        }
        else {
            printf("Skor Anda : %d\n", RandomNumber());
        }
        QueueType val;
        dequeueQ(q, &val);
    }