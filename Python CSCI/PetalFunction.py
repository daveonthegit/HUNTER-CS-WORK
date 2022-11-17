#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 11/17/22
#This program makes a flower using functions.

import turtle

t = turtle.Turtle(visible=False)
turtle.colormode(255)

def petal(color):
    for i in range(0,255,10):
        t.forward(10)
        t.pensize(i)
        if(color=='red'):
            t.pencolor(i,0,0)
        elif(color =="green"):
            t.pencolor(0,i,0)
        elif(color =="blue"):
            t.pencolor(0,0,i)
        elif(color =="yellow"):
            t.pencolor(i,i,0)
        elif(color =="purple"):
            t.pencolor(i,0,i)
        elif(color =="cyan"):
            t.pencolor(0,i,i)

def flower(color, numPetals):
    angle = 360/numPetals
    for i in range(numPetals):
        t.pendown()
        petal(color)
        t.penup()
        t.pensize(0)
        t.backward(260)	
        t.left(angle)

def main():
    flower('green', 9)

if __name__ == '__main__':
    main()

