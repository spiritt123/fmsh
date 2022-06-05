#pragma once

#include "i_chess_rule.h"
#include "enums.h"

class ChessRuleForPawn : public IChessRule
{
public:
    ChessRuleForPawn();
    ~ChessRuleForPawn();

    bool canChessPieceMoved(const PairCoords &pair_coords, ColorChessPiece piece) const override;
    bool canChessPieceAttacked(const PairCoords &pair_coords, 
                               ColorChessPiece piece_color, 
                               ColorChessPiece target_color) const override;
};


class ChessRuleForBishop : public IChessRule
{
public:
    ChessRuleForBishop();
    ~ChessRuleForBishop();

    bool canChessPieceMoved(const PairCoords &pair_coords, ColorChessPiece piece) const override;
    bool canChessPieceAttacked(const PairCoords &pair_coords, 
                               ColorChessPiece piece_color, 
                               ColorChessPiece target_color) const override;
};

class ChessRuleForRook : public IChessRule
{
public:
    ChessRuleForRook();
    ~ChessRuleForRook();

    bool canChessPieceMoved(const PairCoords &pair_coords, ColorChessPiece piece) const override;
    bool canChessPieceAttacked(const PairCoords &pair_coords, 
                               ColorChessPiece piece_color, 
                               ColorChessPiece target_color) const override;
};

class ChessRuleForKing : public IChessRule
{
public:
    ChessRuleForKing();
    ~ChessRuleForKing();

    bool canChessPieceMoved(const PairCoords &pair_coords, ColorChessPiece piece) const override;
    bool canChessPieceAttacked(const PairCoords &pair_coords, 
                               ColorChessPiece piece_color, 
                               ColorChessPiece target_color) const override;
};

class ChessRuleForQueen : public IChessRule
{
public:
    ChessRuleForQueen();
    ~ChessRuleForQueen();

    bool canChessPieceMoved(const PairCoords &pair_coords, ColorChessPiece piece) const override;
    bool canChessPieceAttacked(const PairCoords &pair_coords, 
                               ColorChessPiece piece_color, 
                               ColorChessPiece target_color) const override;
};

class ChessRuleForKnight : public IChessRule
{
public:
    ChessRuleForKnight();
    ~ChessRuleForKnight();

    bool canChessPieceMoved(const PairCoords &pair_coords, ColorChessPiece piece) const override;
    bool canChessPieceAttacked(const PairCoords &pair_coords, 
                               ColorChessPiece piece_color, 
                               ColorChessPiece target_color) const override;
};

