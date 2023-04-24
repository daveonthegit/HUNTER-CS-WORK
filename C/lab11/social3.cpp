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
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network(){
    numUsers = 0;
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
};
int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}
