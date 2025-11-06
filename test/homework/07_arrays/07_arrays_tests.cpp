#include <cassert>
#include <iostream>
#include "tic_tac_toe.h"

// small helper to show progress then assert
static void check(bool cond, const char* msg)
{
    if (!cond)
    {
        std::cerr << "[FAIL] " << msg << "\n";
        std::abort();
    }
}

int main()
{
    // First player X
    {
        TicTacToe g; g.start_game("X");
        check(g.get_player() == "X", "first player should be X");
    }
    // First player O
    {
        TicTacToe g; g.start_game("O");
        check(g.get_player() == "O", "first player should be O");
    }
    // Win by first column 1,4,7
    {
        TicTacToe g; g.start_game("X");
        g.mark_board(1); check(!g.game_over(), "after 1 move not over");
        g.mark_board(2); check(!g.game_over(), "after 2 moves not over");
        g.mark_board(4); check(!g.game_over(), "after 3 moves not over");
        g.mark_board(3); check(!g.game_over(), "after 4 moves not over");
        g.mark_board(7); check(g.game_over(), "should be over");
        check(g.get_winner() == "X", "winner should be X");
    }
    // Win by second column 2,5,8
    {
        TicTacToe g; g.start_game("X");
        g.mark_board(2); check(!g.game_over(), "not over");
        g.mark_board(1); check(!g.game_over(), "not over");
        g.mark_board(5); check(!g.game_over(), "not over");
        g.mark_board(3); check(!g.game_over(), "not over");
        g.mark_board(8); check(g.game_over(), "over");
        check(g.get_winner() == "X", "winner X");
    }
    // Win by third column 3,6,9
    {
        TicTacToe g; g.start_game("X");
        g.mark_board(3); check(!g.game_over(), "not over");
        g.mark_board(1); check(!g.game_over(), "not over");
        g.mark_board(6); check(!g.game_over(), "not over");
        g.mark_board(2); check(!g.game_over(), "not over");
        g.mark_board(9); check(g.game_over(), "over");
        check(g.get_winner() == "X", "winner X");
    }
    // Win by first row 1,2,3
    {
        TicTacToe g; g.start_game("X");
        g.mark_board(1); check(!g.game_over(), "not over");
        g.mark_board(4); check(!g.game_over(), "not over");
        g.mark_board(2); check(!g.game_over(), "not over");
        g.mark_board(5); check(!g.game_over(), "not over");
        g.mark_board(3); check(g.game_over(), "over");
        check(g.get_winner() == "X", "winner X");
    }
    // Win by second row 4,5,6
    {
        TicTacToe g; g.start_game("X");
        g.mark_board(4); check(!g.game_over(), "not over");
        g.mark_board(1); check(!g.game_over(), "not over");
        g.mark_board(5); check(!g.game_over(), "not over");
        g.mark_board(2); check(!g.game_over(), "not over");
        g.mark_board(6); check(g.game_over(), "over");
        check(g.get_winner() == "X", "winner X");
    }
    // Win by third row 7,8,9
    {
        TicTacToe g; g.start_game("X");
        g.mark_board(7); check(!g.game_over(), "not over");
        g.mark_board(1); check(!g.game_over(), "not over");
        g.mark_board(8); check(!g.game_over(), "not over");
        g.mark_board(2); check(!g.game_over(), "not over");
        g.mark_board(9); check(g.game_over(), "over");
        check(g.get_winner() == "X", "winner X");
    }
    // Win diagonal 1,5,9
    {
        TicTacToe g; g.start_game("X");
        g.mark_board(1); check(!g.game_over(), "not over");
        g.mark_board(2); check(!g.game_over(), "not over");
        g.mark_board(5); check(!g.game_over(), "not over");
        g.mark_board(3); check(!g.game_over(), "not over");
        g.mark_board(9); check(g.game_over(), "over");
        check(g.get_winner() == "X", "winner X");
    }
    // Win diagonal 7,5,3
    {
        TicTacToe g; g.start_game("X");
        g.mark_board(7); check(!g.game_over(), "not over");
        g.mark_board(1); check(!g.game_over(), "not over");
        g.mark_board(5); check(!g.game_over(), "not over");
        g.mark_board(2); check(!g.game_over(), "not over");
        g.mark_board(3); check(g.game_over(), "over");
        check(g.get_winner() == "X", "winner X");
    }
    // Tie C
    {
        TicTacToe g; g.start_game("X");
        int seq[] = {1,2,3,5,4,6,8,7,9}; // full board no 3-in-a-row
        for (int i = 0; i < 9; ++i)
        {
            g.mark_board(seq[i]);
            if (i < 8) check(!g.game_over(), "not over yet");
        }
        check(g.game_over(), "tie ends game");
        check(g.get_winner() == "C", "winner C");
    }

    std::cout << "All tests passed.\n";
    return 0;
}



