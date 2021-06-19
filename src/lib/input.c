#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "board.h"
#include "piece.h"

int row_normalize(int rownum) {
    // Rows by default go from 0->7 but it needs to be 8->1 (from top to bottom)
    int maxrows = BOARD_HEIGHT;

    return abs(maxrows - rownum);
}

int row_unnormalize(int rownum) {
    // We need 0->7 format instead of 8->1 (from top to bottom)
    int maxrows = BOARD_HEIGHT;

    return abs(rownum - maxrows);
}

int letter_toint(char c) {
    if (c >= '0' && c <= '9') {
        // char representing a number
        return c - '0';
    }

    if (c >= 'A' && c <= 'Z') {
        // char representing capital letters
        c += 32; // converting to lowercase
    }

    if (c >= 'a' && c <= 'z') {
        // char representing lowercase letters
        return c - 'a';
    }

    // invalid
    return -1;
}

board_state_t process_move(board_state_t state, const char* input, char* err) {
    // A move looks like this: Rh4e1 where Rook moves from h4 to e1

    err = "none";

    if (strcmp(input, "undo")) {
        return board_undo(state);
    }

    if (strlen(input) != 5) {
        err = "Invalid move syntax!\n";
        return state;
    }

    int fromx = letter_toint(input[1]);
    int tox =   letter_toint(input[3]);

    int fromy = row_unnormalize(letter_toint(input[2]));
    int toy =   row_unnormalize(letter_toint(input[4]));

    /*printf("from: %d, %d\n", fromx, fromy);
    printf("to: %d, %d\n", tox, toy);*/

    board_state_t move = board_move(&state, fromx, fromy, tox, toy);

    if (strcmp(err, "none") == 0) {
        return move;
    } else {
        return state;
    }
}
