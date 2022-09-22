from cProfile import label
from matplotlib import pyplot as plt
import numpy as np

numberOfWords = np.array([100,500,1000])
miliseconds = np.array([[0,0,0],[0,1,1],[0,1,1],[0,0,1]])

norm1 = np.linalg.norm(numberOfWords)
normalizedNumberOfWords = numberOfWords/norm1

normalizedMliseconds = []
norm2 = np.linalg.norm(miliseconds.flatten())

for arr in miliseconds:
    normalizedMliseconds.append( arr / norm2)

colors = ["green","blue","red","purple"]
for i in range(4):
    x = i + 2
    str = "word length %s" %(x)
    plt.plot(normalizedNumberOfWords,normalizedMliseconds[i],color=colors[i], label = str)
plt.title("Time / Number of words dependence")
plt.xlabel("Number of words")
plt.ylabel("ms")
plt.legend()

plt.show()
