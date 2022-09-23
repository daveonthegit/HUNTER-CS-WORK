#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 9/8/22
#This program takes a name list input, and separates it and prints it back in Initial. Lastname order. G. Washington

names = input("Enter a list of names, separated by semicolon: ").split(";")
for x in names:
    x = x.split()
    print(x[0][0]+". "+x[1])

