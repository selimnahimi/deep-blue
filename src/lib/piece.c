#include <stdbool.h>

#include "piece.h"

piece_t piece_empty() {
    return piece_create(TEAM_NONE, PIECE_NONE);
}

bool piece_isempty(piece_t piece) {
    return piece.team == TEAM_NONE || piece.type == PIECE_NONE;
}

piece_t piece_create(int team, int type) {
    piece_t piece;
    piece.team = team;
    piece.type = type;

    return piece;
}
