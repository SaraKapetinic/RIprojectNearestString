from cProfile import label
from matplotlib import pyplot as plt
import numpy as np

numberOfWords = np.array([100,500,1000])
miliseconds = np.array([[949,1414,2113],[993,1483,2105],[1185,1460,2096],[1129,1471,2805]])

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
    plt.title('Length of words %d' %(i+2))
    plt.xlabel("Number of words")
    plt.ylabel("ms")
plt.legend()

plt.show()

plt.plot(normalizedNumberOfWords,normalizedMliseconds[0],color = "green")
plt.xlabel("Number of words")
plt.ylabel("ms")
plt.title("Word length 2")
plt.show()

plt.plot(normalizedNumberOfWords,normalizedMliseconds[1],color = "blue")
plt.xlabel("Number of words")
plt.ylabel("ms")
plt.title("Word length 3")
plt.show()

plt.plot(normalizedNumberOfWords,normalizedMliseconds[2],color = "red")
plt.xlabel("Number of words")
plt.ylabel("ms")
plt.title("Word length 4")
plt.show()

plt.plot(normalizedNumberOfWords,normalizedMliseconds[3],color = "purple")
plt.xlabel("Number of words")
plt.ylabel("ms")
plt.title("Word length 5")
plt.show() 
