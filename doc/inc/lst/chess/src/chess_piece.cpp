#include "chess_piece.h"
#include "simple_chess_rule.h"

ChessPiece::ChessPiece(IChessRule *rule, ColorChessPiece color, TypesChessPiece type)
    : _rule(rule)
    , _color(color)
    , _type(type)
{

}

ChessPiece::~ChessPiece()
{
    delete _rule;
}

TypesChessPiece ChessPiece::getType()
{
    return _type;
}

ColorChessPiece ChessPiece::getColor()
{
    return _color;
}

bool ChessPiece::canMove(const PairCoords &pair_coords, ColorChessPiece piece)
{
    return _rule->canChessPieceMoved(pair_coords, piece);
}    

bool ChessPiece::canAttack(const PairCoords &pair_coords, ColorChessPiece piece_color, ColorChessPiece target_color)
{
    return _rule->canChessPieceAttacked(pair_coords, piece_color, target_color);
}



