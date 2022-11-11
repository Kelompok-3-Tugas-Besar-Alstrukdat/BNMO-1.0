//--------------------------------------------------------------- C LIBRARY ---------------------------------------------------------------//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//------------------------------------------------------------ FILE HEADER ADT ------------------------------------------------------------//
#include "src/ADT/Array/arraydin.c"
#include "src/ADT/MesinKarakter/mesinkarakter.c"
#include "src/ADT/MesinKata/mesinkata.c"
#include "src/ADT/Queue/queue.c"

//--------------------------------------------------- FILE HEADER FUNCTION FOR COMMAND ----------------------------------------------------//
#include "src/Command/save.c"
#include "src/Command/creategame.c"
#include "src/Command/deletegame.c"
#include "src/Command/queuegame.c"
#include "src/Command/playgame.c"
#include "src/Command/skipgame.c"
#include "src/Command/help.c"
#include "src/Command/another_command.c"
#include "BNMO_display.c"

void fetchBNMO(Word *INPUT)
{
    do
    {
        printf("MASUKKAN COMMAND: ");
        COMMAND();
        int i;
        for (i = 0; i < currentWord.Length; i++)
        {
            (*INPUT).TabWord[i] = currentWord.TabWord[i];
        }
        (*INPUT).Length = currentWord.Length;

        if (!isWordEqual((*INPUT),validCOMMAND().Elmt[0]))
        {
            i = 0;
            while ((currentWord.TabWord[i] != ' ') && (i < currentWord.Length))
            {
            (*INPUT).TabWord[i] = currentWord.TabWord[i];
                i++;
            }
            (*INPUT).Length = i;

            if (isWordEqual((*INPUT),validCOMMAND().Elmt[0]))
            {
                (*INPUT).Length = 0;
            }
        }
        if (!isCOMMAND(*INPUT))
        {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }
        else
        {
            if (isWordEqual((*INPUT),validCOMMAND().Elmt[10]))
            {
                Help();
            }
            else
            {
                if (!isWordEqual((*INPUT),validCOMMAND().Elmt[0]) && !isWordEqual((*INPUT),validCOMMAND().Elmt[1]))
                {
                    printf("Masukkan command START atau LOAD <namafile>.txt untuk menjalan BNMO.\n");
                }
            }
        }
    }
    while (!isWordEqual((*INPUT),validCOMMAND().Elmt[0]) && !isWordEqual((*INPUT),validCOMMAND().Elmt[1]));
}

void backToMainPage()
{
    printf("\n\n\n\n\nK E M B A L I  K E  H A L A M A N  U T A M A ");
    countdown();
    system("cls");
}

void changePage()
{
    printf("\n\n\n\n\nM O H O N  T U N G G U ");
    countdown();
    system("cls");
    printf("==================================| B N M O |==================================\n");
}

void loadGame(Word game)
{
    printf("\n\n\n\n\nS E D A N G  M E M U A T  ");
    for (int i = 0; i < game.Length; i++)
    {
        printf("%c ", game.TabWord[i]);
    }
    countdown();
    system("cls");
    printf("==================================| B N M O |==================================\n");
}

