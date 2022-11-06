//--------------------------------------------------------------- C LIBRARY ---------------------------------------------------------------//
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------ FILE HEADER ADT ------------------------------------------------------------//
#include "src/ADT/Array/arraydin.h"
#include "src/ADT/MesinKarakter/mesinkarakter.h"
#include "src/ADT/MesinKata/mesinkata.h"
#include "src/ADT/Queue/queue.h"

//--------------------------------------------------- FILE HEADER FUNCTION FOR COMMAND ----------------------------------------------------//
#include "src/Command/start.h"
#include "src/Command/load.h"
#include "src/Command/creategame.h"
#include "src/Command/listgame.h"
#include "src/Command/deletegame.h"
#include "src/Command/queuegame.h"
#include "src/Command/playgame.h"
#include "src/Command/skipgame.h"
#include "src/Command/quit.h"
#include "src/Command/help.h"
#include "src/Command/another_command.h"

void main()
{
    printf("ENTER COMMAND (START/LOAD): ");
    COMMAND();
    Word INPUT;
    ArrayDin Game;
    if (isWordEqual(currentWord,validCOMMAND().Elmt[0]))
    {
        INPUT = currentWord;
    }
    else
    {
        int i;
        for (i = 0; i < 4; i++)
        {
            INPUT.TabWord[i] = currentWord.TabWord[i];
        }
        INPUT.Length = i;
    }
    while ((!isWordEqual(INPUT,validCOMMAND().Elmt[0])) && (!isWordEqual(INPUT,validCOMMAND().Elmt[1])))
    {
        ADVCMD();
        INPUT = currentWord;
    }
    if (!isWordEqual(INPUT,validCOMMAND().Elmt[0]))
    {
        Game = STARTGAME();
    }
    else
    {
        char filename[50];
        int j = 0;
        for (int i = INPUT.Length; i < currentWord.Length; i++)
        {
            if (currentWord.TabWord[i] != ' ')
            {
                filename[j] = currentWord.TabWord[i];
                j++;
            }
        }
        Game = LOADGAME(filename);
    }
    while (!isWordEqual(INPUT,validCOMMAND().Elmt[8]))
    {
        ADVCMD();
        INPUT = currentWord;

        if (isCOMMAND(INPUT))
        {
            if ((isWordEqual(INPUT, validCOMMAND().Elmt[0])) || (isWordEqual(INPUT, validCOMMAND().Elmt[1])))
            {
                printf('BNMO sudah dijalankan.');
            }
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[2])))
            {

            }
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[3])))
            {

            }
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[4])))
            {

            }
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[5])))
            {

            }
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[6])))
            {

            }
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[7])))
            {

            }
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[8])))
            {
                
            }
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[9])))
            {
                printf("Anda keluar dari game BNMO.\nBye bye ...\n");
            }
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[9])))
            {

            }
        }
        else
        {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.");
        }
    }
}