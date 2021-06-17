#include "lib/board.h"
#include "lib/piece.h"
int main(void)
{
    board_state_t board = board_generate();

    board = board_move(board, 0, 0, 3, 3);

    board_print(board);

    board = board_undo(board);

    board_print(board);

    /*printf("4 + 2 = %d\n", calculator('+', 4, 2));
    printf("4 - 2 = %d\n", calculator('-', 4, 2));
    printf("4 * 2 = %d\n", calculator('*', 4, 2));
    printf("4 / 2 = %d\n", calculator('/', 4, 2));*/
    return (0);
}
