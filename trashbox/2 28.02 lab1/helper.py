import subprocess
import matplotlib.pyplot as plt 
import numpy as np

standart, binary = [], []
min, max, step = 100, 1000, 10
for i in range(min, max, step):
    subprocess.run(["g++", "35.cpp", "-DARRAYSIZE="+str(i), "-o 35test.exe"], shell=True) 
    output = subprocess.Popen("35test.exe", shell=True, stdout=subprocess.PIPE).stdout.read()
    output = output.decode('ascii').replace('\r\n','').split('@')
    standart.append(int(output[0]))
    binary.append(int(output[1]))
    print(i, output)

plt.plot(np.arange(min,max,step), np.array(binary))
plt.savefig('output.png')
plt.show()