void main()
{
    Word INPUT;
    ArrayDin Game = MakeArrayDin();
    Queue GameQ;
    CreateQueue(&GameQ);
    char filename[50] = "docs/";

    display();
    printf("====================================| B N M O |====================================\n");
    printf("Masukkan command START atau LOAD <namafile>.txt untuk menjalan BNMO.\n");
    fetchBNMO(&INPUT);
    if (isWordEqual(INPUT,validCOMMAND().Elmt[0]))
    {
        int i = 0;
        STARTWORD("docs/config.txt");
        while (!EndWord)
        {
            Game.Elmt[i].Length = currentWord.Length;
            for (int j = 0; j < currentWord.Length; j++)
            {
                Game.Elmt[i].TabWord[j] = currentWord.TabWord[j];
            }
            ADVWORD();
            i++;
        }
        Game.Neff = i;
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
    else
    {
        boolean success = false;
        do
        {
            int j = 5;
            for (int i = INPUT.Length; i < currentWord.Length; i++)
            {
                if (currentWord.TabWord[i] != ' ')
                {
                    filename[j] = currentWord.TabWord[i];
                    j++;
                }
            }
            filename[j] = '\0';

            FILE *test;
            test = fopen(filename, "r");
            if (test != NULL)
            {
                fclose(test);
                int i = 0;
                STARTWORD(filename);
                while (!EndWord)
                {
                    Game.Elmt[i].Length = currentWord.Length;
                    for (int j = 0; j < currentWord.Length; j++)
                    {
                        Game.Elmt[i].TabWord[j] = currentWord.TabWord[j];
                    }
                    ADVWORD();
                    i++;
                }
                Game.Neff = i;
                success = true;
                printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");

                filename[0] = 'd';
                filename[1] = 'o';
                filename[2] = 'c';
                filename[3] = 's';
                filename[4] = '/';
                filename[5] = '\0';
            }
            else
            {
                fclose(test);
                printf("Nama file yang Anda masukkan salah. Periksa kembali dan pastikan nama file benar.\n");
                fetchBNMO(&INPUT);
            }
        }
        while (success == false);
    }

    printf("\n\n\n\n\nM O H O N  T U N G G U ");
    countdown();
    system("cls");

    while (!isWordEqual(INPUT,validCOMMAND().Elmt[9]))
    {
        printf("==================================| B N M O |==================================\n");
        printf("MASUKKAN COMMAND: ");
        COMMAND();
        for (int i = 0; i < currentWord.Length; i++)
        {
            INPUT.TabWord[i] = currentWord.TabWord[i];
        }
        INPUT.Length = currentWord.Length;
        
        if (!isCOMMAND(INPUT))
        {
            int i = 0;
            while ((currentWord.TabWord[i] != ' ') && (i < currentWord.Length))
            {
                INPUT.TabWord[i] = currentWord.TabWord[i];
                i++;
            }
            INPUT.Length = i;

            int j = 5;
            for (int i = INPUT.Length; i < currentWord.Length; i++)
            {
                if (currentWord.TabWord[i] != ' ')
                {
                    filename[j] = currentWord.TabWord[i];
                    j++;
                }
            }
            filename[j] = '\0';

            if (!isWordEqual(INPUT, validCOMMAND().Elmt[2]) && !isWordEqual(INPUT, validCOMMAND().Elmt[8]))
            {
                INPUT.Length = 0;
            }
        }

        if (isCOMMAND(INPUT))
        {
            // INPUT == START atau INPUT == LOAD
            if ((isWordEqual(INPUT, validCOMMAND().Elmt[0])) || (isWordEqual(INPUT, validCOMMAND().Elmt[1])))
            {
                changePage();
                printf("BNMO sudah dijalankan.\n");
                backToMainPage();
            }
            // INPUT == SAVE
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[2])))
            {
                changePage();
                if (validExtension(filename))
                {
                    Save(Game, filename);
                    printf("Save file berhasil disimpan.\n");
                }
                else
                {
                    printf("Harap periksa kembali extension file Anda.\nFormat save: SAVE <namafile>.txt\n");
                }
                backToMainPage();
            }
            // INPUT == CREATEGAME
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[3])))
            {
                changePage();
                Create(&Game);
                backToMainPage();
            }
            // INPUT == LISTGAME
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[4])))
            {
                changePage();
                printf("Berikut adalah daftar permainan yang tersedia.\n");
                for (int i = 1; i < Game.Neff; i++)
                {
                    printf("%d. ", i);
                    printWord(Game.Elmt[i]);
                }
            }
            // INPUT == DELETEGAME
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[5])))
            {
                changePage();
                DeleteGame(&Game, &GameQ);
                backToMainPage();
            }
            // INPUT == QUEUEGAME
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[6])))
            {
                changePage();
                QueueGame(&Game, &GameQ);
                backToMainPage();
            }
            // INPUT == PLAYGAME
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[7])))
            {
                if (isEmptyQueue(GameQ))
                {
                    changePage();
                    printf("Daftar antrian Anda kosong. Silahkan tambahkan permainan terlebih dahulu.\n");
                }
                else
                {
                    loadGame(HEAD(GameQ));
                    PlayGame(&GameQ);
                }
                backToMainPage();
            }
            // INPUT == SKIPGAME
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[8])))
            {
                changePage();
                int idx = 5, n = 0;
                while (filename[idx] != '\0')
                {
                    idx++;
                }
                for (int tidx = (idx - 6); tidx >= 0; tidx--)
                {
                    n += ((filename[tidx] - '0') * pow(10, tidx));
                }
                if (n > 0)
                {
                    SkipGame(&GameQ, n);
                    if (isEmptyQueue(GameQ))
                    {
                        printf("Tidak ada permainan lagi dalam daftar antrian.\n");
                    }
                }
                else
                {
                    printf("Parameter skip tidak valid.\nTIPS: Parameter harus lebih besar dari nol\n");
                }
                backToMainPage();
            }
            // INPUT == QUIT
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[9])))
            {
                system("cls");
                printf("==================================| B N M O |==================================\n");
                printf("           ^_^ T E R I M A  K A S I H  T E L A H  B E R M A I N ^_^\n");
                printf("                              B Y E  B Y E ");
                countdown();
                system("cls");
            }
            // INPUT == HELP
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[10])))
            {
                changePage();
                Help();
            }
        }
        else
        {
            changePage();
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            backToMainPage();
        }
    }
}