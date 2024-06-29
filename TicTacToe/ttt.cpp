#include <iostream>
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
        return '\0';
    }
}

void ShowField(const Game game)
{
    std::cout << "_________\n";
    int fieldSize = game.GetFieldSize();
    for (int i = 0; i < fieldSize; ++i)
    {
        std::cout << '|';
        for (int j = 0; j < fieldSize; ++j)
        {
            char sign = GetSignByValue(game.GetValueByPos(i, j));
            std::cout << (sign == '\0') ? (i * fieldSize + j + 1) : sign;
            std::cout << '|';
        }
        std::cout << '\n';
    }
    std::cout << "_________\n";
}

int main()
{
    int n, player = 1;
    std::cout << "Enter field size\n";
    std::cin >> n;

    Game game(n);
    while (!game.IsGameEnd())
    {
        ShowField(game);
        std::cout << "Enter next move\n";

        int move;
        std::cin >> move;
        --move;
        int xMove = move / n, yMove = move % n;
        if (move > n || game.GetValueByPos(xMove, yMove) != 0)
        {
            std::cout << "Incorrect move";
            continue;
        }

        game.MakeMove(xMove, yMove, (marks)player);
        player *= -1;
    }

    return 0;
}