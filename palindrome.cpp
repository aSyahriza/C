/*
 * Author: Allam Syahriza
 * Date: 9/27/2022
 * Project: Palindrome
 * 
 * This program reads in an input from the user, and checks if 
 * that input is the same backwards as forwards. If so, it is a palindrome.
 *
 */


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char input[80];
  char correct[80];
  int correctCount = 0;
  bool palindrome = true;
  // Gets string from user
  cout << "Enter a string" << endl;
  cin.get(input, 80, '\n');
  cin.get();
  // Gets length of input
  int inputLength = strlen(input);
  for (int i=0; i < inputLength;i++){
    char correctChar;
    // Makes sure character isn't punctuation or space
    if (((input[i] > 47 && input[i] < 58) || (input[i] > 64 && input[i] < 91) || (input[i] > 96 && input [i] < 123)) && (input[i] != '\0')){
      // Makes lowercase characters uppercase
      if (input[i] > 96 && input[i] < 123){
	correctChar = input[i] - 32;
        
      }

      else{
	correctChar = input[i];

      }

      // Creates a new array without spaces or punctuation
      correct[correctCount] = correctChar;
      correctCount++;

    }
  }

  

  cout << "!" << correctCount << endl;
  int correctLength = strlen(correct);
  correct[correctLength] = '\0';
  cout << "*" << correctLength << endl;
  // Manually adding in null character
  
  for (int i=0; i < correctCount;i++){
    // Compares each charcter with the character at its mirrored position  
    if(correct[i] != correct[correctCount-(i+1)]){
      // If one of the characters don't match, the string is not a palindrome
      palindrome = false;
 
    

    }
  }

  if(palindrome){
    cout << "This is a palindrome." << endl;
  }

  else{

    cout << "This is not a palindrome." << endl;

  }
  



  return 0;
}
