#include "tic_tac_toe.h"

TicTacToe::TicTacToe(int size) : pegs(size * size, " ") {}

void TicTacToe::start_game(std::string first_player)
{
    player = first_player;
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::set_next_player()
{
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full()
{
    for (auto peg : pegs)
        if (peg == " ")
            return false;
    return true;
}

bool TicTacToe::game_over()
{
    if (check_row_win() || check_column_win() || check_diagonal_win())
    {
        winner = (player == "X") ? "O" : "X";
        return true;
    }

    if (check_board_full())
    {
        winner = "C";
        return true;
    }

    return false;
}

std::string TicTacToe::get_player() const { return player; }
std::string TicTacToe::get_winner() const { return winner; }

bool TicTacToe::check_row_win() { return false; }
bool TicTacToe::check_column_win() { return false; }
bool TicTacToe::check_diagonal_win() { return false; }
