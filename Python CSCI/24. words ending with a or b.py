#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 11/3/22
#This program counts number of words ending in a or b and prints fraction


wlist = input('Enter a list of words, separated by a space: ').split()
print('number of words: '+str(len(wlist)))
numab=0
for i in wlist:
    if(list(i)[-1] in ['a','b']):
        numab+=1

print('number of words ending with a or b: ' + str(numab))
print('fraction of words starting with a or b: '+ str(round((numab/len(wlist)),2)))