
#include <iostream>
#include <cstring>
using namespace std;

int printBoard(char board[3][3]){
  cout << "\t" << "A" << "\t" << "B" << "\t" << "C" << endl;
  for (int row = 0; row < 3; row++){
    cout << row + 1;
      for (int column = 0; column < 3; column ++){
        cout << "\t" << board[row][column];
      }
      cout << "\n";
  }

  return 0;

  
  
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
  while(input != 'y' && input != 'n'){

    cout << "Must enter 'y' or 'n'" << endl;
    cin >> input;

  }
  if(input == 'y'){
    for (int row = 0; row < 3; row++){
      for (int column = 0; column < 3; column++){
        board[row][column] = 'S';
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
  
  for (int row = 0; row < 3; row++){

    for (int column = 0; column < 3; column ++){
      board[row][column] = 'S';
      }
  }
  while(stillPlaying){
    while (checkWin('X',board) == false && checkWin('O',board) == false /*&& checkTie() == false*/) {  
      printBoard(board);



      cout << "What row will you make your move?" << endl;
      cin >> tempRow;



      while((tempRow < 49) || (tempRow > 51)){

	cout << "Row entered is invalid!" << endl; 
	cout << "What row will you make your move?" << endl;
	cin >> tempRow;

      }

      cout << "What column will you make your move?" << endl;
      cin >> tempColumn;

      while((tempColumn < 65 || tempColumn > 67) && (tempColumn < 97 || tempColumn > 99)){
	cout << "Column entered is invalid:" << endl; 
	cout << "What column will you make your move?" << endl;
	cin >> tempColumn;
      }

      row = tempRow - 49;
      column = tempColumn - 65; 


      if (board[row][column] == 'S'){
	if (X_TURN){
	  board[row][column] = 'X';
	  X_TURN = false;



	}
	else {
	  board[row][column] = 'O';
	  X_TURN = true;            

	}
      }
    }

    if(checkWin('X',board) == true){
      cout << "X WINS!!!!!!" << endl;  
    }

    else if (checkWin('O',board) == true){
      cout << "O WINS!!!!!!!!!!" << endl;
    }

    /*else if (checkTie() == true){

      }*/
    stillPlaying = checkPlay(board);
  }

  return 0;


}
