// Include Header
#include "commands.h"

void SkipGame(Queue *game, int n){
    QueueType val;
    for (int i = 0; i < n; i++){
        dequeueQ(game, &val);
    }
    if (!isEmptyQueue(*game)){
        PlayGame(game);
    }
    else
    {
        printf("Tidak ada permainan lagi dalam daftar antrian.\n");
    }
}
