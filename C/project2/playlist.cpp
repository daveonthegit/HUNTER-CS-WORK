/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 2
Dynamically Allocated Playlists

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int g_curr_size = 2;
int g_number_of_songs = 0;

string *g_song_names = new string[g_curr_size];
string *g_artist_names = new string[g_curr_size];
int *g_song_durations = new int[g_curr_size];
string *g_genres = new string[g_curr_size];

/*
    @post             :   Replace the old global
                          dynamically allocated arrays
                          with new dynamically allocated
                          arrays of twice the size 
                          ('g_curr_size' * 2). Update
                          'g_curr_size' accordingly.
                          Make sure you copy the contents
                          of the older arrays. Do this
                          for the following global-arrays:
                          'g_song_names', 'g_artist_names', 
                          'g_song_durations', 'g_genres'
*/
void allocateNew(){
    string* g_song_names_temp = new string[g_curr_size*2];
    string* g_artist_names_temp = new string[g_curr_size*2];
    int* g_song_durations_temp = new int[g_curr_size*2];
    string* g_genres_temp = new string[g_curr_size*2];
    for(int i= 0 ; i<g_curr_size;i++){
        g_song_names_temp[i] = g_song_names[i];
        g_artist_names_temp[i] = g_artist_names[i];
        g_song_durations_temp[i] = g_song_durations[i];
        g_genres_temp[i]=g_genres[i];
    }
    delete[] g_song_names;
    delete[] g_artist_names;
    delete[] g_song_durations;
    delete[] g_genres;
    string* g_song_names = g_song_names_temp;
    string* g_artist_names = g_artist_names_temp;
    int* g_song_durations = g_song_durations_temp;
    string* g_genres = g_genres_temp;
    g_curr_size*=2;
}

/*
    @param            :   The string with the 'filename'
    @post             :   Reads the song, artists,
                          song durations and genres into 
                          the global-arrays and set the 
                          value of 'g_number_of_songs'
                          to the number of songs read.
                          Call 'allocateNew()' to allocate 
                          an array of larger size if the 
                          dynamic arrays reach full 
                          capacity.
*/
void readSongs(string filename){
    cout<<"test";
    ifstream songs(filename);
    if(songs.fail()){
        cerr<<"File cannot be opened for reading.";
        exit(1);
    }
    string line;
    int i = 0;
    while(getline(songs,line)){
        int type =0;
        string tempdur ="";

        if(i >= g_curr_size){
            allocateNew();
        }
        for(int j = 0; j<line.length();i++){
            if(line[j]==':'||line[j]=='-'){
                type++;
            }else{
                switch(type){
                    case 0: g_song_names[i]+=line[j]; break;
                    case 1: g_artist_names[i]+=line[j]; break;
                    case 2: g_genres[i]+=line[j]; break;
                    case 3: tempdur+= line[j]; break;
                }
            }
        }
        g_song_durations[i] = stoi(tempdur);
        i++;
    }
}

void printSongs(){
    for (int i= 0 ; i <g_curr_size;i++){
        cout<<g_song_names[i]<<"-"<<g_artist_names[i]<<"-"<<g_genres[i]<<"-";
        cout<<g_song_durations[i];
        cout<<endl;
    }
}

int main(){
    readSongs("example.txt");
    printSongs();
}