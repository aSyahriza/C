/*
* 
* Author: Allam Syahriza  
* Date: 11/06/2022
* This programs creates a list of students, keeping tracks of their names, IDs, and GPAs.
* Users can add or remove students, and print the list.
*
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


// Creates struct
struct Student{
  char name[10];
  int id;
  float gpa;

};

// Function prototypes
void addStudent(Student &student1, vector<Student>& vect);
void printList(vector<Student>& vect);
void deleteStudent(vector<Student>& vect);


int main() {
  
  bool loop = true;
  // Creates vector which hold pointers to instances of student struct.
  vector<Student> studentList;
  // Char array to hold user input
  char command[10];
  
  cout << "Enter ADD, DELETE, PRINT, or QUIT" << endl;
  
  // Loops program
  while(loop == true){
    // Gets input from user
    cin.get(command,10,'\n');
    cin.clear();
    cin.ignore(99999,'\n');
    
    
    
    // Checks if the user wants to ADD students to list
    if(strcmp(command, "ADD") == 0){
      
      Student student1;
      addStudent(student1,studentList);
      
    }
    // Checks if the user wants to DELETE students to list
    else if(strcmp(command, "DELETE") == 0){
      
      deleteStudent(studentList);
      
    }
    // Checks if the user wants to PRINT the current list
    else if(strcmp(command, "PRINT") == 0){
      
      printList(studentList);
      
    }
    else if(strcmp(command, "QUIT") == 0){

      // Breaks the loop, quits program
      loop = false;
      
    }    
  }
  cout << "Program ended." << endl;
  return 0;
}

void addStudent(Student &student,vector<Student>& vect){

  // Takes in student info from user
  cout << "Enter Student Name" << endl;
  cin >> student.name;
  cout << "Enter Student ID" << endl;
  cin >> student.id;
  cout << "Enter Student GPA" << endl;
  cin >> student.gpa;
  // Creates pointer pointing to student
  Student* ptrStudent1 = &student;
  // Adds said pointer to vector
  vect.push_back(*ptrStudent1);
  cout << "Student has been added." << endl;
  
}

void deleteStudent(vector<Student>& vect){
  
  int deleteId;
  
  cout<< "Enter ID of student you wish to delete: " << endl;
  // Saves ID of student user wants to delete
  cin >> deleteId;

  // Iterator goes through vector until it reaches end
  vector<Student>::iterator i;
  for (i = vect.begin(); i != vect.end(); ++i){
    // Creates student instance from iterator value
    Student student = *i;
    // Compares ID of said student instance to ID user will delete
    if(student.id == deleteId){
      // If they are equal, deletes ID at i
      vect.erase(i);
      cout << "Student has been deleted."<< endl;
    }
  }
  
}

void printList(vector<Student>& vect)
{
  cout << "Current List of Students: " << endl;
  vector<Student>::iterator i;
  for (i = vect.begin(); i != vect.end(); ++i){
    // Prints out value of vector at i
    // (line would cause error in code)
    // cout << vect.at(i);
  
  }
}
