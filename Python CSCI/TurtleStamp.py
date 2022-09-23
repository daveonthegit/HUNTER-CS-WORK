#Name:  David Xiao
#Email:  david.xiao67@myhunter.cuny.edu
#Date: September 5, 2022
#This program stamps a turtle triangle.


import turtle				
wn=turtle.Screen()
turtle.colormode(255)		
t = turtle.Turtle()		
t.shape("turtle")		
t.backward(100)			
t.color(150, 75, 0)
for i in range(0,3):
    t.forward(100)
    t.left(120)
    t.stamp()
wn.exitonclick()