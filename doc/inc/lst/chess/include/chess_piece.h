#pragma once

#include "types_chess_piece.h"

class ChessPiece
{
public:
    ChessPiece(TypesChessPiece type);
    ~ChessPiece();

    TypesChessPiece getType();

private:
    TypesChessPiece _type;
};
