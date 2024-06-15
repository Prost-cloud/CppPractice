#pragma once
#include "marks.h"

class Game
{
public:
#ifndef typedefGetField
#define typedefGetField
    // int (*getField)(Game, int, int);
    typedef int (*getField)(Game, int, int);
#endif
    Game(int fieldSize);
    bool MakeMove(int &x, int &y, marks &player);
    bool IsGameEnd() const;
    int GetValueByPos(int, int) const;
    ~Game();

private:
    marks **m_Field;
    int m_FieldSize;
    bool m_IsGameEnd;
    marks m_Winner;
    int m_MoveCount;
    marks CheckWinner();
    marks CheckLine(getField);
};