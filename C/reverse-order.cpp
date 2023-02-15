//Name:  David Xiao
//Email:  david.xiao67@myhunter.cuny.edu
//Date:  2/15/23
//Reads data from Reservoir levels, and posts the elevation in reverse chronological order.

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
    string start_date; string end_date; //start and end dates
    cout<< "Enter earlier date: ";
    cin >> start_date;
    cout<< "Enter later date: ";
    cin >> end_date;
    string junk;        // new string variable
    getline(fin, junk); // read one line from the file just
    string date;
    double eastSt; double eastEl; double westSt; double westEl;\
    bool x = false;
    int i = 0;
    struct date_info { //create a struct to hold data
        string struct_date;
        double struct_westEl;
    };
    struct date_info info[365]; //struct array using # of days in a year
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                                //ignorring the remaining columns 
        if (start_date == date){ //check if date is between range
            x = true;
        }
        if (x) {
            info[i].struct_date = date;
            info[i].struct_westEl = westEl;
            i++; //max length to go for array using i
        }
        if (end_date == date){
            x = false;
        }
    }
    for (int j = i-1;j>=0;j-- ){
        cout<<info[j].struct_date << "  " << info[j].struct_westEl << " ft" <<endl;
    }
    fin.close();
}
