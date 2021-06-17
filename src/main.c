#include "lib/board.h"
#include "lib/piece.h"
int main(void)
{
    board_state_t board = board_generate();
    board_print(board);

    board_state_t board2 = board_move(&board, 1, 1, 4, 4);

    board_print(board2);

    board_state_t board3 = board_move(&board2, 0, 0, 5, 5);

    board_print(board3);

    board_print(board_undo(board3));

    /*board = board_undo(board);

    board_print(board);
    board_print(*board.previous);*/

    /*printf("4 + 2 = %d\n", calculator('+', 4, 2));
    printf("4 - 2 = %d\n", calculator('-', 4, 2));
    printf("4 * 2 = %d\n", calculator('*', 4, 2));
    printf("4 / 2 = %d\n", calculator('/', 4, 2));*/
    return (0);
}
