void SKIPGAME (queue *game, int n){
    int i;
    scanf("%d", &n);
    if (n <= length(game)){
        while (i <= n){
            dequeue(*game, *HEAD(game));
        }
    }
    else {
        printf("Tidak ada permainan lagi dalam daftar game-mu /n");
    }
}
