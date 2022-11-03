hunger = 0
bored = 0
state = str('HAPPY')

while (state != 'SAD'):
  print('Tamagotchi current state is:', state)
  i = input('Action: ')
  if (i == 'feed'):
    if (hunger>0) :
      hunger-=1
    bored += 1
  elif ( i == 'play'):
    if (bored>0) :
      bored-=1
    hunger+=1
  elif ( i == 'ignore'):
    hunger+=1
    bored += 1
  elif ( i == 'save'):
    f = open('save.txt', mode='w', encoding='utf-8')
    f.write(str(state)+'\n')
    f.write(str(hunger) +'\n')
    f.write(str(bored) + '\n')
    f.close()
    print('Tamagotchi saved.')
  elif ( i == 'load'):
    f = open('save.txt', mode='r', encoding='utf-8')
    state = str(f.readline()).strip()
    hunger = int(f.readline())
    bored = int(f.readline())
    f.close()
    print('Tamagotchi loaded.')
  else:
    print("Please use a proper input.")
  print('h: ' + str(hunger) + ' b: ' + str(bored))
  if(state == 'HAPPY'):
    if(hunger>=2):
      state='HUNGRY'
    if(bored>=2):
      state='BORED'
  elif(state == 'HUNGRY'):
    if(hunger>=4):
      state='SAD'
    if(bored>hunger):
      state='BORED'
    if(hunger<2):
      state='HAPPY'
  elif(state == 'BORED'):
    if(bored>=4):
      state='SAD'
    if(hunger>bored):
      state='HUNGRY'
    if(hunger<2):
      state='HAPPY'
  else:
    print('error')
print('You made your tamagotchi sad.')
  