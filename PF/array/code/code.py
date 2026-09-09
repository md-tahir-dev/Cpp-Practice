import numpy as np

A = np.array([[1, 2, 3],
              [0, 1, 4],
              [2, 3, 0]])

B = np.array([[2, 0, 1],
              [3, 4, 0],
              [1, 2, 3]])

C = np.dot(A, B)
print("A x B:")
print(C)
