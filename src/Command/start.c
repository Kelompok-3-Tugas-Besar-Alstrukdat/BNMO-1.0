#include "start.h"

ArrayDin STARTGAME()
{
    ArrayDin Game = MakeArrayDin();
    int i = 0;
    STARTWORD("configurasi.txt");
    Game.Neff = toInt(currentWord);
    ADVWORD();
    while (!EndWord)
    {
        Game.Elmt[i].Length = currentWord.Length;
        for (int j = 0; j < currentWord.Length; j++)
        {
            Game.Elmt[i].TabWord[j] = currentWord.TabWord[j];
        }
    }
    return Game;
}