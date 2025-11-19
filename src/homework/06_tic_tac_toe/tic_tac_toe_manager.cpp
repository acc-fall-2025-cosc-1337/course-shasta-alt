#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(TicTacToe game)
{
    std::string winner = game.get_winner();
    update_winner_count(winner);
    games.push_back(game);
}

void TicTacToeManager::update_winner_count(std::string winner)
{
    if (winner == "X")
    {
        x_win++;
    }
    else if (winner == "O")
    {
        o_win++;
    }
    else
    {
        ties++;
    }
}

void TicTacToeManager::get_winner_total(int& x, int& o, int& t)
{
    x = x_win;
    o = o_win;
    t = ties;
}
