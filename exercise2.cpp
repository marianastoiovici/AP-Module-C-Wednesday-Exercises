// C++ program that appends (or create in
// the first instance) a plain text file called “list.csv” with a name entered by the user.Once updated, the user can enter a new name or leave with a goodbye message.
// https://repl.it/@mstoiovici/FileWriter#main.cpp
#include <iostream>
#include <fstream> // provides ofstream and ifstream
using namespace std;

string getResponse(string message) {
	//this function askes the user to provide some information
	string response; //declare a variable to hold the user response
	cout << message; //output the provided message
	getline (cin, response); //get the user's input
	return response; //return the response
}

void store(string filename, string value, bool append) {
  ofstream ofstreamObject;
  if(append) {
    // moves the cursor to append to an existing file or creat the file if it doesn't exist and append to it
    ofstreamObject.open(filename, ios_base::app);
  } else {
    // moves the cursor to do not append to a file but rather override the specified existing file
    ofstreamObject.open(filename, ios_base::out);
  }
  //writes the value where the cursor was moved(above in the if statement)
  ofstreamObject << value << endl;
  //close the connection to the file
  ofstreamObject.close();
}



int main() {
  bool keepAdding = true;

  while (keepAdding) {
    //ask user for a name 
  string name = getResponse("\nEnter name: ");
  store("list.csv", name, true);
  cout << "Updating file..." << endl;
  string anotherName = getResponse("\nAdd another (y/n)?:");
  if (anotherName == "y" || anotherName == "Y"){
    keepAdding = true;
    //TODO:could add validation for getting something else other than n, N, case in which I should ask again for a valid option y,n?
  } else {
    keepAdding = false;
    cout << "Goodbye";
  }
  }
  return 0;
}
