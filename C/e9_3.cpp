/*
Author: David Xiao
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Exercise 9.3

lightswitch
*/
#include <iostream>
using namespace std;
class Circuit {
	public:
        int get_first_switch_state(){
            return first_switch;
        }
		int get_second_switch_state(){
            return second_switch;
        }
		int get_lamp_state(){
            return lamp_state;
        }
		void toggle_first_switch(){
            if(first_switch ==1){
                first_switch = 0;
            }else{
                first_switch = 1;
            }
            if(lamp_state == 0){
                lamp_state = 1;
            }else{
                lamp_state = 0;
            }
        }
		void toggle_second_switch(){
            if(second_switch ==1){
                second_switch = 0;
            }else{
                second_switch = 1;
            }
            if(lamp_state == 0){
                lamp_state = 1;
            }else{
                lamp_state = 0;
            }
        }
	private:
		int first_switch = 0;
		int second_switch = 0;
		int lamp_state = 0;
};