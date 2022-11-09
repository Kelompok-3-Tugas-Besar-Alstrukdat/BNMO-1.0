#include <stdio.h>
#include "../boolean.h"
#include "../ADT/Array/arraydin.h"

ArrayDin validCOMMAND()
{
    ArrayDin command = MakeArrayDin();
    command.Neff = 11;
    int i;

    // START
    command.Elmt[0].Length = 5;
    char CMDSTART[15] = "START";
    for (i = 0; i < 5; i++)
    {
        command.Elmt[0].TabWord[i] = CMDSTART[i];
    }
    // LOAD
    command.Elmt[1].Length = 4;
    char CMDLOAD[15] = "LOAD";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[1].TabWord[i] = CMDLOAD[i];
    }
    // SAVE
    command.Elmt[2].Length = 4;
    char CMDSAVE[15] = "SAVE";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[2].TabWord[i] = CMDSAVE[i];
    }
    // CREATE GAME
    command.Elmt[3].Length = 10;
    char CMDCG[15] = "CREATEGAME";
    for (i = 0; i < 10; i++)
    {
        command.Elmt[3].TabWord[i] = CMDCG[i];
    }
    // LIST GAME
    command.Elmt[4].Length = 8;
    char CMDLG[15] = "LISTGAME";
    for (i = 0; i < 8; i++)
    {
        command.Elmt[4].TabWord[i] = CMDLG[i];
    }
    // DELETE GAME
    command.Elmt[5].Length = 10;
    char CMDDG[15] = "DELETEGAME";
    for (i = 0; i < 10; i++)
    {
        command.Elmt[5].TabWord[i] = CMDDG[i];
    }
    // QUEUE GAME
    command.Elmt[6].Length = 9;
    char CMDQG[15] = "QUEUEGAME";
    for (i = 0; i < 9; i++)
    {
        command.Elmt[6].TabWord[i] = CMDQG[i];
    }
    // PLAY GAME
    command.Elmt[7].Length = 8;
    char CMDPG[15] = "PLAYGAME";
    for (i = 0; i < 8; i++)
    {
        command.Elmt[7].TabWord[i] = CMDPG[i];
    }
    // SKIP GAME
    command.Elmt[8].Length = 8;
    char CMDSG[15] = "SKIPGAME";
    for (i = 0; i < 8; i++)
    {
        command.Elmt[8].TabWord[i] = CMDSG[i];
    }
    // QUIT
    command.Elmt[9].Length = 4;
    char CMDQUIT[15] = "QUIT";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[9].TabWord[i] = CMDQUIT[i];
    }
    // HELP
    command.Elmt[10].Length = 4;
    char CMDHELP[15] = "HELP";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[10].TabWord[i] = CMDHELP[i];
    }
    return command;
}

boolean isCOMMAND(Word Kata)
{
    // Memerika apakah Kata merupakan sebuah command atau bukan
    boolean check = false;
    ArrayDin command = MakeArrayDin();
    command.Neff = 11;
    int i;

    // START
    command.Elmt[0].Length = 5;
    char CMDSTART[15] = "START";
    for (i = 0; i < 5; i++)
    {
        command.Elmt[0].TabWord[i] = CMDSTART[i];
    }
    // LOAD
    command.Elmt[1].Length = 4;
    char CMDLOAD[15] = "LOAD";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[1].TabWord[i] = CMDLOAD[i];
    }
    // SAVE
    command.Elmt[2].Length = 4;
    char CMDSAVE[15] = "SAVE";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[2].TabWord[i] = CMDSAVE[i];
    }
    // CREATE GAME
    command.Elmt[3].Length = 10;
    char CMDCG[15] = "CREATEGAME";
    for (i = 0; i < 10; i++)
    {
        command.Elmt[3].TabWord[i] = CMDCG[i];
    }
    // LIST GAME
    command.Elmt[4].Length = 8;
    char CMDLG[15] = "LISTGAME";
    for (i = 0; i < 8; i++)
    {
        command.Elmt[4].TabWord[i] = CMDLG[i];
    }
    // DELETE GAME
    command.Elmt[5].Length = 10;
    char CMDDG[15] = "DELETEGAME";
    for (i = 0; i < 10; i++)
    {
        command.Elmt[5].TabWord[i] = CMDDG[i];
    }
    // QUEUE GAME
    command.Elmt[6].Length = 9;
    char CMDQG[15] = "QUEUEGAME";
    for (i = 0; i < 9; i++)
    {
        command.Elmt[6].TabWord[i] = CMDQG[i];
    }
    // PLAY GAME
    command.Elmt[7].Length = 8;
    char CMDPG[15] = "PLAYGAME";
    for (i = 0; i < 8; i++)
    {
        command.Elmt[7].TabWord[i] = CMDPG[i];
    }
    // SKIP GAME
    command.Elmt[8].Length = 8;
    char CMDSG[15] = "SKIPGAME";
    for (i = 0; i < 8; i++)
    {
        command.Elmt[8].TabWord[i] = CMDSG[i];
    }
    // QUIT
    command.Elmt[9].Length = 4;
    char CMDQUIT[15] = "QUIT";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[9].TabWord[i] = CMDQUIT[i];
    }
    // HELP
    command.Elmt[10].Length = 4;
    char CMDHELP[15] = "HELP";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[10].TabWord[i] = CMDHELP[i];
    }

    i = 0;
    while ((check == false) && (i < 11))
    {
        if (isWordEqual(Kata, command.Elmt[i]))
        {
            check = true;
        }
        i++;
    }
    return check;
}
