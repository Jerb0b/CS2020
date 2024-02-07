// Program #1 – Hurricane Program
// Programmer:  Justin Jereb
// Class:  CS 2020, Term Spring 2024
// Due Date: 1/28/2024
// Purpose of program: Create a program that 
// will read data from a file called hurricanes.txt.  
// The data will consist of a city’s name, wind velocity 
// and amount of rain for the hurricanes that occurred in the United States.

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

//global constants
const int MAXCITIES = 50;
using namespace std;

// Prototypes
void fillvector (vector<string>& city, vector<int>& wind, vector<double>& rain, int& numcities);
void printvectors (vector<string>city, vector<int> wind, vector<double>rain, int numcities);
void selsort (vector<string>& city, vector<int>& wind, vector<double>& rain, int numcities);
void violentwinds (vector<string>city, vector<int> wind, vector<double> rain, int numcities);
void majorflood (vector<string> city, vector<int> wind, vector<double> rain, int numcities);
int windiestcitypos (vector<string>city, vector<int>wind, int numcities);
double averagewind (vector<string>city, vector<int>wind, int numcities);
double averagerain (vector<string> city, vector<double>rain, int numcities);


int main() {
// Declared variables and vectors
	vector<string> city(MAXCITIES);
	vector<int> wind(MAXCITIES);
	vector<double> rain(MAXCITIES);
	int numcities = 0;
	int i = 0;

// call to the functions
	fillvector(city, wind, rain, numcities);
	selsort(city, wind, rain, numcities);
	printvectors(city, wind, rain, numcities);
	violentwinds(city, wind, rain, numcities);
	majorflood(city, wind, rain, numcities);
	


// output averages and highest
	cout << city.at(windiestcitypos(city, wind, numcities)) << " is the windiest city at " << wind.at(windiestcitypos(city, wind, numcities)) << " mph." << endl;
	cout << endl;
	cout << "The average wind is " << averagewind(city, wind, numcities) << endl;
	cout << "The average rain is " << fixed << setprecision(3) << averagerain(city, rain, numcities) << endl;


	system("Pause");
	return 0;
}

//************************************************************************************
//Function: fillvector
//Function to read and fill vectors. The file is opened and closed after filling vectors
//************************************************************************************

void fillvector(vector<string>&city, vector<int>&wind, vector<double>&rain, int& numcities)
{
	cout << left << fixed << setprecision(1);
	ifstream infile;
	string tempstr;
	numcities = 0;

	//Now we will open the file

	infile.open("hurricanes.txt");
	if (!infile)
	{
		cerr << "Error" << endl;
	}

	//We will now run a loop to get al of the data from the file and assign it to the proper vector
	while (!infile.eof() && numcities < MAXCITIES)
	{
		getline(infile, city.at(numcities));
		infile >> wind.at(numcities);
		infile >> rain.at(numcities);
		getline(infile, tempstr);
		numcities++;
	}
	infile.close();
}

//************************************************************************************
//Function: printvectors
//Function to print the vectors in tabular form
//************************************************************************************

void printvectors(vector<string>city, vector<int>wind, vector<double>rain, int numcities){
	//Header
	cout << "The Data file consists of: " << endl;
	cout << setw(15) << "City" << setw(10) << "Wind" << setw(10) << " Rain" << endl;
	cout << setw(15) << "------" << setw(10) << "----" << setw(10) << "-----" << endl;

	//Body
	for (int count = 0; count < numcities; count++)
	{
		cout << setw(15) << city.at(count) << setw(10);
		cout << wind.at(count) << setw(10);
		cout << rain.at(count) << endl;
		
		
	}
	cout << endl;
	cout << endl;
}

//************************************************************************************
//Function: selsort
//Function to sort the cities, wind, and rain using selection sort
//************************************************************************************

