#include <stdbool.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#include "board.h"
#include "piece.h"

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

board_state_t board_generate() {
    board_state_t newboard;

    // Set up board
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            newboard.cells[y][x] = piece_empty();
        }
    }

    // Place pawns
    int row_top = 0;
    int row_bottom = BOARD_HEIGHT-1;
    for (int x = 0; x < BOARD_WIDTH; x++) {
        // top row
        newboard.cells[row_top][x].team = TEAM_BLACK;
        newboard.cells[row_top][x].type = PIECE_PAWN;

        // bottom row
        newboard.cells[row_bottom][x].team = TEAM_WHITE;
        newboard.cells[row_bottom][x].type = PIECE_PAWN;
    }

    return newboard;
}

void board_print(board_state_t state) {
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            printf("%d", state.cells[y][x].type);
        }
        printf("\n");
    }
}

/*void board_print(board_state_t state) {
    setlocale(LC_CTYPE, "");

    for (wchar_t p = 0x2654; p <= 0x265F; p++) {
        wprintf(L"%lc\n", p);
    }
}*/

bool board_replace(int x, int y, piece_t newpiece) {
    return false;
}

bool board_move(piece_t piece, int newx, int newy) {
    return false;
}

board_state_t board_undo(board_state_t state) {
    board_state_t newboard = board_generate();
    return newboard;
}

board_state_t board_redo(board_state_t state) {
    board_state_t newboard = board_generate();
    return newboard;
}
