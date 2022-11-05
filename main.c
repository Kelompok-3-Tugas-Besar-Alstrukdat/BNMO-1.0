//--------------------------------------------------------------- C LIBRARY ---------------------------------------------------------------//
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------ FILE HEADER ADT ------------------------------------------------------------//
#include "src/ADT/Array/arraydin.h"
#include "src/ADT/MesinKarakter/mesinkarakter.h"
#include "src/ADT/MesinKata/mesinkata.h"
#include "src/ADT/Queue/queue.h"

//--------------------------------------------------- FILE HEADER FUNCTION FOR COMMAND ----------------------------------------------------//
#include "src/Command/start.h"
#include "src/Command/load.h"
#include "src/Command/creategame.h"
#include "src/Command/listgame.h"
#include "src/Command/deletegame.h"
#include "src/Command/queuegame.h"
#include "src/Command/playgame.h"
#include "src/Command/skipgame.h"
#include "src/Command/quit.h"
#include "src/Command/help.h"
#include "src/Command/another_command.h"

void main()
{
    printf("ENTER COMMAND (START/LOAD): ");
    Word INPUT;
    COMMAND();
    INPUT = currentWord;
}