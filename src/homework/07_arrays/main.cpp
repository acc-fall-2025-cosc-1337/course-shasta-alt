#include "tic_tac_toe.h"
#include <iostream>
#include <limits>
#include <string>

static int read_position()
{
    int pos{};
    while (true)
    {
        std::cout << "Enter position 1..9: ";
        if (std::cin >> pos && pos >= 1 && pos <= 9) return pos;
        std::cout << "Invalid position. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

static std::string read_first_player()
{
    std::string p;
    while (true)
    {
        std::cout << "Who starts the game, X or O? ";
        if (std::cin >> p)
        {
            if (p == "X" || p == "O") return p;
        }
        std::cout << "Please enter X or O.\n";
    }
}

int main()
{
    std::cout << "TicTacToe\n";
    bool play_again = true;

    while (play_again)
    {
        TicTacToe game;
        try
        {
            auto first = read_first_player();
            game.start_game(first);
        }
        catch (const std::exception& ex)
        {
            std::cout << "Error: " << ex.what() << "\n";
            continue;
        }

        while (!game.game_over())
        {
            game.display_board();
            std::cout << "Current player: " << game.get_player() << "\n";
            try
            {
                game.mark_board(read_position());
            }
            catch (const std::exception& ex)
            {
                std::cout << "Invalid move: " << ex.what() << "\n";
            }
        }

        std::cout << "\nFinal board:\n";
        game.display_board();

        std::string w = game.get_winner();
        if (w == "C") std::cout << "Result: Tie game\n";
        else std::cout << "Winner: " << w << "\n";

        std::cout << "Play again? (y/n): ";
        char ans{};
        std::cin >> ans;
        play_again = (ans == 'y' || ans == 'Y');
    }
    std::cout << "Goodbye\n";
    return 0;
}

