#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "input.h"
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

board_state_t* process_move(board_state_t* state, const char* input, char* err) {
    // A move looks like this: h4e1 where a piece moves from h4 to e1

    strcpy(err, "none");

    if (strcmp(input, "undo") == 0) {
        return board_undo(state);
    }

    if (strlen(input) != 4) {
        strcpy(err, "Invalid move syntax!\n");
        return state;
    }

    int fromx = letter_toint(input[0]);
    int tox =   letter_toint(input[2]);

    int fromy = row_unnormalize(letter_toint(input[1]));
    int toy =   row_unnormalize(letter_toint(input[3]));

    int errcode = step_validate(state, fromx, fromy, tox, toy);

    switch (errcode) {
        case 0:
            break;
        case 1:
            strcpy(err, "Coordinates out of bounds!\n");
            break;
        case 2:
            strcpy(err, "No piece on given cell!\n");
            break;
        case 3:
            strcpy(err, "Trying to hit your own piece!\n");
            break;
        case 4:
            strcpy(err, "This piece is not yours!\n");
            break;
        default:
            strcpy(err, "Unknown error\n");
            break;
    }
    
    if (strcmp(err, "none") == 0) {
        board_state_t* move = board_move(state, fromx, fromy, tox, toy);
        return move;
    } else {
        return state;
    }
}
