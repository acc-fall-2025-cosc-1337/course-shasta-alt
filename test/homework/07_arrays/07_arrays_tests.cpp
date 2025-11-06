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

TEST_CASE("Test game over tie with 9 moves winner C")
{
    TicTacToe game;
    game.start_game("X");

    // A common tie sequence
    int moves[] = {1,2,3,5,4,6,8,7,9};
    for (int i = 0; i < 9; ++i)
    {
        game.mark_board(moves[i]);
        if (i < 8) REQUIRE(game.game_over() == false);
    }
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test win by first column")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); REQUIRE_FALSE(game.game_over());
    game.mark_board(2); REQUIRE_FALSE(game.game_over());
    game.mark_board(4); REQUIRE_FALSE(game.game_over());
    game.mark_board(5); REQUIRE_FALSE(game.game_over());
    game.mark_board(7); REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second column")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(2); REQUIRE_FALSE(game.game_over());
    game.mark_board(1); REQUIRE_FALSE(game.game_over());
    game.mark_board(5); REQUIRE_FALSE(game.game_over());
    game.mark_board(3); REQUIRE_FALSE(game.game_over());
    game.mark_board(8); REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third column")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(3); REQUIRE_FALSE(game.game_over());
    game.mark_board(1); REQUIRE_FALSE(game.game_over());
    game.mark_board(6); REQUIRE_FALSE(game.game_over());
    game.mark_board(2); REQUIRE_FALSE(game.game_over());
    game.mark_board(9); REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by first row")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); REQUIRE_FALSE(game.game_over());
    game.mark_board(4); REQUIRE_FALSE(game.game_over());
    game.mark_board(2); REQUIRE_FALSE(game.game_over());
    game.mark_board(5); REQUIRE_FALSE(game.game_over());
    game.mark_board(3); REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second row")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(4); REQUIRE_FALSE(game.game_over());
    game.mark_board(1); REQUIRE_FALSE(game.game_over());
    game.mark_board(5); REQUIRE_FALSE(game.game_over());
    game.mark_board(2); REQUIRE_FALSE(game.game_over());
    game.mark_board(6); REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third row")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(7); REQUIRE_FALSE(game.game_over());
    game.mark_board(1); REQUIRE_FALSE(game.game_over());
    game.mark_board(8); REQUIRE_FALSE(game.game_over());
    game.mark_board(2); REQUIRE_FALSE(game.game_over());
    game.mark_board(9); REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1); REQUIRE_FALSE(game.game_over());
    game.mark_board(2); REQUIRE_FALSE(game.game_over());
    game.mark_board(5); REQUIRE_FALSE(game.game_over());
    game.mark_board(3); REQUIRE_FALSE(game.game_over());
    game.mark_board(9); REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(7); REQUIRE_FALSE(game.game_over());
    game.mark_board(1); REQUIRE_FALSE(game.game_over());
    game.mark_board(5); REQUIRE_FALSE(game.game_over());
    game.mark_board(2); REQUIRE_FALSE(game.game_over());
    game.mark_board(3); REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}


