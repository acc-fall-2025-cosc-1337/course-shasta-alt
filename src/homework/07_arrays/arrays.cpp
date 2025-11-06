#include "tic_tac_toe.h"
#include <iostream>
#include <stdexcept>

void TicTacToe::start_game(std::string first_player)
{
    if (first_player != "X" && first_player != "O")
    {
        throw std::invalid_argument("first_player must be 'X' or 'O'");
    }
    player = first_player;
    winner.clear();
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    if (position < 1 || position > 9)
    {
        throw std::out_of_range("position must be 1..9");
    }
    std::size_t idx = static_cast<std::size_t>(position - 1);
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
        winner = "C";
        return true;
    }
    return false;
}

std::string TicTacToe::get_player() const
{
    return player;
}

void TicTacToe::display_board() const
{
    for (int r = 0; r < 3; ++r)
    {
        int i = r * 3;
        std::cout << " " << pegs[i] << " | " << pegs[i + 1] << " | " << pegs[i + 2] << "\n";
        if (r < 2) std::cout << "---+---+---\n";
    }
}

std::string TicTacToe::get_winner() const
{
    return winner;
}

bool TicTacToe::check_column_win() const
{
    // columns: 0,3,6  1,4,7  2,5,8
    for (int c = 0; c < 3; ++c)
    {
        const std::string& a = pegs[c];
        const std::string& b = pegs[c + 3];
        const std::string& d = pegs[c + 6];
        if (a != " " && a == b && b == d) return true;
    }
    return false;
}

bool TicTacToe::check_row_win() const
{
    // rows: 0,1,2  3,4,5  6,7,8
    for (int r = 0; r < 3; ++r)
    {
        int i = r * 3;
        const std::string& a = pegs[i];
        const std::string& b = pegs[i + 1];
        const std::string& d = pegs[i + 2];
        if (a != " " && a == b && b == d) return true;
    }
    return false;
}

bool TicTacToe::check_diagonal_win() const
{
    bool d1 = pegs[0] != " " && pegs[0] == pegs[4] && pegs[4] == pegs[8];
    bool d2 = pegs[6] != " " && pegs[6] == pegs[4] && pegs[4] == pegs[2];
    return d1 || d2;
}

bool TicTacToe::check_board_full() const
{
    for (const auto& s : pegs) if (s == " ") return false;
    return true;
}

void TicTacToe::set_next_player()
{
    player = (player == "X") ? "O" : "X";
}

void TicTacToe::clear_board()
{
    for (auto& s : pegs) s = " ";
}

void TicTacToe::set_winner()
{
    // mark_board already toggled player, so the opposite is the winner
    winner = (player == "X") ? "O" : "X";
}

