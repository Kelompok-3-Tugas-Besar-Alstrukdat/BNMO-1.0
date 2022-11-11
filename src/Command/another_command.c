#include <stdio.h>
#include "../boolean.h"
#include "../ADT/Array/arraydin.h"
#include <time.h>

// Menyimpan Command-command yang valid ke dalam array command
ArrayDin validCOMMAND()
{
    ArrayDin command = MakeArrayDin();
    command.Neff = 11;
    int i;

    // START
    // Menyimpan perintah "START" ke dalam array command indeks 0
    command.Elmt[0].Length = 5;
    char CMDSTART[15] = "START";
    for (i = 0; i < 5; i++)
    {
        command.Elmt[0].TabWord[i] = CMDSTART[i];
    }

    // LOAD
    // Menyimpan perintah "LOAD" ke dalam array command indeks 1
    command.Elmt[1].Length = 4;
    char CMDLOAD[15] = "LOAD";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[1].TabWord[i] = CMDLOAD[i];
    }

    // SAVE
    // Menyimpan perintah "SAVE" ke dalam array command indeks 2
    command.Elmt[2].Length = 4;
    char CMDSAVE[15] = "SAVE";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[2].TabWord[i] = CMDSAVE[i];
    }

    // CREATE GAME
    // Menyimpan perintah "CREATE GAME" ke dalam array command indeks 3
    command.Elmt[3].Length = 11;
    char CMDCG[15] = "CREATE GAME";
    for (i = 0; i < 11; i++)
    {
        command.Elmt[3].TabWord[i] = CMDCG[i];
    }

    // LIST GAME
    // Menyimpan perintah "LIST GAME" ke dalam array command indeks 4
    command.Elmt[4].Length = 9;
    char CMDLG[15] = "LIST GAME";
    for (i = 0; i < 9; i++)
    {
        command.Elmt[4].TabWord[i] = CMDLG[i];
    }

    // DELETE GAME
    // Menyimpan perintah "DELETE GAME" ke dalam array command indeks 5
    command.Elmt[5].Length = 11;
    char CMDDG[15] = "DELETE GAME";
    for (i = 0; i < 11; i++)
    {
        command.Elmt[5].TabWord[i] = CMDDG[i];
    }

    // QUEUE GAME
    // Menyimpan perintah "QUEUE GAME" ke dalam array command indeks 6
    command.Elmt[6].Length = 10;
    char CMDQG[15] = "QUEUE GAME";
    for (i = 0; i < 10; i++)
    {
        command.Elmt[6].TabWord[i] = CMDQG[i];
    }

    // PLAY GAME
    // Menyimpan perintah "PLAY GAME" ke dalam array command indeks 7
    command.Elmt[7].Length = 9;
    char CMDPG[15] = "PLAY GAME";
    for (i = 0; i < 9; i++)
    {
        command.Elmt[7].TabWord[i] = CMDPG[i];
    }

    // SKIPGAME
    // Menyimpan perintah "SKIPGAME" ke dalam array command indeks 8
    command.Elmt[8].Length = 8;
    char CMDSG[15] = "SKIPGAME";
    for (i = 0; i < 8; i++)
    {
        command.Elmt[8].TabWord[i] = CMDSG[i];
    }

    // QUIT
    // Menyimpan perintah "QUIT" ke dalam array command indeks 9
    command.Elmt[9].Length = 4;
    char CMDQUIT[15] = "QUIT";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[9].TabWord[i] = CMDQUIT[i];
    }

    // HELP
    // Menyimpan perintah "HELP" ke dalam array command indeks 10
    command.Elmt[10].Length = 4;
    char CMDHELP[15] = "HELP";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[10].TabWord[i] = CMDHELP[i];
    }
    return command;
}

