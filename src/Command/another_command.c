#include "another_command.h"

ArrayDin validCOMMAND()
{
    ArrayDin command = MakeArrayDin();
    command.Neff = 11;
    char tempCMD[20];
    int i;

    // START
    command.Elmt[0].Length = 5;
    tempCMD[20] = "START";
    for (i = 0; i < 5; i++)
    {
        command.Elmt[0].TabWord[i] = tempCMD[i];
    }
    // LOAD
    command.Elmt[1].Length = 4;
    tempCMD[20] = "LOAD";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[1].TabWord[i] = tempCMD[i];
    }
    // SAVE
    command.Elmt[2].Length = 4;
    tempCMD[20] = "SAVE";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[2].TabWord[i] = tempCMD[i];
    }
    // CREATE GAME
    command.Elmt[3].Length = 11;
    tempCMD[20] = "CREATE GAME";
    for (i = 0; i < 11; i++)
    {
        command.Elmt[3].TabWord[i] = tempCMD[i];
    }
    // LIST GAME
    command.Elmt[4].Length = 9;
    tempCMD[20] = "LIST GAME";
    for (i = 0; i < 9; i++)
    {
        command.Elmt[4].TabWord[i] = tempCMD[i];
    }
    // DELETE GAME
    command.Elmt[5].Length = 11;
    tempCMD[20] = "DELETE GAME";
    for (i = 0; i < 11; i++)
    {
        command.Elmt[5].TabWord[i] = tempCMD[i];
    }
    // QUEUE GAME
    command.Elmt[6].Length = 10;
    tempCMD[20] = "QUEUE GAME";
    for (i = 0; i < 10; i++)
    {
        command.Elmt[6].TabWord[i] = tempCMD[i];
    }
    // PLAY GAME
    command.Elmt[7].Length = 9;
    tempCMD[20] = "PLAY GAME";
    for (i = 0; i < 9; i++)
    {
        command.Elmt[7].TabWord[i] = tempCMD[i];
    }
    // SKIP GAME
    command.Elmt[8].Length = 9;
    tempCMD[20] = "SKIP GAME";
    for (i = 0; i < 9; i++)
    {
        command.Elmt[8].TabWord[i] = tempCMD[i];
    }
    // QUIT
    command.Elmt[9].Length = 4;
    tempCMD[20] = "QUIT";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[9].TabWord[i] = tempCMD[i];
    }
    // HELP
    command.Elmt[10].Length = 4;
    tempCMD[20] = "HELP";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[10].TabWord[i] = tempCMD[i];
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
