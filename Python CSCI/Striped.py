#Name:  David Xiao
#Email:  david.xiao67@myhunter.cuny.edu
#Date: September 15, 2022
#This program makes an image of blue and green stripes

import matplotlib.pyplot as plt
import numpy as np
size = int(input("Enter the size: "))
img = np.zeros((size,size,3), dtype=np.uint8)
for y in range(len(img)):
    for x in range(len(img[0])):
        if(x%2==0):
            img[y,x,2] = 255
        else:
            img[y,x,1] = 255
print(img)
plt.imsave(input("Enter output file: "), img) 