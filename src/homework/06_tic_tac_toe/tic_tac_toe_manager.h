#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include <memory>
#include <vector>
#include "tic_tac_toe.h"

class TicTacToeManager
{
public:
    void save_game(std::unique_ptr<TicTacToe>& game);
    void display_games() const;

private:
    std::vector<std::unique_ptr<TicTacToe>> games;
};

#endif
