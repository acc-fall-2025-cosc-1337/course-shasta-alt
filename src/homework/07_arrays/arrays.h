#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <string>
#include <vector>

class TicTacToe
{
public:
    void start_game(std::string first_player);
    void mark_board(int position);
    bool game_over();
    std::string get_player() const;
    void display_board() const;
    std::string get_winner() const;

private:
    bool check_column_win() const;
    bool check_row_win() const;
    bool check_diagonal_win() const;
    bool check_board_full() const;
    void set_next_player();
    void clear_board();
    void set_winner();

    std::string player;                   // "X" or "O"
    std::vector<std::string> pegs{9, " "}; // 9 spaces
    std::string winner;                   // "X", "O", or "C" for tie
};

#endif
