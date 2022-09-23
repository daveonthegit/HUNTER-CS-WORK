#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 9/1/22
#This program reverses a phrase, then uppercases, then abbreviates it.

oPhrase = input("input: ")
rAbbrev = [w[0] for w in oPhrase.upper().split()]
print("user reverse: " + oPhrase[::-1])
print("user reverse upper: " + oPhrase[::-1].upper())
print("user abbreviation: " + (''.join(rAbbrev)))   