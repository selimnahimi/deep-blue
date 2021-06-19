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
        char* current_player;
        
        int move_num = board->stepnum;

        if (move_num % 2 == 0) {
            current_player = p1_name;
        } else {
            current_player = p2_name;
        }

        wprintf(L"Move #%d, %s's turn\n\n", board->stepnum, current_player);
        board_print(board);

        wprintf( L"Enter a move: ");
        scanf("%s", input);

        if (strcmp("end", input) == 0) {
            break;
        }

        board = process_move(board, input, err);

        wprintf( L"------------------------------------\n");

        if (strcmp("none", err) != 0) {
            wprintf( L"Invalid move: %s\n", err);
        }
    }

    board_freememory(board);
    
    return (0);
}
