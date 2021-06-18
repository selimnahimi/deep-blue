#include <stdio.h>
#include "lib/board.h"
#include "lib/piece.h"
#include "lib/input.h"

int main(void)
{
    board_state_t board = board_generate();
    board_print(board);

    char input[100];
    char err[255];
    wprintf( L"White's turn.\n");
    wprintf( L"Enter a move: ");
    scanf("%s", input);

    board_state_t move = process_move(board, input, err);

    board_print(move);

    scanf("%s", input);

    move = process_move(move, input, err);

    board_print(move);
    scanf("%s", input);

    move = process_move(move, input, err);

    board_print(move);

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
