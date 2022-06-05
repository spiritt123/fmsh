#include "map.h"
#include "enums.h"
#include "simple_chess_rule.h"

#include <iostream>

Map::Map(uint32_t size)
    : _state(StateChess::WHITES_MOVE)
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

const std::vector<std::vector<ChessPiece*>>& Map::getMap()
{
    return _map;
}

PairCoords Map::ConvertMoveToPairCoords(std::string move, bool &result_convertation)
{
// string have formate: "e4 d5";
    char buffer_piece, buffer_target;
    PairCoords answer;
    if (sscanf(move.c_str(), 
               "%c%d%c%d", 
               &buffer_piece, &answer.piecey, 
               &buffer_target, &answer.targety) != 4)
    {
        //error scaning;
        result_convertation = false;
        return answer;
    }

    answer.piecex  = buffer_piece  - 'a';
    --answer.piecey;
    answer.targetx = buffer_target - 'a';
    --answer.targety;

    if (answer.targetx < 0 || answer.targetx > 7 || 
        answer.targety < 0 || answer.targety > 7)
    {
        result_convertation = false;
        return answer;
    }

    if (_map[answer.piecey][answer.piecex] == nullptr)
    {
        result_convertation = false;
        return answer;
    }
    
    result_convertation = true;
    return answer;
}

bool Map::isCoodsBelongMap(uint32_t x, uint32_t y) const
{
    if (x < 0 || y < 0)
    {
        return false;
    }    
    if (y > _map.size() || x > _map[0].size())
    {
        return false;
    }

    return true;
}

ChessPiece* Map::getChessPieceByCoords(uint32_t x, uint32_t y) const
{
    if (isCoodsBelongMap(x, y) == true)
    {
        return _map[y][x];
    }
    return nullptr;
}

void Map::tryMove(std::string move)
{
    bool is_correct_coords = false;
    PairCoords coords = ConvertMoveToPairCoords(move, is_correct_coords);
    if (is_correct_coords == false)
    {
        _state = getNewState(StateSignal::ERROR);
        return ;
    }

    ChessPiece *target = _map[coords.targety][coords.targetx];
    ChessPiece *piece  = _map[coords.piecey][coords.piecex];

    if (target == nullptr && piece->canMove(coords, piece->getColor()) == true)
    {
        target = piece;
        piece = nullptr;
    }
    else if (target != nullptr && 
            piece->canAttack(coords, piece->getColor(), target->getColor()) == true)
    {
        delete target;
        target = piece;
        piece = nullptr;
    }
    else
    {
        _state = getNewState(StateSignal::ERROR);
        return ;
    }
    
    _map[coords.targety][coords.targetx] = target;
    _map[coords.piecey][coords.piecex]   = piece;  

    _state = getNewState(StateSignal::SUCCESS);
}
    
StateChess Map::getNewState(StateSignal signal)
{
//signal //success                | error
    StateChess states_map[2][2] = {
/*s*/   {StateChess::BLACKS_MOVE,  StateChess::WHITES_MOVE},         // white move
/*t*/   {StateChess::WHITES_MOVE,  StateChess::BLACKS_MOVE}          // black move
/*a*/
/*t*/
/*e*/};
    return states_map[_state][signal];
}


void Map::Init()
{
    for (uint32_t i = 0; i < 8; ++i)
    {
        _map[1][i] = new ChessPiece(new ChessRuleForPawn(), ColorChessPiece::WHITE, TypesChessPiece::PAWN);
        _map[6][i] = new ChessPiece(new ChessRuleForPawn(), ColorChessPiece::BLACK, TypesChessPiece::PAWN);
    }
    _map[0][0] = new ChessPiece(new ChessRuleForRook(), ColorChessPiece::WHITE, TypesChessPiece::ROOK);
    _map[0][1] = new ChessPiece(new ChessRuleForKnight(), ColorChessPiece::WHITE, TypesChessPiece::KNIGHT);
    _map[0][2] = new ChessPiece(new ChessRuleForBishop(), ColorChessPiece::WHITE, TypesChessPiece::BISHOP);
    _map[0][3] = new ChessPiece(new ChessRuleForQueen(), ColorChessPiece::WHITE, TypesChessPiece::QUEEN);
    _map[0][4] = new ChessPiece(new ChessRuleForKing(), ColorChessPiece::WHITE, TypesChessPiece::KING);
    _map[0][5] = new ChessPiece(new ChessRuleForBishop(), ColorChessPiece::WHITE, TypesChessPiece::BISHOP);
    _map[0][6] = new ChessPiece(new ChessRuleForKnight(), ColorChessPiece::WHITE, TypesChessPiece::KNIGHT);
    _map[0][7] = new ChessPiece(new ChessRuleForRook(), ColorChessPiece::WHITE, TypesChessPiece::ROOK);
    _map[7][0] = new ChessPiece(new ChessRuleForRook(), ColorChessPiece::BLACK, TypesChessPiece::ROOK);
    _map[7][1] = new ChessPiece(new ChessRuleForKnight(), ColorChessPiece::BLACK, TypesChessPiece::KNIGHT);
    _map[7][2] = new ChessPiece(new ChessRuleForBishop(), ColorChessPiece::BLACK, TypesChessPiece::BISHOP);
    _map[7][3] = new ChessPiece(new ChessRuleForQueen(), ColorChessPiece::BLACK, TypesChessPiece::QUEEN);
    _map[7][4] = new ChessPiece(new ChessRuleForKing(), ColorChessPiece::BLACK, TypesChessPiece::KING);
    _map[7][5] = new ChessPiece(new ChessRuleForBishop(), ColorChessPiece::BLACK, TypesChessPiece::BISHOP);
    _map[7][6] = new ChessPiece(new ChessRuleForKnight(), ColorChessPiece::BLACK, TypesChessPiece::KNIGHT);
    _map[7][7] = new ChessPiece(new ChessRuleForRook(), ColorChessPiece::BLACK, TypesChessPiece::ROOK);
}





