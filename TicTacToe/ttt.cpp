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

void ShowField(const Game game)
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
    int n, player = 1;
    std::cout << "Enter field size" << std::endl;
    std::cin >> n;
    Game game(n);

    while (!game.IsGameEnd())
    {
        ShowField(game);
        std::cout << "Enter next move " << std::endl;

        int move;
        std::cin >> move;
        --move;
        int xMove = move / n;
        int yMove = move % n;
        if (move > n * n || game.GetValueByPos(xMove, yMove) != 0)
        {
            std::cout << "Incorrect move" << std::endl;
            continue;
        }

        game.MakeMove(xMove, yMove, (marks)player);
        player *= -1;
    }

    return 0;
}