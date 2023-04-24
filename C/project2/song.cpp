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
int g_capacity = 2;
int g_size = 0;
class Song{
    public:
        string name;
        string artist;
        int duration;
        string genre;
        
    private:

};

Song *g_songs = new Song[g_capacity];


/*
    @post             :   Replace the old global
                          dynamically allocated arrays
                          with new dynamically allocated
                          arrays of twice the size 
                          ('g_capacity' * 2). Update
                          'g_capacity' accordingly.
                          Make sure you copy the contents
                          of the older arrays. Do this
                          for the following global-arrays:
                          'g_song_names', 'g_artist_names', 
                          'g_song_durations', 'g_genres'
*/
void allocateNew(){
    Song* tempsongs = new Song[g_capacity*2];
    for(int i= 0 ; i<g_capacity;i++){
        tempsongs[i] = g_songs[i];
    }
    delete[] g_songs;
    g_songs = tempsongs;
    g_capacity*=2;
}

/*
    @param            :   The string with the 'filename'
    @post             :   Reads the song, artists,
                          song durations and genres into 
                          the global-arrays and set the 
                          value of 'g_size'
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
        if(g_size == g_capacity){
            allocateNew();
        }
        g_songs[g_size].name=song_name;
        g_songs[g_size].artist=artist_name;
        g_songs[g_size].genre=genre;
        g_songs[g_size].duration=stoi(dur);
        g_size++;
    }
}

void printSongs(){
    for (int i= 0 ; i <g_capacity;i++){
        cout<<g_songs[i].name<<"-"<<g_songs[i].artist<<"-"<<g_songs[i].genre<<"-";
        cout<<g_songs[i].duration;
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
Song * getGenreSongs(string genre, int &genreCount){
    Song *temp = new Song[g_size];
    genreCount= 0;
    for(int i = 0; i <g_size;i++){
        if(g_songs[i].genre==genre){
            temp[genreCount]=g_songs[i];
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
Song * getSongsFromDuration(int duration, int &durationsCount, int filter){
    Song *temp = new Song[g_size];
    durationsCount = 0;
    for(int i = 0; i <g_size;i++){
        if(filter ==0) {
            if(g_songs[i].duration>duration){
                temp[durationsCount]=g_songs[i];
                durationsCount++;
            }        
        } else if(filter ==1) {
            if(g_songs[i].duration<duration){
                temp[durationsCount]=g_songs[i];
                durationsCount++;
            }
        }else{
            if(g_songs[i].duration==duration){
                temp[durationsCount]=g_songs[i];
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
    string* temp =new string[g_size];
    for(int i = 0; i <g_size;i++){
        bool uniquename = true;
        for(int j =0; j <uniqueCount;j++){
            if(g_songs[i].artist==temp[j]){
                uniquename=false;
            }
        }
        if(uniquename){
            temp[uniqueCount] = g_songs[i].artist;
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
    if(g_size==0){
        return "NONE";
    }
    int uniqueNames = 0;
    string* uniqueArtistsList = getUniqueArtists(uniqueNames);
    int artistCount[uniqueNames]= { }; 
    for(int i = 0; i<g_size;i++){
        for(int j = 0 ; j<uniqueNames;j++){
            if(g_songs[i].artist==uniqueArtistsList[j]){
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
    Song* genreSongsTemp = getGenreSongs("Hiphop", count);
    for (int i = 0; i<count;i++){
        cout<<genreSongsTemp[i].name<<endl;
    }
    int uniqueNames = 0;
    cout<<g_size<<endl;
    string* uniqueArtistsList = getUniqueArtists(uniqueNames);
    for (int i = 0; i<count;i++){
        cout<<uniqueArtistsList[i]<<endl;
    }
    cout<<getFavoriteArtist();
}