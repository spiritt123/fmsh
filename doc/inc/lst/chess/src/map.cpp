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
            element = nullptr; 
        }
    }
    Init();
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

void Map::Init()
{
    for (uint32_t i = 0; i < 8; ++i)
    {
        _map[1][i] = new ChessPiece(TypesChessPiece::WHITE_PAWN);
        _map[6][i] = new ChessPiece(TypesChessPiece::BLACK_PAWN);
    }
    _map[0][0] = new ChessPiece(TypesChessPiece::WHITE_ROOK);
    _map[0][1] = new ChessPiece(TypesChessPiece::WHITE_KNIGHT);
    _map[0][2] = new ChessPiece(TypesChessPiece::WHITE_BISHOP);
    _map[0][3] = new ChessPiece(TypesChessPiece::WHITE_QUEEN);
    _map[0][4] = new ChessPiece(TypesChessPiece::WHITE_KING);
    _map[0][5] = new ChessPiece(TypesChessPiece::WHITE_BISHOP);
    _map[0][6] = new ChessPiece(TypesChessPiece::WHITE_KNIGHT);
    _map[0][7] = new ChessPiece(TypesChessPiece::WHITE_ROOK);
    _map[7][0] = new ChessPiece(TypesChessPiece::BLACK_ROOK);
    _map[7][1] = new ChessPiece(TypesChessPiece::BLACK_KNIGHT);
    _map[7][2] = new ChessPiece(TypesChessPiece::BLACK_BISHOP);
    _map[7][3] = new ChessPiece(TypesChessPiece::BLACK_QUEEN);
    _map[7][4] = new ChessPiece(TypesChessPiece::BLACK_KING);
    _map[7][5] = new ChessPiece(TypesChessPiece::BLACK_BISHOP);
    _map[7][6] = new ChessPiece(TypesChessPiece::BLACK_KNIGHT);
    _map[7][7] = new ChessPiece(TypesChessPiece::BLACK_ROOK);
}





