#include "chess_piece.h"

ChessPiece::ChessPiece(TypesChessPiece type)
    : _type(type)
{

}

ChessPiece::~ChessPiece()
{
}

TypesChessPiece ChessPiece::getType()
{
    return _type;
}