// Memeriksa apakah Kata merupakan sebuah perintah yang valid atau bukan
boolean isCOMMAND(Word Kata)
{
    boolean check = false;
    ArrayDin command = MakeArrayDin();
    command.Neff = 11;
    int i;

    // START
    // Menyimpan perintah "START" ke dalam array command indeks 0
    command.Elmt[0].Length = 5;
    char CMDSTART[15] = "START";
    for (i = 0; i < 5; i++)
    {
        command.Elmt[0].TabWord[i] = CMDSTART[i];
    }

    // LOAD
    // Menyimpan perintah "LOAD" ke dalam array command indeks 1
    command.Elmt[1].Length = 4;
    char CMDLOAD[15] = "LOAD";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[1].TabWord[i] = CMDLOAD[i];
    }

    // SAVE
    // Menyimpan perintah "SAVE" ke dalam array command indeks 2
    command.Elmt[2].Length = 4;
    char CMDSAVE[15] = "SAVE";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[2].TabWord[i] = CMDSAVE[i];
    }

    // CREATE GAME
    // Menyimpan perintah "CREATE GAME" ke dalam array command indeks 3
    command.Elmt[3].Length = 11;
    char CMDCG[15] = "CREATE GAME";
    for (i = 0; i < 11; i++)
    {
        command.Elmt[3].TabWord[i] = CMDCG[i];
    }

    // LIST GAME
    // Menyimpan perintah "LIST GAME" ke dalam array command indeks 4
    command.Elmt[4].Length = 9;
    char CMDLG[15] = "LIST GAME";
    for (i = 0; i < 9; i++)
    {
        command.Elmt[4].TabWord[i] = CMDLG[i];
    }

    // DELETE GAME
    // Menyimpan perintah "DELETE GAME" ke dalam array command indeks 5
    command.Elmt[5].Length = 11;
    char CMDDG[15] = "DELETE GAME";
    for (i = 0; i < 11; i++)
    {
        command.Elmt[5].TabWord[i] = CMDDG[i];
    }

    // QUEUE GAME
    // Menyimpan perintah "QUEUE GAME" ke dalam array command indeks 6
    command.Elmt[6].Length = 10;
    char CMDQG[15] = "QUEUE GAME";
    for (i = 0; i < 10; i++)
    {
        command.Elmt[6].TabWord[i] = CMDQG[i];
    }

    // PLAY GAME
    // Menyimpan perintah "PLAY GAME" ke dalam array command indeks 7
    command.Elmt[7].Length = 9;
    char CMDPG[15] = "PLAY GAME";
    for (i = 0; i < 9; i++)
    {
        command.Elmt[7].TabWord[i] = CMDPG[i];
    }

    // SKIPGAME
    // Menyimpan perintah "SKIPGAME" ke dalam array command indeks 8
    command.Elmt[8].Length = 8;
    char CMDSG[15] = "SKIPGAME";
    for (i = 0; i < 8; i++)
    {
        command.Elmt[8].TabWord[i] = CMDSG[i];
    }

    // QUIT
    // Menyimpan perintah "QUIT" ke dalam array command indeks 9
    command.Elmt[9].Length = 4;
    char CMDQUIT[15] = "QUIT";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[9].TabWord[i] = CMDQUIT[i];
    }

    // HELP
    // Menyimpan perintah "HELP" ke dalam array command indeks 10
    command.Elmt[10].Length = 4;
    char CMDHELP[15] = "HELP";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[10].TabWord[i] = CMDHELP[i];
    }

    // Memeriksa apakah Kata merupakan sebuah perintah atau bukan
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

//Menghasilkan waktu hitung mundur dengan menampilkan "."
void countdown(){
    int check;
    time_t start_t, end_t;
    float diff_t;
    check = 0;
        time(&start_t);
        time(&end_t);
        
        diff_t = difftime(end_t, start_t);
        while (diff_t != 4){
            time(&end_t);
            diff_t = (float) difftime(end_t, start_t);
            
            if ((diff_t == 1 ) && (check != -1) && (check != -2) && (check != -99)) {
                printf(".");
                check = -1;
            }
            if ((diff_t == 2 ) && (check == -1)) {
                printf(".");
                check = -2;
            }
            if ((diff_t == 3 ) && (check == -2)) {
                printf(".");
                check = -99;
            }
        }
}
