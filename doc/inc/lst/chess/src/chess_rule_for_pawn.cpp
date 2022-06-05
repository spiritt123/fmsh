#include "simple_chess_rule.h"
#include "map.h"
#include <iostream>


ChessRuleForPawn::ChessRuleForPawn() : IChessRule()
{
}

ChessRuleForPawn::~ChessRuleForPawn()
{
}


bool ChessRuleForPawn::canChessPieceMoved(const PairCoords &pair_coords, ColorChessPiece piece) const
{
    if (pair_coords.piecex == pair_coords.targetx)
    {
        if (piece == ColorChessPiece::WHITE)
        {
            if (pair_coords.piecey == pair_coords.targety - 1)
            {
                return true;
            }
            if (pair_coords.piecey == 1 && 
                pair_coords.piecey == pair_coords.targety - 2)
            {
                return true;
            }
        }
        if (piece == ColorChessPiece::BLACK)
        {
            if (pair_coords.piecey == pair_coords.targety + 1)
            {
                return true;
            }
            if (pair_coords.piecey == 6 && 
                pair_coords.piecey == pair_coords.targety + 2)
            {
                return true;
            }
        }
    }

    return false;
}

bool ChessRuleForPawn::canChessPieceAttacked(const PairCoords &pair_coords, 
                                             ColorChessPiece piece_color, 
                                             ColorChessPiece target_color) const
{
    if (piece_color == target_color)
    {
        return false;
    }
        
    if (pair_coords.piecex == pair_coords.targetx + 1 ||
        pair_coords.piecex == pair_coords.targetx - 1)
    {
        if (piece_color == ColorChessPiece::WHITE)
        {
            if (pair_coords.piecey == pair_coords.targety + 1)
            {
                return true;
            }
        }
        if (piece_color == ColorChessPiece::BLACK)
        {
            if (pair_coords.piecey == pair_coords.targety - 1)
            {
                return true;
            }
        }
    }
    return true;
}

