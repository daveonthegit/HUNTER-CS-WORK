/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 2? A

Transcriptase, reads a line of DNA and transcripts it into a line of mRNA
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;
char returnComplement(char y){ //returns complement character
    char x;
    if (y == 'A')
        x = 'U';
    else if(y =='T')
        x = 'A';
    else if (y =='C')
        x = 'G';
    else if (y =='G')
        x = 'C';

    return x;
}

int main(){
    ifstream fin("dna.txt"); //reads dna txt file
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string strand;
    while(getline(fin, strand)) {
        for (int i = 0;i<strand.length();i++){
            cout<<returnComplement(toupper(strand.at(i)));//loop through each char, print complement char
        }
        cout<<endl;//new line
    }
    fin.close();
}