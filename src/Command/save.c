// Include Header
#include "commands.h"

boolean validExtension(char *filename)
{
    boolean valid = true;
    char check[5], extension[5] = ".txt";
    int str_len = 0;
    while (filename[str_len] != '\0')
    {
        str_len++;
    }
    for (int i = 3; i >=0; i--)
    {
        check[3-i] = filename[str_len - 1 - i];
    }
    for (int i = 0; i < 5; i++)
    {
        if (check[i] != extension[i])
        {
            valid = false;
            break;
        }
    }
    return valid;
}

void Save(ArrayDin array, char *filename)
{
    char text[50];
    static FILE *savefile;

    savefile = fopen(filename, "w");
    if (savefile == NULL)
    {
        printf("Gagal untuk menyimpan file. Silahkan coba lagi\n");
    }
    else
    {
        for (int i = 0; i < array.Neff; i++)
        {
            toStr(array.Elmt[i], text);
            fputs(text, savefile);
            fputs("\n", savefile);
        }
        fputs(".", savefile);
    }
    fclose(savefile);
}