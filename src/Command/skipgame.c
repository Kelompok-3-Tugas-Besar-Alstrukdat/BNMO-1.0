void SKIPGAME (queue *game, int n){
    int i;
    scanf("%d", &n);
    if (n <= length(q)){
        while (i <= n){
            dequeue(*game, *HEAD(q));
        }
    }
    else {
        printf("Tidak ada permainan lagi dalam daftar game-mu /n");
    }
}
