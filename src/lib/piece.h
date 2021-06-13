#include <stdbool.h>

#define PIECE_NONE 0
#define PIECE_PAWN 1
#define PIECE_ROOK 2
#define PIECE_KNIGHT 3
#define PIECE_BISHOP 4
#define PIECE_QUEEN 5
#define PIECE_KING 6

#define TEAM_NONE 0
#define TEAM_WHITE 1
#define TEAM_BLACK 2

#ifndef _PIECE_H
#define _PIECE_H
typedef struct piece_t {
    int team;
    int type;
} piece_t;

piece_t piece_empty();
bool piece_isempty(piece_t piece);
piece_t piece_create(int team, int type);

#endif