#include <stdio.h>

void Help(){
    printf("HELP\n");
    printf("1. START\n");
    printf("   Enter command START, dibaca file yang berisi list game yang dapat dimainkan\n");
    printf("2. LOAD\n");
    printf("   Enter command savefile1.txt, dibaca save file <filename> berisi list game yang dapat dimainkan, history dan scoreboard game\n");
    printf("3. CREATE GAME\n");
    printf("   Enter command CREATE GAME, menambahkan game baru pada daftar game\n");
    printf("4. LIST GAME\n");
    printf("   Enter command LIST GAME, menampilkan daftar game yang disediakan sistem\n");
    printf("5. DELETE GAME\n");
    printf("   Enter command DELETE GAME, menghapus game dari daftar game");
    printf("6. QUEUE GAME\n");
    printf("   Enter command QUEUE GAME, mendaftarkan permainan ke dalam list, list hilang saat command QUIT dijalankan\n");
    printf("7. PLAY GAME\n");
    printf("   Enter command PLAY GAME, game yang dimainkan yaitu game dengan urutan pertama di antrian game\n");
    printf("8. SKIP GAME\n");
    printf("   Enter command SKIPGAME 2, melewatkan permainan sebanyak n\n");
    printf("9. QUIT\n");
    printf("   Enter command QUIT, keluar dari program");
}