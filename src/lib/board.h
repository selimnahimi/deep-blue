#ifndef _BOARD_H
#define _BOARD_H

#include <stdbool.h>
#include "piece.h"
#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

typedef struct board_state_t {
    int stepnum;
    piece_t cells[BOARD_HEIGHT][BOARD_WIDTH];

    struct board_state_t *previous;
    struct board_state_t *next;
} board_state_t;

board_state_t* board_generate();
void board_print(board_state_t* state);
bool board_replace(int x, int y, piece_t newpiece);
board_state_t* board_move(board_state_t* state, int fromx, int fromy, int tox, int toy);
board_state_t* board_undo(board_state_t* state);
board_state_t* board_redo(board_state_t* state);
int step_validate(board_state_t* state, int fromx, int fromy, int tox, int toy);

#endif
