import polyline
import base64
import matplotlib.pyplot as plt

longitude, latitude = [], []

with open('locations.txt') as f:
    for line in f:
        # print(line)
        l = base64.b64decode(line).decode('utf-8')
        l = polyline.decode(l)
        longitude.append(l[0][0])
        latitude.append(l[0][1])


plt.scatter(x=longitude, y=latitude)
plt.show()
