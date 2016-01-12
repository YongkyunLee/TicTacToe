#include <iostream>
#include "board.hpp"
#include "game.hpp"

using namespace std;

Game::Game()
{
  /*
  @brief constructor of the Game class
  */
}

void Game::run()
{
  /*
  @brief runs the game
  This function runs the game.

  @param board the board on which the game is played on

  @return none
  */
  Board board;
  bool ended = false;
  int pos = 0, turn = 0; // position the player selects

  board.print();
  while (!ended)
  {
    turn ++;
    //cout << board.query(9) << endl;
    if (turn % 2 == 1)
    {
      cout << "Player X's turn" << endl;
      cout << "Enter the box number to put your piece at: ";
      cin >> pos;
      board.place(pos, 1);
    }
    else // when player O's turn
    {
      cout << "Player O's turn" << endl;
      cout << "Enter the box number to put your piece at: ";
      cin >> pos;
      board.place(pos, 2);
    }
    board.print();

    if (board.checkWin() == 1)
    {
      cout << "Player X wins!" << endl;
      ended = true;
    }
    else if (board.checkWin() == 2)
    {
      cout << "Player O wins!" << endl;
      ended = true;
    }

    if (turn == 9)
    {
      if (board.checkDraw())
      {
        cout << "The game ends as a draw!" << endl;
      }
      ended = true;
    }
  }
}

/*int main(int argc, char ** argv)
{

}*/
