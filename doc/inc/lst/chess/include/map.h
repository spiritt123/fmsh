#pragma once

#include <cstdint>
#include <vector>

#include <chess_piece.h>

class Map
{
public:
    Map(uint32_t size = 8);
    ~Map();

    const std::vector<std::vector<ChessPiece*>> getMap();

private:
    std::vector<std::vector<ChessPiece*>> _map;
};


