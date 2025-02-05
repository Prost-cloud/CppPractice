#include <iostream>
#include <iomanip>
#include "game.h"

char GetSignByValue(int value)
{
    switch (value)
    {
    case 1:
        return 'x';
    case -1:
        return 'o';
    default:
        return '0';
    }
}

void ShowField(TicTacToeGame::Game &game)
{
    std::cout << "_________" << std::endl;
    int fieldSize = game.GetFieldSize();
    for (int i = 0; i < fieldSize; ++i)
    {
        std::cout << '|';
        for (int j = 0; j < fieldSize; ++j)
        {
            char sign = GetSignByValue(game.GetValueByPos(i, j));
            int writeInt = i * fieldSize + j + 1;
            std::cout << std::setw(2);
            if (sign == '0')
            {
                std::cout << writeInt;
            }
            else
            {
                std::cout << sign;
            }
            std::cout << '|';
        }

        std::cout << std::endl;
    }

    std::cout << "_________" << std::endl;
}

int main()
{
    int fieldSize, player = 1;
    std::cout << "Enter field size" << std::endl;
    std::cin >> fieldSize;
    TicTacToeGame::Game game(fieldSize);

    while (!game.IsGameEnd())
    {
        ShowField(game);
        std::cout << "Enter next move " << std::endl;

        int move;
        std::cin >> move;
        --move;
        int xMove = move / fieldSize;
        int yMove = move % fieldSize;
        if (move > fieldSize * fieldSize || game.GetValueByPos(xMove, yMove) != 0)
        {
            std::cout << "Incorrect move" << std::endl;
            continue;
        }

        game.MakeMove(xMove, yMove, (TicTacToeGame::marks)player);
        player *= -1;
    }

    return 0;
}