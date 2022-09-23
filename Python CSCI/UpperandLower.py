#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 9/1/22
#This program takes in an upper/lower case input and converts it

name = input("Enter name in format firstName lastName: ")
nameArray = name.split()
lName = nameArray[1].upper()
fName = nameArray[0]
print("name in LASTNAME, firstName format: "+ lName +", " +fName)
username = input("nter user name of email: ")
print("email: "+username.lower()+"@hunter.cuny.edu")
