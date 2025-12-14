#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <vector>
#include <string>

class TicTacToe
{
public:
    TicTacToe(int size);
    void start_game(std::string first_player);
    void mark_board(int position);
    bool game_over();
    std::string get_player() const;
    std::string get_winner() const;

protected:
    std::vector<std::string> pegs;
    std::string player;
    std::string winner;

    virtual bool check_row_win();
    virtual bool check_column_win();
    virtual bool check_diagonal_win();

private:
    bool check_board_full();
    void set_next_player();
};

#endif
