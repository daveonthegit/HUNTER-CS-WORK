#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 11/23/22
#This program is a game where user and computer generate an integer from 1-6, then if the sum of these integers meet a defined condition the user or computer wins.

import random
from numpy import array
def intCheck():
    num = int(input('Enter only 1-6: '))
    if(num >0 and num <7):
        return num
    else:
        print('Input needs to be in 1-6. Re-enter: ')
        return intCheck()

def prog():
    user = intCheck()
    comp = random.randint(1, 6)
    winCon = array([3,6,7,8])
    print("user: "+ str(user))
    print("computer: "+ str(comp))
    if(user==comp):
        print('draw')
    elif(any(winCon==user+comp)):
        print('user wins')
    else:
        print('computer wins')

def main():
    prog()

if __name__ == '__main__':
    main()