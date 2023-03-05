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
#include <cctype>
using namespace std;
//GLOBAL VARIABLES

const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

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
        string TEMPWORDS[g_MAX_WORDS];
        for (int i=0;i<line.length();i++){
            if(line[i]==' ')
                x++;
            else
                TEMPWORDS[x]+=line[i];
        }
        
        g_words[currline] =TEMPWORDS[0];
        g_pos[currline] =TEMPWORDS[1];
        string tempdefstring ="";
        for (int i =3;i<x+1;i++){
            tempdefstring +=TEMPWORDS[i];
            if(i!=x)
                tempdefstring +=" ";
        }
        g_definitions[currline]=tempdefstring;
        currline++;
        g_word_count++;
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
    for(int i = 0;i<g_word_count;i++){
        if(g_words[i]==word)
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
    if(getIndex(word)>-1)
        return g_definitions[getIndex(word)];
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
    if(getIndex(word)>-1)
        return g_pos[getIndex(word)];
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
    for (auto word:g_words){
        if(word.length()>=prefix.length()){
            bool match = true;
            for(int i=0;i<prefix.length();i++){
                if(tolower(word[i])!=tolower(prefix[i]))
                    match =false;
            }
            if(match)
                num++;
        }
    }
    return num;
}

int main() {
    readWords("words.txt");
    for (int i = 0; i <5;i++){
        cout<<g_words[i]<<endl;
        cout<<g_pos[i]<<endl;
        cout<<g_definitions[i]<<endl;
    }
    cout<<countPrefix("wo")<<endl;
    cout<<getIndex("WORD")<<endl;
    cout<<getDefinition("WORD")<<endl;
    cout<<getPOS("WORD")<<endl;

    return 0;
}



/*
    @param word       :   The string with a new word
    @param definition :   The string with the definition of the
                          new `word`
    @param pos        :   The string with the pos of the new `word`
    @return           :   return `true` if the word is
                          successfully added to the dictionary
                          return `false` if failed (word already
                          exists or dictionary is full)
    @post             :   Add the given `word`, `definition`, `pos`
                          to the end of the respective
                          global-arrays.
                          The word should not be added to the
                          global-arrays if it already exists 
                          or if the array reached maximum 
                          capacity(`g_MAX_WORDS`).
                          Update `g_word_count` if the word is
                          successfully added
*/
bool addWord(string word, string definition, string pos){
    if(getIndex(word)==-1&&g_word_count<g_MAX_WORDS){
        g_word_count++;
        g_words[g_word_count]=word;
        g_definitions[g_word_count]=definition;
        g_pos[g_word_count]=pos;
        return true;
    }
    return false;
}

/*
    @param word       :   The string with the word that is to
                          be edited
    @param definition :   The string with the new definition of 
                          the `word`
    @param pos        :   The string with the new pos of the `word`
    @return           :   return `true` if the word is successfully
                          edited, return `false` if the `word`
                          doesn't exist in the dictionary
    @post             :   Replace the given `word`'s  definition
                          and pos with the given `definition` and
                          `pos` (by modifying global-arrays
                          `g_definitions` and `g_pos`).
                          The modification will fail if the word
                          doesn't exist in the dictionary
*/
bool editWord(string word, string definition, string pos){
    if(getIndex(word)==-1)
        return false;
    g_definitions[getIndex(word)] = definition;
    g_pos[getIndex(word)]=pos;
    return true;
}

/*
    @param            :   The string with the word that is to
                          be removed
    @return           :   return `true` if the word is successfully
                          removed from the dictionary return `false`
                          if the word doesn't exist in the dictionary
    @post             :   Remove the given `word`, `word`'s
                          definition and `word`'s pos from the
                          respective global-arrays if the word
                          exists.  
                          Update `g_word_count` if the word is
                          successfully removed
*/
bool removeWord(string word){
    if(getIndex(word)==-1)
        return false;
    g_words[getIndex(word)] = g_words[g_word_count];
    g_words[g_word_count] = "";
    g_definitions[g_word_count]="";
    g_pos[g_word_count]="";
    g_word_count--;

    return true;
}