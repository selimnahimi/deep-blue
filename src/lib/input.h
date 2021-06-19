#ifndef _INPUT_H
#define _INPUT_H

#include "board.h"
#include "piece.h"

board_state_t* process_move(board_state_t* state, const char* input, char* err_out);
int letter_toint(char c);
int row_normalize(int rownum);
int row_unnormalize(int rownum);

#endif