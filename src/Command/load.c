#include "load.h"

ArrayDin LOADGAME(char *filename)
{
    ArrayDin Game = MakeArrayDin();
    int i = 0;
    STARTWORD(filename);
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