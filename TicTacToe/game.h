#pragma once
#include "marks.h"

class Game
{
public:
    Game(int fieldSize);
    bool MakeMove(int &x, int &y, marks &player);
    bool IsGameEnd() const;
    ~Game();

private:
    marks **m_Field;
    int m_FieldSize;
    bool m_IsGameEnd;
    marks m_Winner;
    int m_MoveCount;
    marks CheckWinner();
    marks CheckLine(getField get);
    friend class Getter;
};