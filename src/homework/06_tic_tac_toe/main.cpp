#include "tic_tac_toe.h"
#include <iostream>

int main()
{
    TicTacToe game;
    std::string first;
    char again = 'Y';

    while (again == 'Y' || again == 'y')
    {
        do
        {
            std::cout << "Enter first player (X or O): ";
            std::cin >> first;
        }
        while (first != "X" && first != "O");

        game.start_game(first);

        int position = 0;

        while (!game.game_over())
        {
            std::cout << "Enter position (1-9): ";
            std::cin >> position;
            game.mark_board(position);
            game.display_board();
        }

        std::cout << "Winner: " << game.get_winner() << "\n";

        std::cout << "Play again? (Y/N): ";
        std::cin >> again;
    }

    return 0;
}
