
#include <iostream>
#include <stdexcept>
#include "marks.h"
#include "game.h"

typedef int (*getField)(Game, int, int);

class Getter
{
public:
    static int GetByRow(Game game, int i, int j)
    {
        return game.m_Field[i][j];
    }

    static int GetByColumn(Game game, int i, int j)
    {
        return game.m_Field[j][i];
    }
};

Game::Game(int fieldSize)
{
    m_FieldSize = fieldSize;
    m_Field = new marks *[fieldSize];
    m_IsGameEnd = false;
    m_MoveCount = 0;
    m_Winner = marks::none;

    for (int i = 0; i < fieldSize; ++i)
    {
        m_Field[i] = new marks[fieldSize];
    }
}

bool Game::MakeMove(int &x, int &y, marks &player)
{
    if (x >= m_FieldSize && y >= m_FieldSize)
    {
        throw std::invalid_argument("Selected coordinate out of range");
    }

    if (m_Field[x][y] != marks::none)
    {
        return false;
    }

    m_Field[x][y] = player;
    ++m_MoveCount;

    return true;
}

bool Game::IsGameEnd() const
{
    return m_IsGameEnd;
}

Game::~Game()
{
    for (int i = 0; i < m_FieldSize; ++i)
    {
        delete[] m_Field[i];
    }

    delete[] m_Field;
}

marks Game::CheckWinner()
{
    if (m_MoveCount < m_FieldSize)
    {
        return marks::none;
    }

    marks WinByRow = CheckLine(&Getter::GetByRow);
    marks WinByColumn = CheckLine(&Getter::GetByColumn);
};

marks Game::CheckLine(getField get)
{
    for (int i = 0; i < m_FieldSize; ++i)
    {
        int winner = 0;
        for (int j = 0; j < m_FieldSize; ++j)
        {
            winner += get(*this, i, j);
        }
        if (std::abs(winner) == m_FieldSize)
        {
            return (winner > 0) ? marks::cross : marks::naught;
        }
    }

    return marks::none;
}
