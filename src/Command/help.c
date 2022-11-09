#include <stdio.h>

void Help(){
    printf("HELP\n");
    printf("1. START\n");
    printf("   Enter command START, dibaca file yang berisi list game yang dapat dimainkan\n");
    printf("2. LOAD\n");
    printf("   Enter command LOAD <filename>, dibaca save file <filename> berisi list game yang dapat dimainkan, history dan scoreboard game\n");
    printf("2. SAVE\n");
    printf("   Enter command SAVE <filename>, dibaca save file <filename> berisi list game yang dapat dimainkan, history dan scoreboard game\n");
    printf("4. CREATE GAME\n");
    printf("   Enter command CREATE GAME, menambahkan game baru pada daftar game\n");
    printf("5. LIST GAME\n");
    printf("   Enter command LIST GAME, menampilkan daftar game yang disediakan sistem\n");
    printf("6. DELETE GAME\n");
    printf("   Enter command DELETE GAME, menghapus game dari daftar game");
    printf("7. QUEUE GAME\n");
    printf("   Enter command QUEUE GAME, mendaftarkan permainan ke dalam list, list hilang saat command QUIT dijalankan\n");
    printf("8. PLAY GAME\n");
    printf("   Enter command PLAY GAME, game yang dimainkan yaitu game dengan urutan pertama di antrian game\n");
    printf("9. SKIP GAME\n");
    printf("   Enter command SKIPGAME <n>, melewatkan permainan sebanyak n\n");
    printf("10. QUIT\n");
    printf("    Enter command QUIT, keluar dari program");
}