#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 9/1/22
#This program prints the letter ascii and the two letters ahead value of a character.

x = input("Enter a phrase: ")
print("%6s %5s %15s"%("letter", "ASCII", "next_two_letter"))
for i in x:
    print("%6c %5i %15c"%(i, ord(i), chr(ord(i)+2)))
