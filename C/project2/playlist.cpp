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
    g_song_names = g_song_names_temp;
    g_artist_names = g_artist_names_temp;
    g_song_durations = g_song_durations_temp;
    g_genres = g_genres_temp;
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
    ifstream fin(filename);
    if(fin.fail()){
        cerr<<"File cannot be opened for reading.";
        exit(1);
    }
    string line;
    string song_name, artist_name, genre, dur,junk;
    while(getline(fin,song_name, ':')&&getline(fin,artist_name, '-')&&getline(fin,genre, '-')&&getline(fin,dur, ' ')&&getline(fin,junk)){
        if(g_number_of_songs == g_curr_size){
            allocateNew();
        }
        g_song_names[g_number_of_songs]=song_name;
        g_artist_names[g_number_of_songs]=artist_name;
        g_genres[g_number_of_songs]=genre;
        g_song_durations[g_number_of_songs]=stoi(dur);
        g_number_of_songs++;
    }
}

void printSongs(){
    for (int i= 0 ; i <g_curr_size;i++){
        cout<<g_song_names[i]<<"-"<<g_artist_names[i]<<"-"<<g_genres[i]<<"-";
        cout<<g_song_durations[i];
        cout<<endl;
    }
}
/*
    @param genre              :   A string representing a genre
    @param(&) genreCount      :   An integer that will keep track of the number of songs
    @return                   :   A pointer to a dynamically allocated array of strings 
    @post                     :   Return a pointer to a dynamically allocated array of strings
                                  containing the names of the songs of given 'genre' and 
                                  update 'genreCount' to be the number of songs found.
                                  Return a pointer to an empty dynamically allocated array
                                  if no songs are found of the given 'genre'
    
    For example : Let's say we have the following 'g_song_names':
                  ["Killshot", "Takeover", "Spectre", "Ether", "No Title"]
                  
                  Let's say we have the following 'g_genres':
                  ["HipHop", "HipHop", "EDM", "HipHop", "JPop"]
                  
                  We try the following code with the above global-arrays:
                  int main(){
                    int count = 0;
                    string * genreSongs = getGenreSongs("HipHop", count);
                  }

                  In this case, 'genreSongs' will be pointing to the following:
                  ["Killshot", "Takeover", "Ether"]
                  The value of 'count' will be updated to 3 because there
                  are three "HipHop" songs on the playlist 
*/
string * getGenreSongs(string genre, int &genreCount){
    string *temp = new string[g_number_of_songs];
    genreCount= 0;
    for(int i = 0; i <g_number_of_songs;i++){
        if(g_genres[i]==genre){
            temp[genreCount]=g_song_names[i];
            genreCount++;
        }
    }
    return temp;
}

/*
    @param duration             :   The integer duration of the songs
    @param(&) durationsCount    :   An integer that will keep track of the number of songs
    @param filter               :   An integer(0, 1 or 2) representing the comparision filter
                                    0 = greater-than, 1 = less-than, 2 = equal-to
    @return                     :   A pointer to a dynamically allocated array of strings 
    @post                       :   Return a pointer to a dynamically allocated array of strings
                                    of songs that are either greater-than, less-than or equal-to
                                    the given 'duration' based on given 'filter'. Update parameter
                                    'durationsCount' with the number of songs found. Return a 
                                    pointer to an empty dynamically allocated array if no songs
                                    are found with the given parameters

    For example : Let's say we have the following 'g_song_names':
                  ["Major Crimes", "Never Fade Away", "Circus Minimus", "4aem", "Reaktion"]

                  Let's say we have the following 'g_song_durations':
                  [3, 4, 3, 5, 2]

                  We try the following code with the above global-arrays:
                  int main(){
                    int greater = 0;
                    int less = 0;
                    int equal = 0;
                    string * longSongs = getSongsFromDuration(3, greater, 0);
                    string * shortSongs = getSongsFromDuration(3, less, 1);
                    string * mediumSongs = getSongsFromDuration(3, equal, 2);
                  }

                  After running the above code, 'longSongs' will be:
                  ["Never Fade Away", "4aem"]
                  The value of 'greater' will be 2 because there are two songs 
                  greater than 3 mins duration

                  Similarly, 'shortSongs' will be:
                  ["Reaktion"]
                  The value of 'less' will be 1 because there is only one song 
                  less than 3 mins duration

                  Finally, 'mediumSongs' will be:
                  ["Major Crimes", "Circus Minimus"]
                  The value of 'equal' will be 2 because there are 2 songs
                  equal to 3 mins duration      
*/
string * getSongsFromDuration(int duration, int &durationsCount, int filter){
    string *temp = new string[g_number_of_songs];
    durationsCount = 0;
    for(int i = 0; i <g_number_of_songs;i++){
        if(filter ==0) {
            if(g_song_durations[i]>duration){
                temp[durationsCount]=g_song_names[i];
                durationsCount++;
            }        
        } else if(filter ==1) {
            if(g_song_durations[i]<duration){
                temp[durationsCount]=g_song_names[i];
                durationsCount++;
            }
        }else{
            if(g_song_durations[i]==duration){
                temp[durationsCount]=g_song_names[i];
                durationsCount++;
            }
        }

    }
    return temp;
}

