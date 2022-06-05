#pragma once

#include "enums.h"
#include "i_chess_rule.h"

class ChessPiece
{
public:
    ChessPiece(IChessRule *rule, ColorChessPiece color, TypesChessPiece type);
    ~ChessPiece();

    TypesChessPiece getType();
    ColorChessPiece getColor();

    bool canMove(const PairCoords &pair_coords, ColorChessPiece piece);
    bool canAttack(const PairCoords &pair_coords, ColorChessPiece piece_color, ColorChessPiece target_color);

private:
    TypesChessPiece _type;
    ColorChessPiece _color;
    IChessRule     *_rule;
};
