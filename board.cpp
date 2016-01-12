#include <iostream>
#include <stdlib.h>
#include <string>
#include "board.hpp"

using namespace std;

Board::Board()
{
  /*
  @brief Constructor of Board class

  intializes the "squares" variable to an array of nine 0s
  For this program, 0 expresses "unoccupied" state, 1 expresses "X" state,
  and 2 expresses "O" state.
  */
  for (int i = 0; i < 9; i++)
  {
    squares[i] = 0;
  }
}

int Board::query(int coord)
{
  /*
  @brief Tells the state of requested square

  This function receives the coordinate to be looked at, and returns the state
  of the coordinate. The possible states are unoccupied (expressed as int 0),
  X (expressed as int 1), and O (expressed as int 2).
  The coordinate is going to be an integer from 1 to 9. It would be traditional
  to use two numbers as a coordinate, but to make the matters simpler,
  this program will use one integer to express the coordinate.

  @param coord the coordinate to be looked at - an integer from 1 to 9.

  @return 0, 1, or 2 each representing "unoccupied," "X," or "O" respectively.
  */
  int state = 0;
  state = squares[coord - 1];
  return state;
}

void Board::place(int coord, int piece)
{
  /*
  @brief Places a given piece on the board

  This function places a given piece on a given coordinate. It changes
  an element of the given coordinate of "squares" variable.
  'X' would be int 1 and 'O' would be int 2.

  @param coord the coordinate to place the piece at (X: 1, O: 2)
  @param piece the piece to be placed at the coord

  @return none
  */
  squares[coord - 1] = piece;
}

bool horizontal(int board[10], int piece)
{
  /*
  @brief Checks if there is a same piece put in any horizontal rows
  This function checks if whether X or O took over any horizontal lines
  of the board.

  @param board the board to be looked at (3x3 board assumed)
  @param piece the piece to be checked (1 for X, 2 for O)

  @return True if there is horizontal alignment False if there is none
  */
  for (int i = 0; i < 3; i++) // repeat for 3 rows
  {
    if (board[3 * i] == piece) // check first column
    {
      if (board[3 * i + 1] == piece) // check second column
      {
        if (board[3 * i + 2] == piece) // check third column
        {
          return true;
        }
      }
    }
  }
  return false;
}

bool vertical(int board[10], int piece)
{
  /*
  @brief Checks if there is a same piece put in any vertical columns
  This function checks if whether X or O took over any vertical lines
  of the board.

  @param board the board to be looked at (3x3 board assumed)
  @param piece the piece to be checked (1 for X, 2 for O)

  @return True if there is vertical alignment False if there is none
  */
  for (int i = 0; i < 3; i++) // repeat for 3 columns
  {
    if (board[i] == piece) // check first row
    {
      if (board[i + 3] == piece) // check second row
      {
        if (board[i + 6] == piece) // check third row
        {
          return true;
        }
      }
    }
  }
  return false;
}

bool diagonal(int board[10], int piece)
{
  /*
  @brief Checks if there is a same piece put in a diagonal line
  This function checks if whether X or O took over any diagonal lines
  of the board.

  @param board the board to be looked at (3x3 board assumed)
  @param piece the piece to be checked (1 for X, 2 for O)

  @return True if there is a diagonal alignment False if there is none
  */
  /* First diagonal line: line towards right bottom */
  if (board[0] == piece)
  {
    if (board[4] == piece)
    {
      if (board[8] == piece)
      {
        return true;
      }
    }
  }
  else if (board[2] == piece)
  {
    if (board[4] == piece)
    {
      if (board[6] == piece)
      {
        return true;
      }
    }
  }
  return false;
}

int Board::checkWin()
{
  /*
  @brief Checks if there is a winner and returns the winner, if there is one
  This function checks if there is a winner. If there is no winner,
  it returns 0. If player 1 wins, it returns 1, and if player 2 wins,
  it returns 2.

  @param none this function will use directly use "squares" variable

  @return 0 if no winner, 1 if player 1 wins, or 2 if player 2 wins
  */
  /* horizontal check */
  if (horizontal(squares, 1))
  {
    return 1;
  }
  else if (horizontal(squares, 2))
  {
    return 2;
  }
  /* vertical check */
  if (vertical(squares, 1))
  {
    return 1;
  }
  else if (vertical(squares, 2))
  {
    return 2;
  }
  /* diagonal check */
  if (diagonal(squares, 1))
  {
    return 1;
  }
  else if (diagonal(squares, 2))
  {
    return 2;
  }
  return 0;
}

bool Board::checkDraw()
{
  /*
  @brief Check if the game ended as a draw
  This function checks if the game has ended in a draw or not

  @param none going to work with variable "sqaures"

  @return True if it is a draw False if it is not a draw when the game ends
  */
  if (horizontal(squares, 1) || vertical(squares, 1) || diagonal(squares, 1))
  {
    return false;
  }
  else if (horizontal(squares, 2) || vertical(squares, 2) || diagonal(squares, 2))
  {
    return false;
  }
  return true;
}

string trans(int board[10], int coord)
{
  /*
  @brief translates the state of 'squares' to what is going to be displayed
  This function is a helper function of Board::print() function.
  It receives the state of each box in the board and returns the
  corresponding display of the state i.e coordinate number for 0 (empty),
  'X' for 1, and 'O' for 2.

  @param board the board to be translated from
  @param coord the coordinate of the box to be translated

  @return one letter character that corresponds to the state
  */
  string displayed = "O";
  if (board[coord - 1] == 0) // if unoccupied, display the box number
  {
    displayed = to_string(coord);
  }
  else if (board[coord - 1] == 1)
  {
    displayed = "X";
  }
  else if (board[coord - 1] == 2)
  {
    displayed = "O";
  }
  return displayed;
}

void Board::print()
{
  /*
  @brief prints the current board
  This function prints the board according to the current "squares".
  If the state is empty, the coordinate number is going to be displayed.
  If the state of "squares" is 1, 'X' is going to be displayed in the box.
  If the state of "squares" is 2, 'O' is going to be displayed in the box.

  @param none uses "squares variable"

  @return none just prints out the board
  */
  int j = 0; // variable to keep track of coord
  for (int i = 0; i < 7; i++)
  {
    if (i % 2 == 0) // print the following pattern every other line
    {
      cout << "|---|---|---|" << endl;
    }
    else // display either the coordinate, 'X', or 'O' according to the state
    {
      cout << "| " << trans(squares, 3*j + 1) << " | " << trans(squares, 3*j + 2);
      cout << " | " << trans(squares, 3*j + 3) << " |" << endl;
      j++;
    }
  }
}
