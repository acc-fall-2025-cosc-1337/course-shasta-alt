#include "tic_tac_toe.h"
#include <iostream>
int main() {
  TicTacToe game;
  std::string first;
  std::cout << "Enter first player (X or O): ";
  std::cin >> first;
  game.start_game(first);
  while (!game.game_over()) {
    int pos;
    std::cout << "Enter position (1-9): ";
    std::cin >> pos;
    game.mark_board(pos);
    game.display_board();
    std::cout << "\n";
  }
  std::cout << "Game over\n";
  return 0;
}
