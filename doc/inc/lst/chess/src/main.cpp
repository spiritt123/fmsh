#include <iostream>
#include <cstdint>
#include <map>
#include <string>

#include "map.h"
#include "enums.h"

std::map<TypesChessPiece, std::string> chares =
    {
        {PAWN,   "p"},
        {KNIGHT, "l"},
        {BISHOP, "b"},
        {ROOK,   "r"},
        {QUEEN,  "q"},
        {KING,   "k"},
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
                std::cout << ((element->getColor() == ColorChessPiece::WHITE) ? 'w' : 'b');
                std::cout << chares[element->getType()] <<" ";
            }
        }
        std::cout << "\n";
    }
}


int main()
{
    Map map;
    std::string move;

    while (1)
    {
        print(map);
        std::cin >> move;
        map.tryMove(move);
    }

    return 0;
}


