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

    newboard.previous = &newboard;

    // Set up board
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            newboard.cells[y][x] = piece_empty();
        }
    }

    int row_top = 0;
    int row_bottom = BOARD_HEIGHT-1;

    // Set cell teams
    for (int x = 0; x < BOARD_WIDTH; x++) {
        // top row is black
        newboard.cells[row_top][x].team = TEAM_BLACK;
        newboard.cells[row_top+1][x].team = TEAM_BLACK;
        
        // bottom row is white
        newboard.cells[row_bottom][x].team = TEAM_WHITE;
        newboard.cells[row_bottom-1][x].team = TEAM_WHITE;
    }

    // Place pawns
    for (int x = 0; x < BOARD_WIDTH; x++) {
        // top row
        newboard.cells[row_top+1][x].type = PIECE_PAWN;

        // bottom row
        newboard.cells[row_bottom-1][x].type = PIECE_PAWN;
    }

    // Place other pieces
    newboard.cells[row_top][0].type = PIECE_ROOK;
    newboard.cells[row_top][1].type = PIECE_KNIGHT;
    newboard.cells[row_top][2].type = PIECE_BISHOP;
    newboard.cells[row_top][3].type = PIECE_QUEEN;
    newboard.cells[row_top][4].type = PIECE_KING;
    newboard.cells[row_top][5].type = PIECE_BISHOP;
    newboard.cells[row_top][6].type = PIECE_KNIGHT;
    newboard.cells[row_top][7].type = PIECE_ROOK;

    newboard.cells[row_bottom][0].type = PIECE_ROOK;
    newboard.cells[row_bottom][1].type = PIECE_KNIGHT;
    newboard.cells[row_bottom][2].type = PIECE_BISHOP;
    newboard.cells[row_bottom][3].type = PIECE_QUEEN;
    newboard.cells[row_bottom][4].type = PIECE_KING;
    newboard.cells[row_bottom][5].type = PIECE_BISHOP;
    newboard.cells[row_bottom][6].type = PIECE_KNIGHT;
    newboard.cells[row_bottom][7].type = PIECE_ROOK;

    return newboard;
}

void board_print(board_state_t state) {
    setlocale(LC_CTYPE, "");

    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            int team = state.cells[y][x].team;
            int type = state.cells[y][x].type;
            wchar_t p = piece_getwchar(team, type);

            wprintf(L"%lc ", p);
        }
        wprintf(L"\n");
    }
    wprintf(L"\n");
}

bool isvalid_coords(int x, int y) {
    return x < BOARD_WIDTH && x >= 0 && y < BOARD_HEIGHT && y >= 0;
}

bool isempty_cell(board_state_t state, int x, int y) {
    piece_t piece = state.cells[y][x];
    return piece.team == TEAM_NONE || piece.type == PIECE_NONE;
}

/*
void board_print(board_state_t state) {
    setlocale(LC_CTYPE, "");

    for (wchar_t p = 0x2654; p <= 0x265F; p++) {
        for (int i = 0; i < 8; i++)
        {
            wprintf(L"%lc", p);
        }
        wprintf(L"\n");
    }
}
*/

bool board_replace(int x, int y, piece_t newpiece) {
    return false;
}

board_state_t board_move(board_state_t state, int fromx, int fromy, int tox, int toy) {
    if (!isvalid_coords(fromx, fromy) || !isvalid_coords(tox, toy)) return state;
    if (isempty_cell(state, fromx, fromy)) return state;

    board_state_t newstate = state;
    state.next =        &newstate;
    newstate.previous = &state;

    piece_t piece = newstate.cells[fromy][fromx];
    newstate.cells[toy][tox] = piece;

    newstate.cells[fromy][fromx] = piece_empty();

    return newstate;
}

board_state_t board_undo(board_state_t state) {
    board_state_t newboard = *state.previous;
    return newboard;
}

board_state_t board_redo(board_state_t state) {
    board_state_t newboard = board_generate();
    return newboard;
}