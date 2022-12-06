#Name: David Xiao
#Email: david.xiao67@myhunter.cuny.edu 
#Date: 11/10/22
#This program makes a  map of NYC and central park using coordinates.

import folium

mapCUNY = folium.Map(location=[40.75, -74.125], zoom_start=10)
folium.Marker(location = [40.7812, -73.9665], popup = "Central Park").add_to(mapCUNY)
mapCUNY.save(outfile='nyc_Central_Park.html')