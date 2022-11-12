/* =====| Definisi Header commands.h |===== */
#ifndef __COMMANDS__
#define __COMMANDS__


/* =====| Include Header |===== */
// C Header
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// ADT Header
#include "../boolean.h"
#include "../ADT/Array/arraydin.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Point/point.h"
#include "../ADT/Queue/queue.h"
#include "../Games/games.h"


/* =====| COMMAND CREATE GAME |===== */
// Prosedur untuk membuat serta menambahkan permainan ke dalam daftar permainan
void CreateGame(ArrayDin *Game);


/* =====| COMMAND DELETE GAME |===== */
// Prosedur untuk menghapus permainan yang ada dalam daftar permainan
// Permainan yang ada pada sistem tidak dapat dihapus
void DeleteGame(ArrayDin *Game, Queue *Gameq);


/* =====| COMMAND HELP |===== */
// Prosedur untuk menampilkan informasi command yang dapat dijalankan BNMO
void Help();


/* =====| COMMAND PLAY GAME |===== */
// Menjalankan permainan sesuai dengan daftar antrian
void PlayGame (Queue *q);


/* =====| COMMAND QUEUE GAME |===== */
// Prosedur untuk menambahkan permainan ke dalam daftar antrian
void QueueGame(ArrayDin *Game, Queue *Q);


/* =====| COMMAND SAVE |===== */
// Fungsi untuk memeriksa ekstensi file
boolean validExtension(char *filename);
// Prosedur untuk menyimpan file <savefile>.txt
void Save(ArrayDin array, char *filename);


/* =====| COMMAND SKIPGAME |===== */
// Prosedur untuk melewati permainan sebanyak n
// Memulai permainan jika daftar antrian tidak kosong
void SkipGame(Queue *game, int n);


/* =====| ANOTHER COMMAND |===== */
// Menyimpan Command-command yang valid ke dalam sebuah array
ArrayDin validCOMMAND();
// Fungsi untuk memeriksa apakah Kata merupakan sebuah perintah yang valid atau bukan.
// Jika valid akan mengembalikan true dan akan mengembalikan false jika tidak valid
boolean isCOMMAND(Word Kata);


/* =====| COUNTDOWN |===== */
// Prosedur untu menghasilkan waktu hitung mundur dengan menampilkan "."
void countdown();


#endif