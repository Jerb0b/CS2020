// Program #2 – Shares Program
// Programmer:  Justin Jereb
// Class:  CS 2020, Term Spring 2024
// Due Date: 2/18/2024
// Purpose of program: Create a program that will read data from a file called shares.txt.  
// The data will consist of a shareholder's name, their category, and number of shares
// It will then provide a breakdown of the selected category and the value of each, as
// well as the total value of all categories combined

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// Global Constants
const int numShareHolders = 27;

// Structure of the "Shareholder" we will need for the vector
struct Shareholder {
	string name;
	string category;
	int shares;
};

// Function Prototypes
void fillvector(vector <Shareholder>& ClientsList);
void printvector(vector <Shareholder> ClientsList);
void findcategory(vector <Shareholder> CliensList);
void breakdown(vector <Shareholder> ClientsList);

int main() {
	
	// Declared variables and vectors
	vector <Shareholder> ClientsList;
	ClientsList.resize(numShareHolders);

	// Call to the functions
	fillvector(ClientsList);
	printvector(ClientsList);
	breakdown(ClientsList);


	system("pause");
	return 0;
}

//************************************************************************************
//Function: fillvector
//Function to read and fill vectors. The file is opened and closed after filling vectors
//************************************************************************************

void fillvector(vector <Shareholder>& ClientsList) {
	cout << "INSERT FILLER VECTOR HERE" << endl;
}

//************************************************************************************
//Function: printvectors
//Function to print the vectors in tabular form
//************************************************************************************

void printvector(vector <Shareholder> ClientsList) {
	cout << "INSERT PRINTER VECTOR HERE" << endl;
}

//************************************************************************************
//Function: findcategory
//Function to receive selected category of shareholders and output it
//************************************************************************************

void findcategory(vector <Shareholder> ClientsList) {
	cout << "INSERT FIND CATEGORY HERE" << endl;
}

//************************************************************************************
//Function: breakdown
//Function to display breakdown of each category as well as all shareholder assests
//************************************************************************************

void breakdown(vector <Shareholder> ClientsList) {
	cout << "INSERT SHAREHOLDER BREAKDOWN HERE" << endl;
}