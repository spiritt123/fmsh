#include "simple_chess_rule.h"
#include "map.h"
#include <iostream>


ChessRuleForBishop::ChessRuleForBishop() : IChessRule()
{
}

ChessRuleForBishop::~ChessRuleForBishop()
{
}


bool ChessRuleForBishop::canChessPieceMoved(const PairCoords &pair_coords, ColorChessPiece piece_color) const
{
    if (pair_coords.piecex - pair_coords.targetx != pair_coords.piecey - pair_coords.targety &&
        pair_coords.piecex - pair_coords.targetx != -pair_coords.piecey + pair_coords.targety)
    {
        return false;
    }

    return true;
}

bool ChessRuleForBishop::canChessPieceAttacked(const PairCoords &pair_coords, 
                                             ColorChessPiece piece_color, 
                                             ColorChessPiece target_color) const
{
    if (piece_color == target_color)
    {
        return false;
    }

    return canChessPieceMoved(pair_coords, piece_color);
}

