#include <stdio.h>

void SkipGame(Queue *game, int n){
    for (int i = 0; ((i < n) && (i < lengthQueue(*game))); i++){
        QueueType val;
        dequeueQ(game, &val);
    }
    if (!isEmptyQueue(*game)){
        PlayGame(game);
    }
}
