#include <stdio.h>
#include "../boolean.h"
#include "../Games/DinerDash/diner_dash.c"
#include "../Games/RNG/rng.c"

void PlayGame (Queue *q){
    ArrayDin game = MakeArrayDin();
    game.Neff = 2;
    int i;

    // RNG
    game.Elmt[0].Length = 3;
    char GMRNG[15] = "RNG";
    for (i = 0; i < 3; i++)
    {
        game.Elmt[0].TabWord[i] = GMRNG[i];
    }
    // Diner Dash
    game.Elmt[1].Length = 10;
    char GMDINERDASH[15] = "DINER DASH";
    for (i = 0; i < 10; i++)
    {
        game.Elmt[1].TabWord[i] = GMDINERDASH[i];
    }

    if (!isEmptyQueue(*q)){
        if (isWordEqual(HEAD(*q), game.Elmt[0])){
            runRNG();
        }
        else if (isWordEqual(HEAD(*q), game.Elmt[1])){
            runDinerDash();
        }
        else {
            printf("Skor Anda : %d\n", RandomNumber());
        }
        QueueType val;
        dequeueQ(q, &val);
    }
    else{
        printf("Antrian game Anda kosong. Silahkan tambahkan game terlebih dahulu\n");
    }
}
