#include <stdbool.h>
#include <wchar.h>

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

bool isvalid_team(int team_num) {
    return team_num == TEAM_BLACK || team_num == TEAM_WHITE;
}

bool isvalid_piece(int piece_num) {
    return piece_num >= PIECE_PAWN && piece_num <= PIECE_KING;
}

wchar_t piece_getwchar(int team_num, int piece_num) {

    wchar_t piece_wchars[2][6];
    piece_wchars[TEAM_WHITE][PIECE_QUEEN] = 0x2654;
    piece_wchars[TEAM_WHITE][PIECE_KING] = 0x2655;
    piece_wchars[TEAM_WHITE][PIECE_ROOK] = 0x2656;
    piece_wchars[TEAM_WHITE][PIECE_BISHOP] = 0x2657;
    piece_wchars[TEAM_WHITE][PIECE_KNIGHT] = 0x2658;
    piece_wchars[TEAM_WHITE][PIECE_PAWN] = 0x2659;

    piece_wchars[TEAM_BLACK][PIECE_QUEEN] = 0x265A;
    piece_wchars[TEAM_BLACK][PIECE_KING] = 0x265B;
    piece_wchars[TEAM_BLACK][PIECE_ROOK] = 0x265C;
    piece_wchars[TEAM_BLACK][PIECE_BISHOP] = 0x265D;
    piece_wchars[TEAM_BLACK][PIECE_KNIGHT] = 0x265E;
    //piece_wchars[TEAM_BLACK][PIECE_PAWN] = 0x265F;
    piece_wchars[TEAM_BLACK][PIECE_PAWN] = 0x2659;

    if (!isvalid_team(team_num) || !isvalid_piece(piece_num)) {
        return L' ';
    }

    return piece_wchars[team_num][piece_num];
}

void piece_print(piece_t piece) {
}
