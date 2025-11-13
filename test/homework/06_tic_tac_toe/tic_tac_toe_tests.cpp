#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Test first player set to X")
{
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
    TicTacToe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test tie game")
{
    TicTacToe game;
    game.start_game("X");

    int moves[] = {1,2,3,4,5,7,6,9,8};

    for (int m : moves)
        game.mark_board(m);

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Win by first column")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); game.mark_board(2);
    game.mark_board(4); game.mark_board(3);
    game.mark_board(7);

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Win by second column")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(2); game.mark_board(1);
    game.mark_board(5); game.mark_board(3);
    game.mark_board(8);

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Win by third column")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(3); game.mark_board(1);
    game.mark_board(6); game.mark_board(2);
    game.mark_board(9);

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Win by first row")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); game.mark_board(4);
    game.mark_board(2); game.mark_board(5);
    game.mark_board(3);

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Win by second row")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(4); game.mark_board(1);
    game.mark_board(5); game.mark_board(2);
    game.mark_board(6);

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Win by third row")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(7); game.mark_board(1);
    game.mark_board(8); game.mark_board(2);
    game.mark_board(9);

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Win diagonal 1-5-9")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); game.mark_board(2);
    game.mark_board(5); game.mark_board(3);
    game.mark_board(9);

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Win diagonal 7-5-3")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(7); game.mark_board(1);
    game.mark_board(5); game.mark_board(2);
    game.mark_board(3);

    REQUIRE(game.game_over() == true);
}
