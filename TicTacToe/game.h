#pragma once
#include "marks.h"

class Game;
typedef int (*getField)(Game, int, int);
class Game
{
public:
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
    marks CheckWinner() const;
    marks CheckLine(getField) const;
    marks CheckDiagonals() const;
};