#pragma once
#include "marks.h"

class Game;
typedef int (*getField)(Game, int, int);
class Game
{
public:
    Game(int);
    Game(const Game &);
    bool MakeMove(int, int, marks);
    bool IsGameEnd() const;
    int GetValueByPos(int, int) const;
    int GetFieldSize() const;
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