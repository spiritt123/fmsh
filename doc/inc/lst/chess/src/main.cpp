#include <iostream>
#include <cstdint>
#include <map>
#include <string>
#include <unistd.h>

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
    system("clear");
    std::cout << "   ";
    for (int i = 0; i < 8; ++i) std::cout << " " << (char)(i + 'a') << " ";
    std::cout << "\n";
    int i = 1;
    for (const auto& rol : place)
    {
        std::cout << "|" << i << "|";
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
        std::cout << "|" << i++ << "|";
        std::cout << "\n";
    }
    std::cout << "   ";
    for (int i = 0; i < 8; ++i) std::cout << " " << (char)(i + 'a') << " ";
    std::cout << "\n";
}


int main()
{
    Map map;
    std::string move = "start";

    while (move != "stop")
    {
        print(map);
        std::cin >> move;
        map.tryMove(move);
        usleep(500);
    }

    return 0;
}


