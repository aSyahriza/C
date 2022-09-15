/* 

 * 3 Rules of C++ class:
 * 1. No global variables. (Global constants are all right.)
 * 2. No strings. Not ever. (You can use cstrings/character arrays, and the cstring and cctype libraries are okay. In fact, I recommend using strcmp and strlen in your projects.)
 * 3. You should include <iostream>, not stdio. (This applies more to C programmers.)

 * Author: Allam Syahriza
 * Date: 9/9/2022
 * This program generates a random number, 0 - 100, that the user tries to guess.



 */ 


#include <iostream>
#include <cstdlib>
 

  

using namespace std;

int main()
{
  // Keeps track of if the game is still going on or not
  char playAgain = 'y';
  while(playAgain == 'y'){

    // Setting seed for randomly generated number
    srand(time(NULL));
    cout << "Enter a guess, 0 - 100: " << endl;

    // Generates a very large random number, which is made into a double digit number by taking its modulus of 100
    int randNum = rand() % 100;

    
    int input = 0;
    int guesses = 0;
    
    // Reads in guess from user
    cin >> input;

    // Keeps tally of the amount of guesses from the user
    guesses +=1;

    // Loops while the users guess does not match the random number
    while (input != randNum){
      // Tells user if guess was too high
      if(input > randNum){
        cout << "Guess was too high! " << endl;
      }
      // Tells user if guess was too low
      if (input < randNum){
        cout << "Guess was too low! " << endl;
      }
      cout << "Enter a different guess: " << endl;
      cin >> input;
      guesses +=1;
    
    
    }
    // Prints out how many guesses it took the user
    cout << "Guess was correct! It took you " << guesses << " tries."<< endl;
    cout << "Would you like to play again? " << endl;
    cin >> playAgain;
    
  }

  cout << "See you next time" << endl;

  return 0;
  
  

}
