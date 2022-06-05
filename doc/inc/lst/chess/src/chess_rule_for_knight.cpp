#include "simple_chess_rule.h"
#include "map.h"
#include <iostream>


ChessRuleForKnight::ChessRuleForKnight() : IChessRule()
{
}

ChessRuleForKnight::~ChessRuleForKnight()
{
}


bool ChessRuleForKnight::canChessPieceMoved(const PairCoords &pair_coords, ColorChessPiece piece_color) const
{
    int dx = abs(pair_coords.piecex - pair_coords.targetx);
    int dy = abs(pair_coords.piecey - pair_coords.targety);

    if (dx == 1 && dy == 2 || dx == 2 && dy == 1)
    {
        return true;
    }

    return false;
}

bool ChessRuleForKnight::canChessPieceAttacked(const PairCoords &pair_coords, 
                                             ColorChessPiece piece_color, 
                                             ColorChessPiece target_color) const
{
    if (piece_color == target_color)
    {
        return false;
    }
        
    return canChessPieceMoved(pair_coords, piece_color);
}

