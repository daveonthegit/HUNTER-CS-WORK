#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 9/2/22
#This program changes cyan shades up and right.

import turtle				

turtle.colormode(255)		
t = turtle.Turtle()		
t.shape("turtle")
t.penup()
t.backward(100)
t.left(90)
t.backward(100)
t.right(90) 
t.pendown()		
def turtleShade(t,i):
    t.forward(10)		
    t.pensize(i)		
    t.color(0,i,i)		
for y in range(0,2):
    t.pendown()
    for i in range(0,255,10):
        turtleShade(t,i)
    t.pensize(0)
    t.penup()
    t.backward(250)	
    t.left(90)
    
turtle.Screen().exitonclick()