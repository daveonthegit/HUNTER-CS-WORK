/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 2 B

Hamming, Checks two dna strands to see if there are differences, then returns # of diff, and if codons changed.
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
string translatase(string untranslated,ifstream &dict){ //function translates string 
    bool start= false;
    string temp;
    for(int j = 0; j<untranslated.length();j+=3){
        if(start) {
            if(dictionary_lookup(dict,untranslated.substr(j,3))=="Stop"){
                start = false;
            }else {
                temp+="-";
                temp+=dictionary_lookup(dict,untranslated.substr(j,3));
            }
        }
        if(untranslated.substr(j,3)=="AUG"){
            temp+="Met";
            start = true;
        }
    }
    return temp;
}
int main(){
    ifstream fin("mutations.txt"); //reads dna txt file
    ifstream dict("codons.tsv");//reads codons dict
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string strand;
    string temp="";
    string strands[12]; 
    int line=0;
    while(getline(fin, strand)) {
        for (int i = 0;i<strand.length();i++){
            temp+=(returnComplement(toupper(strand.at(i))));//loop through each char, print complement char
        }
        strands[line] =temp;
        line++;
        temp ="";
    }
    string translated[12];//to store translated strands
    for (int i = 0; i<12;i+=2){
        translated[i] = translatase(strands[i],dict);
        translated[i+1]= translatase(strands[i+1],dict);
        int numDiff=0;
        for(int j = 0;j<strands[i].length();j++){//record num mutations
            if(strands[i].at(j)!=strands[i+1].at(j))
                numDiff++;
        }
        cout<<numDiff;
        if(translated[i]==translated[i+1]) //compare translated strings
            cout<<" yes"<<endl;
        else 
            cout<<" no"<<endl;
    }
    fin.close();
    dict.close();
    return 0;
}