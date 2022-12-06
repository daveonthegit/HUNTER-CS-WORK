#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 11/21/22
#This program returns if a number is perfect or not
import math
def isPerfect(num):
    sum = 0
    if (num <0):
        return False
    else:
        for i in range(1,math.ceil(num/2)+1):
            if num%i==0:
                sum+=i
        if num== sum:
            return True
        else:
            return False

def main():
    num = int(input("Enter a perfect integer: "))
    x = True
    while (x):
        if(isPerfect(num)):
            x = False
        else:
            print(num, "is not a perfect number.")
            num =  int(input('Please enter a new number: '))
    else:
        print(str(num)+ ' is a perfect number')

if __name__=='__main__':
    main()