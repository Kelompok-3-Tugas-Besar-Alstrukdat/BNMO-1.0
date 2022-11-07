// File: rng.h
#ifndef _RNG_
#define _RNG_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/MesinKata/mesinkata.h"

// Fungsi untuk menentukan nilai integer yang random,
// dengan rentang nilai 0-100 (inclusive)
int RandomNumber();

// Prosedur yang menjalankan game RNG
// Prekondisi: tebakan merupakan bilangan bulat (integer)
void runRNG();

#endif