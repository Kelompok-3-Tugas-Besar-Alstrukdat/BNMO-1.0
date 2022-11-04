#include "mesinkata.h"

/* State Mesin Kata */
boolean EndWord;
Word currentWord;
Word currentCMD;

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD()
{
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        ADVWord();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD()
{
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */

void CopyWord()
{
    currentWord.Length = 0;
    while ((currentChar != BLANK) && (currentChar != MARK))
    {
        // jika lebih akan terpotong
        if (currentWord.Length < NMax)
        {
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
        {
            break;
        }
    }
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void COMMAND()
{
    CharCOMMAND();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        ADVWord();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = ENTER;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

int toInt (Word Kata)
{
    int base;
    int num = 0;
    for (int i = 0; i < Kata.Length; i++)
    {
        base = 1;
        for (int j = (Kata.Length - 1); j > i; j--)
        {
            base *= 10;
        }
        num += ((Kata.TabWord[i] - '0') * base);
    }
    return num;
}
/* Mengubah kata yang merupakan angka numerik menjadi integer
   Prekondisi : Kata merupakan bilangan numerik */

boolean isWordEqual (Word Kata1, Word Kata2)
{
    boolean check = true;
    if (Kata1.Length != Kata2.Length)
    {
        return !check;
    }
    else
    {
        int i = 0;
        while (check && (i < Kata1.Length))
        {
            if (Kata1.TabWord[i] != Kata2.TabWord[i])
            {
                check = false;
            }
            i++;
        }
        return check;
    }
}
/* Memeriksa apakah Kata1 dan Kata2 sama, jika Kata1 dan Kata2 sama akan mengembalikan true
   Prekondisi : Kata1 dan Kata2 terdefinisi */