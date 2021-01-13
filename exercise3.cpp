// C++ program that takes a filename from the user and checks if it exists. If it exists it display and add a count to each line and display the total number of lines at the end; an appropriate indication should be given if the file specified does not exist.
// https://repl.it/@mstoiovici/FileReader#main.cpp
#include <iostream>
#include <fstream> // provides ofstream and ifstream
#include <sys/stat.h>
using namespace std;

string getResponse(string message) {
	//this function askes the user to provide some information
	string response; //declare a variable to hold the user response
	cout << message; //output the provided message
	getline (cin, response); //get the user's input
	return response; //return the response
}
  
int main() {
  struct stat buf;
  string line;
  ifstream ifstreamObject;

  string filename = getResponse("Please enter a valid filename: ");

  if (stat(filename.c_str(), &buf) == 0){
    ifstreamObject.open(filename);
    int count  = 0;
    // while you're not at the end of file
    while(!ifstreamObject.eof()){
      getline(ifstreamObject, line);
      count++;
      cout << count << ":" << line << endl;
    } 
    cout << "\n\nTotal number of lines read: " << count;
    ifstreamObject.close();
  } else {
    cout << "Sorry, \'"<< filename << "\' does not exist." << endl;
  }
  return 0;
}
