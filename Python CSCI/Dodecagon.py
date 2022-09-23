#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 8/30/22
#This program draws a dodecagon

import turtle
wn = turtle.Screen()

t = turtle.Turtle()
x = 12 #Dodecagon is 12 sides, using variable allows you to change the shape easier.
for i in range(0,x):
    t.forward(30)
    t.left(360/x)
wn.exitonclick()