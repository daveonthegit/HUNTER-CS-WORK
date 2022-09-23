#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 8/30/22
#This program draws a flower
import turtle
from turtle import *
wn = turtle.Screen()

t = turtle.Turtle()
for i in range(0,9):
    t.forward(100)
    t.left(105)
    t.forward(52)
    t.left(105)
    t.forward(100)
    t.right(170)
wn.exitonclick()

