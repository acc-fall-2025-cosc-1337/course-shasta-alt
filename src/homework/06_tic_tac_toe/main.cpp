#include <iostream>
#include <memory>
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

int main()
{
    TicTacToeManager manager;
    char choice;

    do
    {
        int game_type;
        std::cout << "Play TicTacToe 3 or 4? ";
        std::cin >> game_type;

        std::unique_ptr<TicTacToe> game;

        if (game_type == 3)
            game = std::make_unique<TicTacToe3>();
        else
            game = std::make_unique<TicTacToe4>();

        game->start_game("X");

        int position;
        while (!game->game_over())
        {
            game->display_board();
            std::cout << "Player " << game->get_player() << ", enter position: ";
            std::cin >> position;
            game->mark_board(position);
        }

        game->display_board();
        std::cout << "Winner: " << game->get_winner() << "\n";

        manager.save_game(game);

        std::cout << "Play again? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y');

    manager.display_games();
    return 0;
}
