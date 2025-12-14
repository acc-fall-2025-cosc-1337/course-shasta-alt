#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <memory>
#include "tic_tac_toe_3.h"

TEST_CASE("Test first row win")
{
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe3>();

    board->start_game("X");
    board->mark_board(1);
    board->mark_board(4);
    board->mark_board(2);
    board->mark_board(5);
    board->mark_board(3);

    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}
