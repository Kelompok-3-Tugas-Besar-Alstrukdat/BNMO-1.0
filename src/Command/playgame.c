#include <stdio.h>
#include "../boolean.h"
#include "../Games/DinerDash/diner_dash.c"
#include "../Games/RNG/rng.c"
#include "../Games/MagicShell/MagicShell.c"

void PlayGame (Queue *q){
    ArrayDin game = MakeArrayDin();
    game.Neff = 8;
    int i;

    // RNG
    game.Elmt[0].Length = 3;
    char GMRNG[20] = "RNG";
    for (i = 0; i < 3; i++)
    {
        game.Elmt[0].TabWord[i] = GMRNG[i];
    }
    // DINER DASH
    game.Elmt[1].Length = 10;
    char GMDD[20] = "DINER DASH";
    for (i = 0; i < 10; i++)
    {
        game.Elmt[1].TabWord[i] = GMDD[i];
    }
    // DINOSAUR IN EARTH
    game.Elmt[2].Length = 17;
    char GMDIE[20] = "DINOSAUR IN EARTH";
    for (i = 0; i < 17; i++)
    {
        game.Elmt[2].TabWord[i] = GMDIE[i];
    }
    // RISEWOMAN
    game.Elmt[3].Length = 9;
    char GMRW[20] = "RISEWOMAN";
    for (i = 0; i < 9; i++)
    {
        game.Elmt[3].TabWord[i] = GMRW[i];
    }
    // EIFFEL TOWER
    game.Elmt[4].Length = 12;
    char GMET[20] = "EIFFEL TOWER";
    for (i = 0; i < 12; i++)
    {
        game.Elmt[4].TabWord[i] = GMET[i];
    }
    // HIDE IN CARTESIAN
    game.Elmt[5].Length = 17;
    char GMHIC[20] = "HIDE IN CARTESIAN";
    for (i = 0; i < 17; i++)
    {
        game.Elmt[5].TabWord[i] = GMHIC[i];
    }
    // NUZZLE
    game.Elmt[6].Length = 6;
    char GMNZ[20] = "NUZZLE";
    for (i = 0; i < 6; i++)
    {
        game.Elmt[6].TabWord[i] = GMNZ[i];
    }
    // MAGIC SHELL
    game.Elmt[7].Length = 11;
    char GMMS[20] = "MAGIC SHELL";
    for (i = 0; i < 11; i++)
    {
        game.Elmt[7].TabWord[i] = GMMS[i];
    }

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
            runDinerDash();
        }
        else if (isWordEqual(HEAD(*q), game.Elmt[6])){
            runDinerDash();
        }
        else if (isWordEqual(HEAD(*q), game.Elmt[7])){
            magic_shell();
        }
        else {
            printf("Skor Anda : %d\n", RandomNumber());
        }
        QueueType val;
        dequeueQ(q, &val);
    }
}
