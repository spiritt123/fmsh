#include <SFML/Graphics.hpp>

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
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    window.setFramerateLimit(30);

    sf::Texture pieces_texture;
    pieces_texture.loadFromFile("piece.png");
    sf::Texture place_texture;
    place_texture.loadFromFile("place.jpg");

    sf::Sprite place_sprite;
    place_sprite.setTexture(place_texture);
    //sprite.setTextureRect(sf::IntRect(10, 10, 50, 30));
    place_sprite.setScale(sf::Vector2f(0.5, 0.5));
    place_sprite.setColor(sf::Color(255, 255, 255, 200));
    place_sprite.setPosition(0, 0);

    sf::Sprite pieces_sprite;
    pieces_sprite.setTexture(pieces_texture);
    pieces_sprite.setColor(sf::Color(255, 255, 255, 200));
    pieces_sprite.setPosition(0, 0);

    Map map;
    sf::Vector2f mouse;
    sf::Vector2f offset_place(0, 0);
    sf::Vector2f size(100, 100);
    std::string move = "";

    bool is_first = true;

    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    mouse = {(event.mouseButton.x - offset_place.x) / size.x, 
                             (event.mouseButton.y - offset_place.y) / size.y};
                    sf::Vector2f number_of_cells = mouse;

                    if (is_first == true)
                    {
                        move = "";
                        move += (char)((int)number_of_cells.x + 'a');
                        move += (char)((int)number_of_cells.y + '1');
                    std::cout << move << "\n";
                        is_first = false;
                    }
                    else
                    {
                        is_first = true;
                        move += (char)((int)number_of_cells.x + 'a');
                        move += (char)((int)number_of_cells.y + '1');
                    std::cout << move << "|\n";
                        
                        map.tryMove(move);
                    }
                }
            }
        }
        map.tryMove("a2a4");

        window.draw(place_sprite);

        int offsety = 0;
        const auto& el = map.getMap();
        for (int i = 0; i < el.size(); ++i)
        {
            for (int j =0 ; j < el[0].size(); ++j)
            {
                if (el[i][j] != nullptr)
                {
                    offsety = 0;
                    if (el[i][j]->getColor() == ColorChessPiece::WHITE)
                    {
                        offsety = 50;
                    }

                    pieces_sprite.setTextureRect(sf::IntRect(50 * el[i][j]->getType(), offsety, 50, 50));
                    pieces_sprite.setPosition(sf::Vector2f(j * 100, i * 100));
                    pieces_sprite.setScale(sf::Vector2f(2, 2));
                    window.draw(pieces_sprite);
                    // element->getType()
                }
            }
        }

        window.display();
        //print(map);
    }
    return 0;
}


