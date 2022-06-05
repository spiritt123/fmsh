#include "simple_chess_rule.h"
#include "map.h"
#include <iostream>


ChessRuleForKing::ChessRuleForKing() : IChessRule()
{
}

ChessRuleForKing::~ChessRuleForKing()
{
}


bool ChessRuleForKing::canChessPieceMoved(const PairCoords &pair_coords, ColorChessPiece piece_color) const
{
    if (abs(pair_coords.piecex - pair_coords.targetx) > 1 ||
        abs(pair_coords.piecey - pair_coords.targety) > 1)
    {
        return false;
    }    

    return true;
}

bool ChessRuleForKing::canChessPieceAttacked(const PairCoords &pair_coords, 
                                             ColorChessPiece piece_color, 
                                             ColorChessPiece target_color) const
{
    if (piece_color == target_color)
    {
        return false;
    }

    return canChessPieceMoved(pair_coords, piece_color);
}

