/*
* 
* Author: Allam Syahriza  
* Date: 10/11/2022
* This programs simulates a two person game of TicTacToe in C++,
* keeps tracks of wins/ties, and allows the user to play again.
*
*/





#include <iostream>
#include <cstring>
using namespace std;

int printBoard(char board[3][3]){
  // Prints grid letters and numbers
  cout << "\n" << "\n" << endl;
  cout << "\t" << "A" << "\t" << "B" << "\t" << "C" << "\n" <<endl;
  for (int row = 0; row < 3; row++){
    cout << row + 1;
      for (int column = 0; column < 3; column ++){
        // Prints board contents
        cout << "\t" << board[row][column];
      }
      cout << "\n"<<"\n";
  }

  return 0;

  
  
}


bool checkTie(char board[3][3]){
  // Checks if every square is occupied
    for (int row = 0; row < 3; row++){
      for (int column = 0; column < 3; column++){
        if (board[row][column] == ' '){
          return false;
        }
      }
    }
    // If every square is occupied with no winner, it is a tie
    return true;
  }

bool checkWin(char player, char board[3][3]){
    if (board[0][0] == player && board[0][1] == player && board[0][2] == player){ // 1st row
      return true;
    }
    else if (board[1][0] == player && board[1][1] == player && board[1][2] == player){ // 2nd row
      return true;
    }
    else if (board[2][0] == player && board[2][1] == player && board[2][2] == player){ // 3rd row
      return true;
    }
    else if (board[0][0] == player && board[1][0] == player && board[2][0] == player){ // 1st column
      return true;
    }
    else if (board[0][1] == player && board[1][1] == player && board[2][1] == player){ // 2nd column
      return true;
    }
    else if (board[0][2] == player && board[1][2] == player && board[2][2] == player){ // 3rd column
      return true;
    }
    else if (board[0][0] == player && board[1][1] == player && board[2][2] == player){ // 1st diagonal 
      return true;
    }
    else if (board[0][2] == player && board[1][1] == player && board[2][0] == player){ // 2nd diagonal 
      return true;
    }
    else {
      return false;
    }
  }

bool checkPlay(char board[3][3]){

  char input;
  cout << "Do you want to play again? (y/n)" << endl;
  cin >> input;
  // Makes sure user enters only 'y' or 'n'
  while(input != 'y' && input != 'n'){

    cout << "Must enter 'y' or 'n'" << endl;
    cin >> input;

  }
  
  if(input == 'y'){
    // Resets the board
    for (int row = 0; row < 3; row++){
      for (int column = 0; column < 3; column++){
        board[row][column] = ' ';
      }
    }
    return true;
  }
  else{


    cout << "Bye." << endl;
    return false;
  
  }
}

int main(){

  char board[3][3];
  bool X_TURN = true;

  char row;
  char column;
  char tempRow;
  char tempColumn;
  bool stillPlaying = true;
  int xWins = 0;
  int oWins = 0;
  int ties = 0;

  // Sets the board blank
  for (int row = 0; row < 3; row++){

    for (int column = 0; column < 3; column ++){
      board[row][column] = ' ';
      }
  }

  while(stillPlaying){
    // Will ask the user for input as long as no winner or tie has occured
    while (checkWin('X',board) == false && checkWin('O',board) == false && checkTie(board) == false) {  
      printBoard(board);


      // Ensures user only enters valid rows
      cout << "What row will you make your move?" << endl;
      cin >> tempRow;
      while((tempRow < 49) || (tempRow > 51)){
	cout << "Row entered is invalid!" << endl;
        cout << "What row will you make your move?" << endl;
        cin >> tempRow;
      }

      // Ensures user only enters valid columns
      cout << "What column will you make your move?" << endl;
      cin >> tempColumn;
      while((tempColumn < 65 || tempColumn > 67) && (tempColumn < 97 || tempColumn > 99)){
	      cout << "Column entered is invalid:" << endl; 
	      cout << "What column will you make your move?" << endl;
	      cin >> tempColumn;
      }

      // Converts the users entered characters to indices for the array
      row = tempRow - 49;
      if(tempColumn < 68)
        column = tempColumn - 65;
      else{
        column = tempColumn - 97;
      }
      

      // If the designated square is empty, places piece
      if (board[row][column] == ' '){
	      if (X_TURN){
	        board[row][column] = 'X';
	        X_TURN = false;
        }
	      else {
	        board[row][column] = 'O';
	        X_TURN = true;            
        }
      }
      // If the square is occupied, has the user choose another square.
      else{
        cout << "That spot is occupied! Choose another spot."<< endl;
        continue;
      }
    }
    printBoard(board);
    cout << "\n";
    // Checks if X has won
    if(checkWin('X',board) == true){
      cout << "X WINS!!" << endl;  
      xWins+=1;
    }
    // Checks if O has won
    else if (checkWin('O',board) == true){
      cout << "O WINS!!" << endl;
      oWins+=1;
    }
    // Checks if there is a tie
    else if (checkTie(board) == true){
      cout << "TIE!!" << endl;
      ties+=1;
    }
    // Prints out the running tallies
    cout << "Total X Wins: " << xWins << endl;
    cout << "Total O Wins: " << oWins << endl;
    cout << "Total Ties: " << ties << endl;
    
    
    // Asks the user if they want to play again 
    if(checkPlay(board)){
      stillPlaying = true;
      X_TURN = true;
      
    }
    else{
      stillPlaying = false;
    }
  }

  return 0;


}
