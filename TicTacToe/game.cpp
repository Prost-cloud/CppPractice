
#include <iostream>
#include <stdexcept>
#include "marks.h"
#include "game.h"

static int GetByRow(Game game, int i, int j)
{
    return game.GetValueByPos(i, j);
}

static int GetByColumn(Game game, int i, int j)
{
    return game.GetValueByPos(j, i);
}

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
        for (int j = 0; j < fieldSize; ++j)
        {
            m_Field[i][j] = marks::none;
        }
    }
}

bool Game::MakeMove(const int &x, const int &y, marks player)
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

marks Game::CheckDiagonals() const
{
    int diag = 0, revDiag = 0;

    for (int i = 0; i < m_FieldSize; i++)
    {
        diag += m_Field[i][i];
        revDiag += m_Field[i][m_FieldSize - 1 - i];
    }

    if (std::abs(diag) == m_FieldSize)
    {
        return (diag > 0) ? marks::cross : marks::naught;
    }

    if (std::abs(revDiag) == m_FieldSize)
    {
        return (revDiag > 0) ? marks::cross : marks::naught;
    }

    return marks::none;
}

marks Game::CheckLine(getField get) const
{
    for (int i = 0; i < m_FieldSize; ++i)
    {
        int pointsInRow = 0;
        for (int j = 0; j < m_FieldSize; ++j)
        {
            pointsInRow += get(*this, i, j);
        }

        if (std::abs(pointsInRow) == m_FieldSize)
        {
            return (pointsInRow > 0) ? marks::cross : marks::naught;
        }
    }

    return marks::none;
}

marks Game::CheckWinner() const
{
    if (m_MoveCount < m_FieldSize)
    {
        return marks::none;
    }

    marks WinByRow = CheckLine(GetByRow);
    marks WinByColumn = CheckLine(GetByColumn);
    marks WinByDiagonal = CheckDiagonals();

    return (marks)(WinByRow | WinByColumn | WinByDiagonal);
}

int Game::GetValueByPos(int i, int j) const
{
    return m_Field[i][j];
}

int Game::GetFieldSize() const
{
    return m_FieldSize;
}
