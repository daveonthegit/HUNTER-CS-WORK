#Name:  David Xiao
#Email:  david.xiao67@myhunter.cuny.edu
#Date: September 5, 2022
#This program shifts a color of pink


import turtle				
wn=turtle.Screen()
turtle.colormode(255)		
t = turtle.Turtle()		
t.shape("turtle")		
t.backward(100)			
def turtleMove(x):
    t.forward(10)		
    t.pensize(x)		
    t.color(x,0,x)
for i in range(0,255,10):
    turtleMove(i)
for i in range(255,0,-10):
    turtleMove(i)

wn.exitonclick()