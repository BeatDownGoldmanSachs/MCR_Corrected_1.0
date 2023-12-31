#include<iostream>
using namespace std;

bool isWin(char game[3][3]) {
  bool win = false;
  if (game[0][0] == game[0][1] && game[0][1] == game[0][2]) win = true;
  if (game[1][0] == game[1][1] && game[1][1] == game[1][2]) win = true;
  if (game[2][0] == game[2][1] && game[2][1] == game[2][2]) win = true;
  // column
  if (game[0][0] == game[1][0] && game[1][0] == game[2][0]) win = true;
  if (game[0][1] == game[1][1] && game[1][1] == game[2][1]) win = true;
  if (game[0][2] == game[1][2] && game[1][2] == game[2][2]) win = true;
  // diagonal
  if (game[0][0] == game[1][1] && game[1][1] == game[2][2]) win = true;
  if (game[0][2] == game[1][1] && game[1][1] == game[2][0]) win = true;
  return win;
}

int main() {
  int i, j;
  char game[3][3] = {
    ' '
  }; // Tic-tac-toe
  char player1 = 'X';
  char player2 = 'O';
  bool turn = true; // false for player 1's turn, true for player 2's turn. Player 1 first.
  cout << "X = Player 1" << endl;
  cout << "O = Player 2" << endl;
  int n = 0;
  for (n; n < 9; n++) {
    turn = !turn; // use the not-operator to change true to false or false to true.
    if (turn == false)
      cout << "Player 1: ";
    else
      cout << "Player 2: ";
    cout << "Which cell to mark? i:[0..2], j:[0..2]: ";
    cin >> i >> j;
    if (game[i][j] != NULL)
      continue;
    else{
      if (turn == false)
        game[i][j] = 'X';
      else
        game[i][j] = 'O';
    }
    if (isWin(game)) {
      cout << "Win!" << endl;
      break; // need to terminate the problem
    }
  }
  if (n == 9) // all celles with i=0 to 2 have been inputted above but no winner yet
    cout << "Tie!" << endl;

  // show the game to console
  cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
  cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
  cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;
  return 0;
}