void selsort(vector<string>& city, vector<int>& wind, vector<double>& rain, int numcities) {
	//Variable Declaration
	int i;
	int j;
	int minIndex;
	string smallCity;
	double smallRain;
	int smallWind;

	//Selection Sort 
	for (i = 0; i < (numcities - 1); ++i) {
		minIndex = i;
		smallCity = city.at(i);
		smallRain = rain.at(i);
		smallWind = wind.at(i);
		for (j = i + 1; j < numcities; ++j) {
			if (city.at(j) < smallCity) {
				smallCity = city.at(j);
				smallRain = rain.at(j);
				smallWind = wind.at(j);
				minIndex = j;
			}
		}
		city.at(minIndex) = city.at(i);
		city.at(i) = smallCity;
		rain.at(minIndex) = rain.at(i);
		rain.at(i) = smallRain;
		wind.at(minIndex) = wind.at(i);
		wind.at(i) = smallWind;
	}
	
}

//************************************************************************************
//Function: violentwinds
//Function to check, and output, which cities had winds equal to, or exceeding 120 MPH
//************************************************************************************

void violentwinds(vector<string>city, vector<int> wind, vector<double> rain, int numcities) {
	//Variable Declaration
	int i;
	int j = 0;
	int isViolent = 120;
	vector <string> violentCities(numcities);
	vector <int> violentWind(numcities);

	//Loop to check if the wind for a city qualifies as violent, and if so adds it to the vector collection of violent winds and cities
	for (i = 0; i < numcities; ++i) {
		if (wind.at(i) >= isViolent) {
			violentCities.at(j) = city.at(i);
			violentWind.at(j) = wind.at(i);
			++j;
		}
	}
	//Header
	cout << "Cities with Violent Winds" << endl;
	
	//Loop to output all cities with violent winds using vectors
	for (i = 0; i < j; ++i) {
		cout << setw(15) << violentCities.at(i) << " " << violentWind.at(i) << endl;
	}
	cout << endl;
}

//************************************************************************************
//Function: majorflood
//Function to check, and output, which cities had rain equal to, or exceeding 3.5 inches
//************************************************************************************

void majorflood(vector<string> city, vector<int> wind, vector<double> rain, int numcities) {
	//Variable Declaration
	int i;
	int j = 0;
	double isFlood = 3.5;
	vector <string> floodCities(numcities);
	vector <double> floodRain(numcities);

	//Loop to check if the rain for a city qualifies as flooding, and if so adds it to the vector collection of flooded cities and rainfall
	for (i = 0; i < numcities; ++i) {
		if (rain.at(i) >= isFlood) {
			floodCities.at(j) = city.at(i);
			floodRain.at(j) = rain.at(i);
			++j;
		}
	}
	//Header
	cout << "Cities with Major Floods" << endl;

	//Loop to output all cities with flooding using vectors
	for (i = 0; i < j; ++i) {
		cout << setw(15) << floodCities.at(i) << " " << floodRain.at(i) << endl;
	}
	cout << endl;
}

//************************************************************************************
//Function: windiestcitypos
//Function to return the index of the windiest city, which is used to output
// both the city and it's wind sped
//************************************************************************************

int windiestcitypos(vector<string>city, vector<int>wind, int numcities){
	//Variable Declaration
	int i;
	int windIndex = 0;
	int windValue = 0;

	//Loop to check the index at which the windiest city resides
	for (i = 0; i < numcities; ++i) {
		if (wind.at(i) > windValue) {
			windValue = wind.at(i);
			windIndex = i;
		}
	}

	return windIndex;
}

//************************************************************************************
//Function: averagewind
//Function to calculate and return the average wind velocity
//************************************************************************************

double averagewind(vector<string>city, vector<int>wind, int numcities){
	//Variable Declaration
	double avgWind;
	double sum = 0;
	int i;
	int counter = 0;
	
	//Loop to calculate the sum of wind for all cities
	for (i = 0; i < numcities; ++i) {
		sum += wind.at(i);
		counter++;
	}

	//Calculates average wind and returns the value
	avgWind = sum / counter;

	return avgWind;
}

//************************************************************************************
//Function: averagerain
//Function to calculate and return the average rainfall
//************************************************************************************

double averagerain(vector<string> city, vector<double> rain, int numcities) {
	//Variable Declaration
	double avgRain;
	double sum = 0;
	double counter = 0;
	int i;

	//Loop to calculate the sum of rain for all cities
	for (i = 0; i < numcities; ++i) {
		sum += rain.at(i);
		counter++;
	}
	
	//Calculates average rain and returns the value
	avgRain = sum / counter;

	return avgRain;
}