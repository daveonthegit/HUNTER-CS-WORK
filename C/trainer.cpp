/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 3
Profemon
*/

#include "trainer.hpp"
#include <string>
#include <vector>
Trainer::Trainer(){
    current_profemon=nullptr;
}

Trainer::Trainer(std::vector <Profemon> profemons){
    for(int i =0;i<3;i++){
        if(team[i].getName()=="Undefined"){
            team[i]=profemons[0];
            profemons.erase(profemons.begin());
        }
    }
    for(auto x:profemons){
        profedex.push_back(x);
    }
    current_profemon=&team[0];
}

bool Trainer::contains(std::string name){
    for(int i =0;i<3;i++){
        if(team[i].getName()==name){
            return true;
        }
    }
    for(auto x:profedex){
        if(x.getName()==name){
            return true;
        }
    }
    return false;
}

bool Trainer::addProfemon(Profemon profemon){
    if(Trainer::contains(profemon.getName())){
        return false;
    }
    for(int i =0;i<3;i++){
        if(team[i].getName()=="Undefined"){
            team[i]=profemon;
            return true;
        }
    }
    profedex.push_back(profemon);
    return true;
}

bool Trainer::removeProfemon(std::string name){
    if(Trainer::contains(name)){
        for(int i =0;i<3;i++){
            if(team[i].getName()==name){
                Profemon temp;
                team[i]=temp;
                return true;
            }
        }
        for(int i =0;i<profedex.size();i++){
            if(profedex[i].getName()==name){
                profedex.erase(profedex.begin()+i);
                return true;
            }
        }
    }
    return false;
}

void Trainer::setTeamMember(int slot, std::string name){

}

bool Trainer::chooseProfemon(int slot){
    current_profemon=*team[slot];
}

Profemon Trainer::getCurrent(){
    return current_profemon;
}

void Trainer::printProfedex(){

}

void Trainer::printTeam(){

}