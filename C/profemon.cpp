/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 3
Profemon
*/
#include "profemon.hpp"
#include <iostream>
#include <string>
Profemon::Profemon(){
    name = "Undefined";
}

Profemon::Profemon(std::string name, double max_health, Specialty specialty){
    this->name = name;
    this->max_health = max_health;
    this->specialty = specialty;
    this->req_exp =50;
    this->curr_exp=0;
    this->level = 0;
}

std::string Profemon::getName(){
    return name;
}

Specialty Profemon::getSpecialty(){
    return specialty;
}

int Profemon::getLevel(){
    return level;
}

double Profemon::getMaxHealth(){
    return max_health;
}

void Profemon::setName(std::string name){
    this->name = name;
}

void Profemon::levelUp(int exp){
    curr_exp += exp;
    while(curr_exp >= req_exp){
        curr_exp -=req_exp;
        level++;
        if(specialty == ML){
            req_exp += 10;
        }
        else if(specialty == SOFTWARE){
            req_exp += 15;
        }
        else if(specialty == HARDWARE){
            req_exp += 20;
        }
    }

}

bool Profemon::learnSkill(int slot, Skill skill){
    if(slot <0||slot>2||skill.getSpecialty()!=specialty){
        return false;
    }
    this->skill[slot]=skill;
    return true;
}

void Profemon::printProfemon(bool print_skills){
    std::string test1 = "ML";
    std::string test2 = "SOFTWARE";
    std::string test3 = "HARDWARE";
    std::string test4;
    if(specialty == 0){
        test4 = test1;
    }
    else if(specialty == 1){
        test4 = test2;
    }
    else if(specialty == 2){
        test4 = test3;
    }
    std::cout << name << " [" << test4 << "] | lvl " << level << " | exp " 
    << curr_exp << "/" << req_exp << " | hp " << max_health << std::endl;
    if(print_skills){
        for(int i = 0; i < 3; i++){
            if(skill[i].getTotalUses() != -1){
                std::cout <<"    " <<skill[i].getName() << " [" << skill[i].getTotalUses() << "] : "
                << skill[i].getDescription() << std::endl;
            }
        }
    }
}