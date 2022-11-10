void PLAYGAME (queue *game){
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
    char GMDINERDASH[15] = "Diner Dash";
    for (i = 0; i < 10; i++)
    {
        game.Elmt[1].TabWord[i] = GMDINERDASH[i];
    }

    if (!isEmpty(game)){
        if (isWordEqual(HEAD(q), game.Elmt[0])){
            runRNG();
        }
        else if (isWordEqual(HEAD(q), game.Elmt[1])){
            diner_dash();
        }
        else {
            printf("Skor Anda : ");
            randomNumber();
        }
        dequeue(*game, *HEAD(q));
        }
    else{
        printf("Antrian game Anda kosong. \n");
    }
}
