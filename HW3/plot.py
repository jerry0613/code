import matplotlib.pyplot as plt
import numpy as np
import serial


serdev = '/dev/ttyACM0'

s = serial.Serial(serdev, baudrate=115200)
X = []
Y = []
Z = []
tilt = []
t = np.arange(0,10, 0.1)   

for i in range(100):
    line=s.readline() # Read an echo string from K66F terminated with '\n'
    v = float(line)
    X.append(v)
    line=s.readline() # Read an echo string from K66F terminated with '\n'
    v = float(line)
    Y.append(v)
    line=s.readline() # Read an echo string from K66F terminated with '\n'
    v = float(line)
    Z.append(v)
    line=s.readline() # Read an echo string from K66F terminated with '\n'
    v = float(line)
    tilt.append(v)


plt.subplot(211)
plt.ylabel("Acc Vector")
plt.xlabel("Time")
plt.plot(t,X, label="x")
plt.plot(t,Y, label="y")
plt.plot(t,Z, label="z")
plt.subplot(212)
plt.ylabel("Tilt")
plt.xlabel("Time")
plt.stem(t, tilt)

plt.show()

s.close()