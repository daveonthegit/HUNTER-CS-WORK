#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 9/1/22
#This program cipher shifts a phrase.

phrase = input("Enter an all-small-letter string: ")
shift = int(input("Enter a non-negative int to shift: "))
ciphered =""
for i in phrase:
    z =ord(i)+shift
    if(z>122):
        z-=26
    ciphered+=chr(z)

print("ciphered string: " + ciphered)