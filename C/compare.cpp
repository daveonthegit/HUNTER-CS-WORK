//Name:  David Xiao
//Email:  david.xiao67@myhunter.cuny.edu
//Date:  2/15/23
//Reads data from Reservoir levels, and posts which basin has more storage.

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
    string start_date; string end_date;
    cout<< "Enter starting date: ";
    cin >> start_date;
    cout<< "Enter ending date: ";
    cin >> end_date;
    string junk;        // new string variable
    getline(fin, junk); // read one line from the file just
    string date;
    bool x =false;
    double eastSt; double eastEl; double westSt; double westEl;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 

        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                                //ignorring the remaining columns 
        if (date ==start_date){
            x = true;
        }
        if (x) {
            cout << date;
            if (eastEl > westEl) {
                cout <<" East" <<endl;
            } else if(eastEl < westEl) {
                cout <<" West" <<endl;
            } else{
                cout <<" Equal" <<endl;
            }
        }
        if (date == end_date){
            x = false;
        }
    }
    fin.close();
}
