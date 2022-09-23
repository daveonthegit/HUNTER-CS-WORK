#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 9/1/22
#This program draws a purina logo
import turtle
from turtle import *
wn = turtle.Screen()
lst = ["green","blue","cyan","red"] #grade scope work properly when I use a list, even though the program works.
t = turtle.Turtle()
t.pensize(5)
t.shape("circle")
def turtleMove(x):
    t.color(x)
    t.forward(300)
    t.right(90)
    t.forward(100)
    t.right(90)
    t.forward(100)
    t.right(90)
for x in lst:
   turtleMove(x)

wn.exitonclick()

