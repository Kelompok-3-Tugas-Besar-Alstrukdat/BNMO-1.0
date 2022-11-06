#include "another_command.h"

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
    command.Elmt[3].Length = 11;
    char CMDCG[15] = "CREATE GAME";
    for (i = 0; i < 11; i++)
    {
        command.Elmt[3].TabWord[i] = CMDCG[i];
    }
    // LIST GAME
    command.Elmt[4].Length = 9;
    char CMDLG[15] = "LIST GAME";
    for (i = 0; i < 9; i++)
    {
        command.Elmt[4].TabWord[i] = CMDLG[i];
    }
    // DELETE GAME
    command.Elmt[5].Length = 11;
    char CMDDG[15] = "DELETE GAME";
    for (i = 0; i < 11; i++)
    {
        command.Elmt[5].TabWord[i] = CMDDG[i];
    }
    // QUEUE GAME
    command.Elmt[6].Length = 10;
    char CMDQG[15] = "QUEUE GAME";
    for (i = 0; i < 10; i++)
    {
        command.Elmt[6].TabWord[i] = CMDQG[i];
    }
    // PLAY GAME
    command.Elmt[7].Length = 9;
    char CMDPG[15] = "PLAY GAME";
    for (i = 0; i < 9; i++)
    {
        command.Elmt[7].TabWord[i] = CMDPG[i];
    }
    // SKIP GAME
    command.Elmt[8].Length = 9;
    char CMDSG[15] = "SKIP GAME";
    for (i = 0; i < 9; i++)
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
    int i = 0;
    boolean check = true;
    ArrayDin command = validCOMMAND();

    while ((check == true) && (i < 10))
    {
        if (!isWordEqual(Kata, command.Elmt[i]))
        {
            check = false;
        }
    }
    return check;
}
