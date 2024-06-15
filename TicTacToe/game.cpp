
#include <iostream>
#include <stdexcept>
#include "marks.h"
#include "game.h"

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

static int GetByRow(Game game, int i, int j)
{
    return game.GetValueByPos(i, j);
}

static int GetByColumn(Game game, int i, int j)
{
    return game.GetValueByPos(j, i);
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

marks Game::CheckWinner()
{
    if (m_MoveCount < m_FieldSize)
    {
        return marks::none;
    }

    marks WinByRow = CheckLine(GetByRow);
    marks WinByColumn = CheckLine(GetByColumn);

    // return (marks)(WinByRow | WinByColumn);
    return (marks)(WinByRow | WinByColumn);
}

int Game::GetValueByPos(int i, int j) const
{
    return m_Field[i][j];
}
