#Name:  David Xiao
#Email:  david.xiao67@myhunter.cuny.edu
#Date: September 5, 2022
#This program takes an image and gets rid of the red.

import matplotlib.pyplot as plt
import numpy as np

img = plt.imread(input("Enter name of the input file: "))
img[:,:,0]=0
plt.imsave(input("Enter name of the output file: "), img) 
