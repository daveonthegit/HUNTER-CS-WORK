#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 11/23/22
#This program is a game where user and computer generate an integer from 1-6, then if the sum of these integers meet a defined condition the user or computer wins.

import random
def intCheck():
    num = int(input('Enter only 1-6: '))
    while(num <1 or num >6):
        print('Input needs to be in 1-6. Re-enter: ')
        num = int(input('Enter only 1-6: '))
    return num

def main():
    user = intCheck()
    comp = random.randint(1, 6)
    print("user: " + str(user))
    print("computer: "+ str(comp))
    if(user==comp):
        print('draw')
    elif(3==user+comp or 6==user+comp or 7==user+comp or 8==user+comp):
        print('user wins')
    else:
        print('computer wins')

if __name__ == '__main__':
    main()