//Name:  David Xiao
//Email:  david.xiao67@myhunter.cuny.edu
//Date:  2/15/23
//Reads data from east-storage and uses input string to print out the east basin storage of that day.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string date_input;
    cout<< "Enter date: ";
    cin >> date_input;
    string junk;        // new string variable
    getline(fin, junk); // read one line from the file 
    string date;
    double eastSt; double eastEl; double westSt; double westEl;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 

        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                                //ignorring the remaining columns 

        if (date_input == date) {
            cout <<"East basin storage: " << eastSt << " billion gallons" <<endl;
        }
        
    }
    fin.close();
}
