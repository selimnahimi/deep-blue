#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "lib/board.h"
#include "lib/piece.h"
#include "lib/input.h"

int main( int argc, char *argv[] )  {
    if (argc < 1) {
        printf("At least one argument expected.\n");
        return -1;
    }

    board_state_t* board = board_generate();

    // Iterate through moves
    for (char** pargv = argv+1; *pargv != argv[argc]; pargv++) {
        char err[255];

        //printf("Move \"%s\"\n", *pargv);
        //int prev_step = board->stepnum;

        board = process_move(board, *pargv, err);
        //printf("%s\n", (board->stepnum > prev_step) ? "Board changed." : "No change.");
    }

    //printf("End state: \n");
    printf("%d\n", board->stepnum);
    board_print_normal(board);

    //printf("-------------------------------\n");

    //printf("Freeing memory...\n");
    board_freememory(board);
    //printf("Done.\n");

    //printf("End.\n");
}