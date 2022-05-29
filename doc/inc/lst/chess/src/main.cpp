#include <iostream>
#include <cstdint>
#include <map>

#include "map.h"
#include "types_chess_piece.h"

std::map<TypesChessPiece, char> chares =
    {
        {PAWN, '^'},
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
                std::cout << "  ";
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


