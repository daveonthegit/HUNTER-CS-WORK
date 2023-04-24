/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 11

Social profile

*/


#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;
struct Post{
  string username;
  string message;
};
class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn){
        username = usrn;
        displayname = dspn;
    }
    // Default Profile constructor (username="", displayname="")
    Profile(){
        username="";
        displayname="";
    }
    // Return username
    string getUsername(){
        return username;
    }
    // Return name in the format: "displayname (@username)"
    string getFullName(){
        return displayname+" (@"+username+")";
    }
    // Change display name
    void setDisplayName(string dspn){
        displayname = dspn;
    }
};
class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn){
    for(int i=0;i<numUsers;i++){
        if(profiles[i].getUsername()==usrn){
            return i;
        }
    }
    return -1;
  }

   bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
 // following[id1][id2] == true when id1 is following id2
  static const int MAX_POSTS = 100;
 int numPosts;                    // number of posts
 Post posts[MAX_POSTS];           // array of all posts

public:
  // Constructor, makes an empty network (numUsers = 0)
  Network(){
    numUsers = 0;
    numPosts = 0;
    for(int x = 0; x<MAX_USERS;x++){
        for(int y=0;y<MAX_USERS;y++){
            following[x][y]=false;
        }
    }
  }
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn){
    if(numUsers==MAX_USERS){
        return false;
    }
    for(int i = 0;i<numUsers;i++){
        if(profiles[i].getUsername()==usrn){
            return false;
        }
    }
    for(char c:usrn){
        if(!isalnum(c))
            return false;
    }
    Profile tempuser(usrn, dspn);
    profiles[numUsers] = tempuser;
    numUsers++;
    return true;
  }
    // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
    // return true if success (if both usernames exist), otherwise return false
    bool follow(string usrn1, string usrn2){
        int u1,u2;
        u1=findID(usrn1);
        u2=findID(usrn2);
        if(u1!=-1&&u2!=-1){
            following[u1][u2]=true;
            return true;
        }
        return false;
    }
    string* getFollowers(string usrn){
        string* followers = new string[numUsers];
        int user =findID(usrn);
        int x = 0;
        for(int i = 0;i<numUsers;i++){
            if(following[user][i]){
                followers[x] =profiles[i].getUsername();
                x++;
            }
        }
        return followers;
    }
    // Print Dot file (graphical representation of the network)
    void printDot(){
        cout<<"digraph {\n";
        for(int i =0;i<numUsers;i++){
            cout<<"\t\"@"<<profiles[i].getUsername()<<"\"\n";
        }
        for(int x = 0; x<numUsers;x++){
            for(int y =0;y<numUsers;y++){
                if(following[x][y]){
                    cout<<"\t\"@"<<profiles[x].getUsername()<<"\" -> \"@"<<profiles[y].getUsername()<<"\"\n";
                }
            }
        }
        cout<<"}";
    }
     // Add a new post
     bool writePost(string usrn, string msg){
        if(numPosts==MAX_POSTS){
            return false;
        }
        bool validUser=false;
        for(auto p:profiles){
            if(p.getUsername()==usrn){
                validUser=true;
            }
        }
        if(validUser){
            posts[numPosts].username = usrn;
            posts[numPosts].message = msg;
            numPosts++;
        }
        return validUser;
     }
     // Print user's "timeline"
    bool printTimeline(string usrn){
        if(findID(usrn)==-1){
            return false;
        }
        string* validUsernames=getFollowers(usrn);
        for(int i = numPosts-1;i>=0;i--){
            for(int j = 0;j<numUsers;j++){
                if(posts[i].username==validUsernames[j]){
                    cout<<profiles[findID(validUsernames[j])].getFullName()<<": "<<posts[i].message<<endl;
                }
            }
            if(posts[i].username==usrn){
                cout<<profiles[findID(usrn)].getFullName()<<": "<<posts[i].message<<endl;
            }
        }
        return true;
    }
};
int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}