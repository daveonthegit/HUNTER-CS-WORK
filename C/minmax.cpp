//Name:  David Xiao
//Email:  david.xiao67@myhunter.cuny.edu
//Date:  2/15/23
//Reads data from east-storage and prints min and max
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
    string junk;        // new string variable
    getline(fin, junk); // read one line from the file 
    string date;
    double min = INT_MAX; double max = INT_MIN;
    double eastSt; double eastEl; double westSt; double westEl;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 

        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                                //ignorring the remaining columns 
        if (eastSt < min) {
            min = eastSt;
        }
        if (eastSt > max) {
            max = eastSt;
        }
        
    }
    cout << "minimum storage in East basin: " << min << endl;
    cout << "MAXimum storage in East basin: " << max << endl;
    fin.close();
}
