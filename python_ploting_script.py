import numpy as np
import matplotlib.pyplot as plt

file = open("results.dat", 'r')

# This is one way to print (append this to a vector)

if False:
    for line in file:
        print line

file = open("results.dat", 'r')

A = file.read()
A = A.split('\n')

V = np.zeros(len(A) - 1)

for index, a in enumerate(A):
    if a != '':
        V[index] = float(a)


plt.plot(V)
plt.show()
