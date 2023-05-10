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
    curr_exp+=exp;
    if(curr_exp>=req_exp){
        curr_exp-=req_exp;
        level++;
    }
    switch (specialty){
        case Specialty::ML:
            {
                req_exp+=10;
            }
            break;
        case Specialty::SOFTWARE:
            {
                req_exp+=15;
            }
            break;
        default:
            {
                req_exp+=20;
            }
            break;
    }
    if(curr_exp >=req_exp){
        return Profemon::levelUp(0);
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
    std::cout<<name;
    switch(specialty){
        case Specialty::ML:
            {
                std::cout<<" [ML] ";
            }
            break;
        case Specialty::SOFTWARE:
            {
                std::cout<<" [SOFTWARE] ";
            }
            break;
        default:
            {
                std::cout<<" [HARDWARE] ";
            }
            break;
    }
    std::cout<<"| lvl "<<level<<" | exp "<<curr_exp<<"/"<<req_exp<<" | hp "<<max_health<<std::endl;
    
    if(print_skills){
        if(skill[0].getName()!="Undefined"){
            std::cout<<skill[0].getName()<<" ["<<skill[0].getTotalUses()<<"] : "<<skill[0].getDescription()<<std::endl;
        }
        if(skill[1].getName()!="Undefined"){
            std::cout<<skill[1].getName()<<" ["<<skill[1].getTotalUses()<<"] : "<<skill[1].getDescription()<<std::endl;
        }
        if(skill[2].getName()!="Undefined"){
            std::cout<<skill[2].getName()<<" ["<<skill[2].getTotalUses()<<"] : "<<skill[2].getDescription()<<std::endl;
        }
    }
}