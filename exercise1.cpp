// C++ program that takes a filename from the user and checks if it exists. If it exists it prints some of its stats and if not it displays a "doesn not exist" message.
// https://repl.it/@mstoiovici/FileExists#main.cpp
#include <iostream>
#include <fstream>
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
  //version inside main
  struct stat buf;
  //ask for the filename to be checked 
  string filename = getResponse("Filename to check: ");
  if (stat(filename.c_str(), &buf) == 0){
    cout << filename << ", " << buf.st_size << " bytes, last modified: " << ctime(&buf.st_mtime);
  } else {
    cout << filename << " does not exist" << endl;
  }
  return 0;
}
