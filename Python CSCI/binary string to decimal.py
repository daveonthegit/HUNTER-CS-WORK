#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 11/3/22
#This program converts binary string to decimal

from re import L


s = input('Enter a string with 0 or 1 only: ')
num=0
base =2
weight =1
length = len(s)
for i in reversed(list(s)):
    if(i =='1'):
        num+=weight
    elif(i!='0'):
        print('Letter ' +i+' is not allowed in binary string.')
        exit()
    weight*=base
print(num)