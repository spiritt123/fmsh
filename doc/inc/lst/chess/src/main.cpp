#include <iostream>
#include <cstdint>
#include <map>
#include <string>

#include "map.h"
#include "types_chess_piece.h"

std::map<TypesChessPiece, std::string> chares =
    {
        {WHITE_PAWN,   "wp"},
        {WHITE_KNIGHT, "wl"},
        {WHITE_BISHOP, "wb"},
        {WHITE_ROOK,   "wr"},
        {WHITE_QUEEN,  "wq"},
        {WHITE_KING,   "wk"},

        {BLACK_PAWN,   "bp"},
        {BLACK_KNIGHT, "bl"},
        {BLACK_BISHOP, "bb"},
        {BLACK_ROOK,   "br"},
        {BLACK_QUEEN,  "bq"},
        {BLACK_KING,   "bk"},
    }; 

void print(Map &map)
{
    const auto place = map.getMap();
    for (const auto& rol : place)
    {
        for (const auto& element : rol)
        {
            if (element == nullptr)
            {
                std::cout << "__ ";
            }
            else
            {
                std::cout << chares[element->getType()] <<" ";
            }
        }
        std::cout << "\n";
    }
}


int main()
{
    Map map;

    print(map);

    return 0;
}


