#include "tic_tac_toe.h"
#include <cassert>
#include <iostream>
using namespace std;

int main()
{
    TicTacToe game;
    game.start_game("X");

    int positions[] = {1, 2, 3, 4, 5, 7, 6, 9, 8};

    for (int pos : positions)
    {
        game.mark_board(pos);
        bool over = game.game_over();
        cout << "After position " << pos << " - game over: " << (over ? "true" : "false") << endl;
    }

    assert(game.game_over() == true);
    cout << "✅ Test passed: Game ends after all 9 positions filled.\n";
}


