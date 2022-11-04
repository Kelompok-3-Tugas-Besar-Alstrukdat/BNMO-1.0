#include "rng.h"

int RandomNumber()
{
    srand(time(0));
    int num = (rand() % 101); // Angka berada pada rentang nilai 0-100 (inclusive)
    return num;
}

int main()
{
    printf("RNG telah dimulai. Uji keberuntungan Anda dengan menebak X.\n")
    int X = RandomNumber(), score = 110, attempt = 0, tebakan;
    do
    {
        attempt++;
        score -= 10;
        scanf("Tebakan: %d", &tebakan);
        if (X < tebakan)
        {
            printf("Lebih kecil\n");
        }
        else if (X > tebakan)
        {
            printf("Lebih besar\n");
        }
        else
        {
            printf("\nYa, X adalah %d\n", X);
        }
    }
    while ((attempt < 10) && (tebakan != X));
    if (tebakan != X)
    {
        printf("\nMaaf, Anda kurang beruntung. Kesempatan Anda telah habis. Coba lagi lain waktu.")
    }
    printf("Skor Anda: %d", score);
    return 0;
}