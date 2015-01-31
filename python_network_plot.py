import numpy as np
import matplotlib.pyplot as plt

file = open("network_results.dat", 'r')

# This is one way to print (append this to a vector)

file_data = file.read()
T = file_data.count('\n\n')
split_data = file_data.split('\n\n')
N = len(split_data[0].split('\n'))

data = np.zeros((T, N, N))

for t, matrix in enumerate(split_data[:-1]):
    rows = matrix.split('\n')
    for x, row in enumerate(rows):
        elements = row.split(',')
        data[t, x, :] = np.array(elements[:-1])


average_rate = np.average(data, axis=0)

plt.imshow(average_rate)
plt.show()
