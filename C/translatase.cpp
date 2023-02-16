/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 2 B

Translatase, Converts DNA into codons.
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
string dictionary_lookup(ifstream &dict,string search) {
    string key, value;
    dict.clear(); // reset error state
    dict.seekg(0); // return file pointer to the beginning
    while (dict >> key >> value) {
        if(key == search)
            return value;
    }
    return NULL;
}
int main(){
    ifstream fin("dnab.txt"); //reads dna txt file
    ifstream dict("codons.tsv");//reads codons dict
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string strand;
    string temp="";
    string strands[8]; 
    int line=0;
    while(getline(fin, strand)) {
        for (int i = 0;i<strand.length();i++){
            temp+=(returnComplement(toupper(strand.at(i))));//loop through each char, print complement char
        }
        strands[line] =temp;
        line++;
        temp ="";
    }
    for (int i = 0; i<8;i++){
        cout<<i;
        cout<<strands[i]<<endl;
        bool start = false;
        for(int j = 0; j<strands[i].length();j+=3){
            if(start) {
                if(dictionary_lookup(dict,strands[i].substr(j,3))=="Stop"){
                    start = false;
                }else {
                    cout<<"-";
                    cout<<dictionary_lookup(dict,strands[i].substr(j,3));
                }
            }
            if(strands[i].substr(j,3)=="AUG"){
                cout<<"Met";
                start = true;
            }
        }
        cout<<endl;
    }
    fin.close();
    dict.close();
    return 0;
}