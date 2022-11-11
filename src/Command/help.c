#include <stdio.h>

//Menampilkan Command-command yang dapat dijalankan dalam BNMO
void Help(){
    printf("H E L P\n");
    printf(" 1. START\n");
    printf("    Command START, membaca file konfigurasi yang akan digunakan sebagai data permainan pada BNMO.\n");
    printf(" 2. LOAD\n");
    printf("    Command LOAD <filename>.txt, membaca save file <filename> yang akan digunakan sebagai data permainan pada BNMO.\n");
    printf(" 2. SAVE\n");
    printf("    Command SAVE <filename>.txt, menyimpan \"state\" permainan pemain ke suatu file <filename>.txt agar dapat digunakan kembali.\n");
    printf(" 4. CREATE GAME\n");
    printf("    Command CREATE GAME, menambahkan permainan baru pada daftar permainan.\n");
    printf(" 5. LIST GAME\n");
    printf("    Command LIST GAME, menampilkan daftar permainan yang dijalankan pada BNMO.\n");
    printf(" 6. DELETE GAME\n");
    printf("    Command DELETE GAME, menghapus permainan dari daftar permainan.\n");
    printf(" 7. QUEUE GAME\n");
    printf("    Command QUEUE GAME, menambahkan permainan ke dalam daftar antrian untuk dimainkan dan akan hilang saat keluar dari BNMO.\n");
    printf(" 8. PLAY GAME\n");
    printf("    Command PLAY GAME, menjalankan permainan pertama pada daftar antrian dan menghapusnya dari daftar antrian.\n");
    printf(" 9. SKIP GAME\n");
    printf("    Command SKIPGAME <n>, melewatkan permainan sebanyak <n> dan menjalankan permainan pada urutan <n> + 1\n");
    printf("    serta menghapus permainan yang dilewati dari daftar antrian.\n");
    printf("10. QUIT\n");
    printf("    Command QUIT, keluar dari permaina BNMO.\n");
}