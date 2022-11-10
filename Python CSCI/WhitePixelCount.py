#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 11/3/22
#This program counts white pixels in a given image past the inputted threshold.

#Import the packages for images and arrays:
import matplotlib.pyplot as plt
import numpy as np


ca = plt.imread(input('Enter file name: '))   #Read in image
countSnow = 0            #Number of pixels that are almost white
t = input('Enter threshold: ')                 #Threshold for almost white-- can adjust between 0.0 and 1.0

#For every pixel:
for i in range(ca.shape[0]):
     for j in range(ca.shape[1]):
          #Check if red, green, and blue are > t:
          if (ca[i,j,0] > t) and (ca[i,j,1] > t) and (ca[i,j,2] > t):
               countSnow = countSnow + 1

print("number of white pixels: ", countSnow)
print('percent of white pixels: ', float(countSnow/len(ca.shape[0])*len(ca.shape[1])), ' %')