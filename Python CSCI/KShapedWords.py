#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 9/8/22
#This program takes a phrase and prints it, removing and adding words to print it into a K shape.

x = input("Enter a phrase: ").split()

for i in reversed(range(1,len(x)+1)):
    print(' '.join(x[:i]))
for i in range(2,len(x)+1):
    print(' '.join(x[:i]))