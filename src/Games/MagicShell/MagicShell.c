#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/Array/arraydin.h"
#include "../../ADT/MesinKata/mesinkata.h"

void magic_shell() {
    printf("Kerang Ajaib telah dimulai. Ulululululululu!!!\n");
    ArrayDin magshell = MakeArrayDin();
    magshell.Neff = 2;
    // Ya
    magshell.Elmt[0].Length = 2;
    magshell.Elmt[0].TabWord[0] = 'Y';
    magshell.Elmt[0].TabWord[1] = 'a';

    srand((unsigned) (time(0)));
    
    while (isWordEqual(currentWord, magshell.Elmt[0])) {
        COMMAND();
        int num = (rand() % 9) + 1;

        if (num == 1) {
            printf("Ya\n");
        }
        else if (num == 2) {
            printf("Tidak\n");
        }
        else if (num == 3) {
            printf("Kamu nanyeaaa?\n");
        }
        else if (num == 4) {
            printf("Kamu nanyea bertanyea tanyeaaa?\n");
        }
        else if (num == 5) {
            printf("Capek ah ditanyain mulu...\n");
        }
        else if (num == 6) {
            printf("Bisa jadi\n");
        }
        else if (num == 7) {
            "Mungkin\n";
        }
        else if (num == 8) {
            printf("Mungkin nanti\n");
        }
        else if (num == 9) {
            printf("Mungkin tidak\n");
        }
        else {
            printf("Coba tanya lagi\n");
        }

        COMMAND();
    }
}
