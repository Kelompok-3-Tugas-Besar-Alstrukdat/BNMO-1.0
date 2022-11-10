int RandomNumber2()
{
    srand(time(0));
    int num = (rand() % 6); // Diperoleh dari num = (rand() % (100 - 0 + 1)) + 0
    return num;
}

void magic_shell(){
    ArrayDin magshell = MakeArrayDin();
    magshell.Neff = 5;
    int i;

    // Ya
    magshell.Elmt[0].Length = 2;
    char MSYA[30] = "Ya";
    for (i = 0; i < 2; i++)
    {
        magshell.Elmt[0].TabWord[i] = MSYA[i];
    }
    // Tidak
    magshell.Elmt[1].Length = 5;
    char MSTIDAK[30] = "Tidak";
    for (i = 0; i < 5; i++)
    {
        magshell.Elmt[1].TabWord[i] = MSTIDAK[i];
    }
    // Kamu nanyeaaa?
    magshell.Elmt[2].Length = 13;
    char MSKMNY[30] = "Kamu nanyeaaa?";
    for (i = 0; i < 13; i++)
    {
        magshell.Elmt[2].TabWord[i] = MSKMNY[i];
    }
    // Cape ah ditanyain mulu...
    magshell.Elmt[3].Length = 25;
    char MSCAPE[30] = "Cape ah ditanyain mulu...";
    for (i = 0; i < 25; i++)
    {
        magshell.Elmt[3].TabWord[i] = MSCAPE[i];
    }
    // Bisa jadi
    magshell.Elmt[4].Length = 9;
    char MSBSJD[30] = "Bisa jadi";
    for (i = 0; i < 9; i++)
    {
        magshell.Elmt[4].TabWord[i] = MSBSJD[i];
    }

    printf("Kerang Ajaib telah dimulai. blablabla");
    scanf("%d", &question);

    char answer = RandomNumber2();
    if (answer == magshell.Elmt[i]){
        printf(magshell.Elmt[i]);
    }
}
