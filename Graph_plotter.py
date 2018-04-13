 
with open('n2.txt','r') as f:
    content = f.readlines()
# you may also want to remove whitespace characters like `\n` at the end of each line
content = [x.strip() for x in content]

contentint = [float(x) for x in content] 

with open('nlogn.txt','r') as f:
    content2 = f.readlines()
# you may also want to remove whitespace characters like `\n` at the end of each line
content2 = [x.strip() for x in content2]

contentint2 = [float(x) for x in content2] 

import numpy as np
import matplotlib.pyplot as plt

num = (5000-1000)//100
print(num)
a = [0]*num
ii = 0
for i in range(1000,5000,100):
	a[ii] = i
	ii = ii + 1

plt.ylabel("Time Taken")
plt.xlabel("Number of inputs")
# plt.title("Comparison")
plt.plot(a,contentint,'-b',label='Without NTT')
plt.plot(a,contentint2,'-r',label='With NTT')
plt.legend(loc='upper left')
plt.show()