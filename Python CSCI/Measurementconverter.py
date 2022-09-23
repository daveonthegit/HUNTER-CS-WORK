#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 9/15/22
#This program converts measurements given three options to the user.

print('(a) convert centimeters to feet\n(b) convert centimeters to feet and inches\n(c) convert feet and inches to centimeters')
conMode = input('Enter a or b or c: ')
match conMode:
    case 'a':
        height = float(input('Enter height in centimeters: '))
        height/=30.48
        height=round(height,2)
        print('height is ' + str(height)+' feet')
    case 'b':
        height = float(input('Enter height in centimeters: '))
        feet = int(height/30.48)
        inches = int((height-(feet*30.48))/2.54)
        if(inches>0):
            print('height is '+str(feet)+' feet and '+str(inches)+' inches')
        else:
            print('height is '+str(feet)+' feet')
    case 'c':
        feet, inches = input("Enter height in feet and inches, separated by a space: ").split()
        feet= int(feet)
        inches = int(inches)
        height = int(round(float(feet)*30.48+float(inches)*2.54,0))
        print('height is '+ str(height)+' cm')
    case other:
        print('Wrong choice, please enter only a or b or c.')
        
            
