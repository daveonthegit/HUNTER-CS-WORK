/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 2

returns pronunciation of a word.
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void splitOnSpace(string s, string & before, string & after) {
  // reset strings
    before = ""; 
    after = "";
  // accumulate before space
    int i = 0;
    while (i < s.size() && not isspace(s[i])) { 
        before = before + s[i]; 
        i++; 
    }
  // skip the space
    i++;
    // accumulate after space
    while (i < s.size()) { 
        after = after + s[i]; 
        i++; 
    }
}

string dictionary_pronunciation_lookup(ifstream &dict,string search) {
    string word, pronunciation;
    dict.clear(); // reset error state
    dict.seekg(0); // return file pointer to the beginning
    string line;
    while (getline(dict, line)){
        splitOnSpace(line,word,pronunciation);  

        if(word == search){
            return pronunciation;
        }
    }
    return "";
}

void print_identicals(ifstream &dict ,string pronunciation,string oword){
    string line;
    string word,tpron;
    dict.clear(); // reset error state
    dict.seekg(0); // return file pointer to the beginning
    while(getline(dict, line)){
        splitOnSpace(line,word,tpron);  
        if(tpron == pronunciation&&word!=oword){
            cout<<word<<" ";
        }
    }
    cout<<endl;
}

int main() {
    ifstream dict("cmudict.0.7a");
    string word;
    cout<<"please enter a word: ";
    cin>> word;
    for(int i = 0; i <word.length();i++){
        word[i]=toupper(word[i]);
    }
    string pronunciation = dictionary_pronunciation_lookup(dict, word);
    cout<<"Pronunciation: "<<pronunciation<<endl;
    cout<<"Identicals: ";
    print_identicals(dict, pronunciation,word);
}