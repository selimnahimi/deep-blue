#include <stdio.h>
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

    board_state_t board = board_generate();

    char input[100];
    char err[255];

    while (true) {
        int move_num = board.stepnum;

        wprintf(L"Move #%d\n", board.stepnum);
        board_print(board);

        if (move_num % 2 == 0) {
            wprintf( L"%s's turn.\n", p1_name);
        } else {
            wprintf( L"%s's turn.\n", p2_name);
        }

        wprintf( L"Enter a move: ");
        scanf("%s", input);

        board = process_move(board, input, err);

        wprintf( L"------------------------------------\n");
    }

    /*
    board_state_t board = board_generate();
    board_print(board);

    char err[255];

    board_state_t move = process_move(board, "Ra8a5", err);

    board_print(move);

    board_state_t move2 = process_move(move, "Rb8b5", err);

    board_print(move2);
    */

    //board_state_t board2 = board_move(&board, 1, 1, 2, 1);

    //board_print(board2);

    //board_state_t board3 = board_move(&board2, 0, 0, 6, 6);

    //board_print(board3);

    //board_print(board_undo(board3));

    /*board = board_undo(board);

    board_print(board);
    board_print(*board.previous);*/

    /*printf("4 + 2 = %d\n", calculator('+', 4, 2));
    printf("4 - 2 = %d\n", calculator('-', 4, 2));
    printf("4 * 2 = %d\n", calculator('*', 4, 2));
    printf("4 / 2 = %d\n", calculator('/', 4, 2));*/
    return (0);
}
