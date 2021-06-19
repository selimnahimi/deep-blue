#ifndef _PIECE_H
#define _PIECE_H

#include <stdbool.h>
#include <wchar.h>

#define PIECE_NONE 9
#define PIECE_PAWN 0
#define PIECE_ROOK 1
#define PIECE_KNIGHT 2
#define PIECE_BISHOP 3
#define PIECE_QUEEN 4
#define PIECE_KING 5

#define TEAM_NONE 9
#define TEAM_WHITE 0
#define TEAM_BLACK 1

typedef struct piece_t {
    int team;
    int type;
} piece_t;

piece_t piece_empty();
bool piece_isempty(piece_t piece);
piece_t piece_create(int team, int type);
wchar_t piece_getwchar(int team_num, int piece_num);

#endif
