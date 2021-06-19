#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "lib/board.h"
#include "lib/piece.h"
#include "lib/input.h"

int main(void)
{
    setlocale(LC_CTYPE, "");

    char p1_name[100];
    char p2_name[100];

    wprintf( L"Player #1 name: ");
    scanf("%s", p1_name);

    wprintf( L"Player #2 name: ");
    scanf("%s", p2_name);

    board_state_t* board = board_generate();

    while (true) {
        char input[100];
        char err[255];
        
        int move_num = board->stepnum;

        wprintf(L"Move #%d\n", board->stepnum);
        board_print(board);

        if (move_num % 2 == 0) {
            wprintf( L"%s's turn.\n", p1_name);
        } else {
            wprintf( L"%s's turn.\n", p2_name);
        }

        wprintf( L"Enter a move: ");
        scanf("%s", input);

        if (strcmp("exit", input) == 0) {
            break;
        }

        board = process_move(board, input, err);

        wprintf( L"------------------------------------\n");

        wprintf( L"Invalid move: %s\n", err);
        if (strcmp("none", err) != 0) {
        }
    }

    // Freeing allocated memory
    board_state_t* nextptr;
    board_state_t* cptr = board;
    while (cptr != NULL) {
        nextptr = cptr->previous;
        //wprintf(L"freeing %d...\n", cptr->stepnum);
        free(cptr);

        cptr = nextptr;
    }
    
    return (0);
}
