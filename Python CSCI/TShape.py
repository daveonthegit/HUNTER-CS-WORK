#Name:  David Xiao
#Email:  david.xiao67@myhunter.cuny.edu
#Date: September 5, 2022
#This program makes a T shape using a numpy plot.

import matplotlib.pyplot as plt
import numpy as np
img = np.zeros((30,30,3), dtype=np.uint8)

img[:,:,0]=255
img[:,:,1]=255
for y in range(5,8):
    for x in range(5,25):
        print(x)
        print(y)
        img[y,x,0] = 0
        img[y,x,1] = 0
        img[y,x,2] = 255
for y in range(8,25):
    for x in range(13,16):
        img[y,x,0] = 0
        img[y,x,1] = 255
        img[y,x,2] = 0
print(img)
plt.imsave(input("Enter output file name: "), img) 
