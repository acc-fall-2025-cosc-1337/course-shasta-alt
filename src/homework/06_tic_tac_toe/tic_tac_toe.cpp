#include "tic_tac_toe.h"

bool TicTacToe::game_over()
{
    if (check_row_win())
    {
        set_winner();
        return true;
    }
    if (check_column_win())
    {
        set_winner();
        return true;
    }
    if (check_diagonal_win())
    {
        set_winner();
        return true;
    }

    if (check_board_full())
    {
        winner = "C";   // tie
        return true;
    }

    return false;
}

void TicTacToe::start_game(std::string first_player)
{
    if (first_player == "X" || first_player == "O")
    {
        player = first_player;
        clear_board();
        winner = " ";
    }
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

std::string TicTacToe::get_player() const
{
    return player;
}

void TicTacToe::display_board() const
{
    for (int i = 0; i < 9; ++i)
    {
        std::cout << pegs[i];
        if ((i + 1) % 3 == 0)
            std::cout << "\n";
        else
            std::cout << " | ";
    }
}

std::string TicTacToe::get_winner() const
{
    return winner;
}

void TicTacToe::set_next_player()
{
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full()
{
    for (const auto& p : pegs)
        if (p == " ") return false;

    return true;
}

void TicTacToe::clear_board()
{
    for (auto& p : pegs)
        p = " ";
}

bool TicTacToe::check_row_win()
{
    return
        (pegs[0] != " " && pegs[0] == pegs[1] && pegs[1] == pegs[2]) ||
        (pegs[3] != " " && pegs[3] == pegs[4] && pegs[4] == pegs[5]) ||
        (pegs[6] != " " && pegs[6] == pegs[7] && pegs[7] == pegs[8]);
}

bool TicTacToe::check_column_win()
{
    return
        (pegs[0] != " " && pegs[0] == pegs[3] && pegs[3] == pegs[6]) ||
        (pegs[1] != " " && pegs[1] == pegs[4] && pegs[4] == pegs[7]) ||
        (pegs[2] != " " && pegs[2] == pegs[5] && pegs[5] == pegs[8]);
}

bool TicTacToe::check_diagonal_win()
{
    return
        (pegs[0] != " " && pegs[0] == pegs[4] && pegs[4] == pegs[8]) ||
        (pegs[2] != " " && pegs[2] == pegs[4] && pegs[4] == pegs[6]);
}

void TicTacToe::set_winner()
{
    // Last player who marked is opposite of current turn
    winner = (player == "X") ? "O" : "X";
}
