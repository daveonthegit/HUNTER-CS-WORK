/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 10
Time class and enums
*/

#include <iostream>
using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Time { 
public:
    int h;
    int m;
};

class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

int minutesSinceMidnight(Time time){ // returns minutes since midnight
    return (time.h*60)+time.m;
}

int minutesUntil(Time earlier, Time later){ //returns minutes between two times
    return minutesSinceMidnight(later)-minutesSinceMidnight(earlier);
}

void printMovie(Movie mv){ // prints movie, uses switch case to check genre and set g to the genre;
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTime(Time time) {//prints time
    cout << time.h << ":" << time.m;
}
Time addMinutes(Time time0, int min){//add minutes to time, if minutes exceed 60, reduce by 60 and increase hr by 1
    Time temp = time0;
    temp.m += min;
    while(temp.m > 59){
        temp.m-=60;
        temp.h+=1;
    }
    return temp;
}
void printTimeSlot(TimeSlot ts){
    printMovie(ts.movie);
    cout<<" [starts at ";
    printTime(ts.startTime);
    cout<<", ends by ";
    printTime(addMinutes(ts.startTime,ts.movie.duration));
    cout<<"]"<<endl;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot temp = ts;
    temp.startTime = addMinutes(temp.startTime,temp.movie.duration);
    temp.movie = nextMovie;
    return temp;
}
bool timeOverlap(TimeSlot ts1, TimeSlot ts2){ //compares which timeslot is earlier, then uses that to see if they overlap
    TimeSlot* earlier;
    TimeSlot* later;
    if(minutesUntil(ts1.startTime,ts2.startTime)>0){
        earlier = &ts1;
        later = &ts2;
    } else{
        earlier = &ts2;
        later = &ts1;
    }
    if(minutesSinceMidnight(addMinutes(earlier->startTime,earlier->movie.duration)) >minutesSinceMidnight(later->startTime)){
        return true;
    }
    return false;
}

int main(){
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"John Wick 4", ACTION, 169};
    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}};
    TimeSlot noon = {movie3,{13,15}};
    int eh, em;
    int lh, lm;
    cout<<"Enter first time: ";
    cin>> eh>>em;
    cout<<"Enter second time: ";
    cin>>lh>>lm;
    Time e = {eh,em};
    Time l = {lh,lm};
    cout<<"These moments of time are "<< minutesSinceMidnight(e)<<" and "<< minutesSinceMidnight(l)<<" minutes after midnight."<<endl;
    cout<<"The interval between them is "<<minutesUntil(e,l)<<endl;
    cout<<"Current time for earlier: ";
    printTime(e);
    cout<<endl;
    cout<<"Enter minutes to add: ";
    int ma;
    cin>>ma;
    printTime(addMinutes(e,ma));
    cout<<endl;
    printTimeSlot(morning);
    printTimeSlot(daytime);
    printTimeSlot(noon);
    printTimeSlot(evening);
    cout<<timeOverlap(morning,daytime)<<endl;
    morning = scheduleAfter(morning,movie3);
    printTimeSlot(morning);
    cout<<timeOverlap(morning,daytime)<<endl;

}