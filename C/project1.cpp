/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 1

Use arrays and read text from a txt, storing information into arrays.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;
//GLOBAL VARIABLES

const int MAX_WORDS = 1000;
int WORD_COUNT = 0;

string WORDS[MAX_WORDS];
string DEFINITIONS[MAX_WORDS];
string POS[MAX_WORDS];

/*
    @param            :   The string with the `filename`
    @post             :   Reads the words, definitions, 
                          POS into the global arrays, 
                          and set the value of `WORD_COUNT` 
                          to the number of words read
*/
void readWords(string filename){
    ifstream fin(filename); //reads dna txt file
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string line;
    int currline=0;
    while(getline(fin, line)) {
        int x=0;
        string TEMPWORDS[MAX_WORDS];
        for (int i=0;i<line.length();i++){
            if(line[i]==' ')
                x++;
            else
                TEMPWORDS[x]+=line[i];
        }
        
        WORDS[currline] =TEMPWORDS[0];
        POS[currline] =TEMPWORDS[1];
        string tempdefstring ="";
        for (int i =3;i<x+1;i++){
            tempdefstring +=TEMPWORDS[i];
            tempdefstring +=" ";
        }
        DEFINITIONS[currline]=tempdefstring;
        currline++;
    }
    fin.close();
}

/*
    @param            :   The string with a query word
    @return           :   Integer index of the word in 
                         `WORDS` global array. Returns 
                          -1 if the word is not found
    @post             :   Find the index of given `word` 
                          in the `WORDS` array. Return -1 
                          if word is not in the array
*/
int getIndex(string word){
    for(int i = 0;i<MAX_WORDS;i++){
        if(WORDS[i]==word)
            return i;
    }
    return -1;
}

/*
    @param            :   The string with a query word
    @return           :   Return the string definition of 
                          the word from  `DEFINITIONS` 
                          global array. Return "NOT_FOUND" 
                          if word doesn't exist in the dictionary
    @post             :   Find the definition of the given `word`. 
                          Return "NOT_FOUND" otherwise
*/
string getDefinition(string word){
    if(getIndex(word))
        return DEFINITIONS[getIndex(word)];
    else
        return "NOT_FOUND";
}

/*
    @param            :   The string with a query word
    @return           :   Return the string part of speech(POS) 
                          from the `POS` global array. Return 
                          "NOT_FOUND" if the word doesn't exist 
                          in the dictionary.
    @post             :   Find the POS of the given `word`. 
                          Return "NOT_FOUND" otherwise.
*/
string getPOS(string word){
    if(getIndex(word))
        return POS[getIndex(word)];
    else
        return "NOT_FOUND";
}

/*
    @param            :   The string prefix of a word (the prefix 
                          can be of any length)
    @return           :   Integer number of words found that starts 
                          with the given `prefix`
    @post             :   Count the words that start with the given 
                          `prefix`
*/
int countPrefix(string prefix){
    int num =0;
    for (auto word:WORDS){
        if(word.length()>prefix.length()){
            bool match = true;
            for(int i=0;i<prefix.length();i++){
                if(word[i]!=prefix[i])
                    match =false;
            }
            if(match)
                num++;
        }
    }
}

int main() {
    readWords("words.txt");
    for (int i = 0; i <5;i++){
        cout<<WORDS[i]<<endl;
        cout<<POS[i]<<endl;
        cout<<DEFINITIONS[i]<<endl;
    }
    
    return 0;
}