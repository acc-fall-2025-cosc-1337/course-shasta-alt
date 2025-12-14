#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>& game)
{
    games.push_back(std::move(game));
}

void TicTacToeManager::display_games() const
{
    for (const auto& game : games)
    {
        game->display_board();
        std::cout << "Winner: " << game->get_winner() << "\n\n";
    }
}
