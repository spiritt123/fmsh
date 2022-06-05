#pragma once

#include <cstdint>
#include <vector>
#include <string>

#include "chess_piece.h"
#include "enums.h"
#include "pair_coords.h"

class Map
{
public:
    Map(uint32_t size = 8);
    ~Map();

    const std::vector<std::vector<ChessPiece*>>& getMap();
    bool isCoodsBelongMap(uint32_t x, uint32_t y) const;
    ChessPiece* getChessPieceByCoords(uint32_t x, uint32_t y) const;

    void tryMove(std::string move);
    

private:
    void Init();
    StateChess getNewState(StateSignal signal);
    PairCoords ConvertMoveToPairCoords(std::string move, bool &result_convertation);

private:
    std::vector<std::vector<ChessPiece*>> _map;
    StateChess _state;

};


