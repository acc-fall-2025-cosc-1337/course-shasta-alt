#include "tic_tac_toe.h"
#include <iostream>
#include <limits>
#include <cctype>

int main()
{
    TicTacToe game;
    char again = 'y';

    while (std::tolower(again) == 'y')
    {
        // choose first player
        std::string first;
        while (true)
        {
            std::cout << "Start game. Choose first player (X or O): ";
            std::cin >> first;
            if (first == "X" || first == "O") break;
            std::cout << "Invalid. Enter X or O.\n";
        }

        game.start_game(first);

        // play until game over
        while (!game.game_over())
        {
            int pos = 0;
            while (true)
            {
                std::cout << "Enter position 1-9: ";
                if (!(std::cin >> pos))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Try again.\n";
                    continue;
                }
                if (pos < 1 || pos > 9)
                {
                    std::cout << "Position must be 1-9. Try again.\n";
                    continue;
                }
                try
                {
                    game.mark_board(pos);
                    break;
                }
                catch (const std::exception& e)
                {
                    std::cout << e.what() << " Try another spot.\n";
                }
            }

            game.display_board();
            std::cout << "\n";
        }

        std::string w = game.get_winner();
        if (w == "C")
            std::cout << "Result: Tie game.\n";
        else
            std::cout << "Winner: " << w << "\n";

        std::cout << "Play again? (y/n): ";
        std::cin >> again;
        std::cout << "\n";
    }

    std::cout << "Goodbye.\n";
    return 0;
}
