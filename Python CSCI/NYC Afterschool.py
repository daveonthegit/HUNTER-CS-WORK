#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 11/16/22
#This program takes a name list input, and separates it and prints it back in Initial. Lastname order. G. Washington

import folium
import pandas as pd

school = pd.read_csv('after_school.csv')
mapAS = folium.Map(location=[40.75, -74.125])
c = input("Enter 1 for Borough/Community,\n2 for Grade Level / Age Group\nYour choice: ")

if (c == '1' ):
    g = school.groupby('Borough/Community')
    print(g.groups.keys())
    x = input('Enter Borough/Community name: ')
    borough = g.get_group(x)

    for index,row in borough.iterrows():
        lat = row['Latitude']
        lon = row['Longitude'] 
        name = row['Name']
        nMarker = folium.Marker([lat,lon], popup= name)
        nMarker.add_to(mapAS)
        mapAS.save(outfile=(x.lower().replace('/','_').replace(' ','_')+'_after_school.html'))
elif(c=='2'):
    g = school.groupby('Grade Level / Age Group')
    print(g.groups.keys())
    x = input('Enter Grade Level / Age Group name: ')
    level = g.get_group(x)

    for index,row in level.iterrows():
        lat = row['Latitude']
        lon = row['Longitude'] 
        name = row['Name']
        nMarker = folium.Marker([lat,lon], popup= name)
        nMarker.add_to(mapAS)
        mapAS.save(outfile=(x.lower().replace('/','_').replace(' ','_')+'_after_school.html'))
