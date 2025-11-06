#include "tic_tac_toe.h"
#include <iostream>
#include <stdexcept>
using std::string;
using std::vector;

void TicTacToe::start_game(string first_player)
{
    if (first_player != "X" && first_player != "O")
    {
        throw std::invalid_argument("first_player must be X or O");
    }
    player = first_player;
    clear_board();
    winner.clear();
}

void TicTacToe::mark_board(int position)
{
    // position is 1-9
    int idx = position - 1;
    if (idx < 0 || idx >= static_cast<int>(pegs.size()))
    {
        throw std::out_of_range("position must be 1-9");
    }
    if (pegs[idx] != " ")
    {
        throw std::logic_error("position already taken");
    }

    pegs[idx] = player;
    set_next_player();
}

bool TicTacToe::game_over()
{
    if (check_row_win() || check_column_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    }

    if (check_board_full())
    {
        winner = "C"; // tie
        return true;
    }

    return false;
}

string TicTacToe::get_player() const
{
    return player;
}

void TicTacToe::display_board() const
{
    // Simple 3x3 print
    for (int i = 0; i < 9; i += 3)
    {
        std::cout << " " << pegs[i] << " | " << pegs[i + 1] << " | " << pegs[i + 2] << "\n";
        if (i < 6) std::cout << "---+---+---\n";
    }
}

string TicTacToe::get_winner() const
{
    return winner;
}

// private helpers

bool TicTacToe::check_column_win()
{
    // columns: (0,3,6), (1,4,7), (2,5,8)
    for (int c = 0; c < 3; ++c)
    {
        const string& a = pegs[c];
        const string& b = pegs[c + 3];
        const string& d = pegs[c + 6];
        if (a != " " && a == b && b == d) return true;
    }
    return false;
}

bool TicTacToe::check_row_win()
{
    // rows: (0,1,2), (3,4,5), (6,7,8)
    for (int r = 0; r < 9; r += 3)
    {
        const string& a = pegs[r];
        const string& b = pegs[r + 1];
        const string& d = pegs[r + 2];
        if (a != " " && a == b && b == d) return true;
    }
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    // diagonals: (0,4,8) and (6,4,2)
    if (pegs[0] != " " && pegs[0] == pegs[4] && pegs[4] == pegs[8]) return true;
    if (pegs[6] != " " && pegs[6] == pegs[4] && pegs[4] == pegs[2]) return true;
    return false;
}

bool TicTacToe::check_board_full()
{
    for (const auto& p : pegs)
    {
        if (p == " ") return false;
    }
    return true;
}

void TicTacToe::set_next_player()
{
    if (player == "X")
        player = "O";
    else
        player = "X";
}

void TicTacToe::clear_board()
{
    for (auto& p : pegs) p = " ";
}

void TicTacToe::set_winner()
{
    // winner is the player who played last which is the opposite of current player
    if (player == "X")
        winner = "O";
    else
        winner = "X";
}
