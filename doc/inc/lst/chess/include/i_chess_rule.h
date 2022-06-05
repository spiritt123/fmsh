#pragma once

#include <cstdint>
#include "pair_coords.h"
#include "enums.h"

class Map;

class IChessRule
{
public:
    IChessRule() {}
    virtual ~IChessRule() = default;

    virtual bool canChessPieceMoved(const PairCoords &pair_coords, ColorChessPiece piece) const = 0;
    virtual bool canChessPieceAttacked(const PairCoords &pair_coords, 
                                       ColorChessPiece piece_color, 
                                       ColorChessPiece target_color) const = 0;

protected:

};

