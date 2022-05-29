#include "map.h"
#include "types_chess_piece.h"

Map::Map(uint32_t size)
{
    _map.resize(size);
    for (auto& rol : _map)
    {
        rol.resize(size);
        for (auto& element : rol)
        {
            element = new ChessPiece(TypesChessPiece::PAWN);
        }
    }
}

Map::~Map()
{
    for (auto& rol : _map)
    {
        for (auto& element : rol)
        {
            delete element;
        }
    }
}

const std::vector<std::vector<ChessPiece*>> Map::getMap()
{
    return _map;
}

