/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 2 D

Frameshift, converts frameshifted codons.
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
    return "";
}
string translatase(string untranslated,ifstream &dict){ //function translates string 
    bool start= false;
    string temp;
    int x = 0;
    do{
        if(x==untranslated.length())
            return"";
        if(untranslated.substr(x,3)=="AUG"){
            temp+="Met";
            start = true;
            x+=3;
        }
        else{
            x++;
        }
    }while(!start);
    for(int j = x; j<untranslated.length();j+=3){
        if(start) {
            if(dictionary_lookup(dict,untranslated.substr(j,3))=="Stop"||j+2>untranslated.length()){
                start = false;
            }else {
                temp+="-";
                temp+=dictionary_lookup(dict,untranslated.substr(j,3));
            }
        }
    }
    return temp;
}
int main(){
    ifstream fin("frameshift_mutations.txt"); //reads dna txt file
    ifstream dict("codons.tsv");//reads codons dict
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string strand;
    string temp="";
    string strands[16]; 
    int line=0;
    while(getline(fin, strand)) {
        for (int i = 0;i<strand.length();i++){
            temp+=(returnComplement(toupper(strand.at(i))));//loop through each char, print complement char
        }
        strands[line] =temp;
        line++;
        temp ="";
    }
    for (int i = 0; i<16;i++){
        cout<<translatase(strands[i],dict)<<endl;
    }
    fin.close();
    dict.close();
    return 0;
}