/*
    @param      :   An integer that will keep track of unique artists
    @return     :   A pointer to a dynamically allocated array of strings 
    @post       :   Return a pointer to a dynamically allocated array of strings
                    containing the names of unique artists in 'g_artist_names'
                    and update 'uniqueCount' parameter to be the number of
                    unique artists found
    
    For example : Let's say we have the following 'g_artist_names':
                  ["Eminem", "Eminem", "Jay Z", "Jay Z", "Nas"]
                  
                  We try the following code with this 'g_artist_names':
                  int main(){
                    int count = 0;
                    string * uniques = getUniqueArtists(count);
                  }

                  In this case, 'uniques' will be pointing to the following:
                  ["Eminem", "Jay Z", "Nas"]
                  The value of 'count' will be updated to 3 because there
                  are three unique artists on the playlist     
*/
string * getUniqueArtists(int &uniqueCount){
    string* temp =new string[g_number_of_songs];
    for(int i = 0; i <g_number_of_songs;i++){
        bool uniquename = true;
        for(int j =0; j <uniqueCount;j++){
            if(g_artist_names[i]==temp[j]){
                uniquename=false;
            }
        }
        if(uniquename){
            temp[uniqueCount] = g_artist_names[i];
            uniqueCount++;
        }
    }
    return temp;
}
/* 
    @return     :   A string with the artist with most songs in playlist
    @post       :   Find the artist with the most songs in the playlist
                    If there are multiple such artists, return any one of them.
                    Return "NONE" if the playlist is empty

    For example : Let's say we have the following 'g_artist_names':
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Kendrick"]
                  The favorite artist here is "Kendrick" because he has 3 songs
                  However, consider the following 'g_artist_names':
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Drake"]
                  In this case, the favorite artist is either "J.Cole" or "Kendrick"
                  because both artists have 2 songs which is greater than any 
                  other artists in the playlist
*/
string getFavoriteArtist(){
    if(g_number_of_songs==0){
        return "NONE";
    }
    int uniqueNames = 0;
    string* uniqueArtistsList = getUniqueArtists(uniqueNames);
    int artistCount[uniqueNames]= { }; 
    for(int i = 0; i<g_number_of_songs;i++){
        for(int j = 0 ; j<uniqueNames;j++){
            if(g_artist_names[i]==uniqueArtistsList[j]){
                artistCount[j]++;
            }
        }
    }
    int largestIndex = 0;
    for(int i = 0;i<uniqueNames; i++ ){
        if(artistCount[i]>artistCount[largestIndex]){
            largestIndex = i;
        }
    }
    return uniqueArtistsList[largestIndex];
}

int main(){
    readSongs("example.txt");
    printSongs();
    int count = 0;
    string* genreSongsTemp = getGenreSongs("Hiphop", count);
    for (int i = 0; i<count;i++){
        cout<<genreSongsTemp[i]<<endl;
    }
    int uniqueNames = 0;
    cout<<g_number_of_songs<<endl;
    string* uniqueArtistsList = getUniqueArtists(uniqueNames);
    for (int i = 0; i<count;i++){
        cout<<uniqueArtistsList[i]<<endl;
    }
    cout<<getFavoriteArtist();
}