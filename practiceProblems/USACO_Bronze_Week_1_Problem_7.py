import sys

sys.stdin = open("cowsignal.in", "r")
sys.stdout = open("cowsignal.out", "w")


lines = sys.stdin.readlines()


for line in lines:
    line = line.strip()
    
N, M, K = map(int, lines[0].split())

expandedSignal = []


            
def expand(signalLine, kVal):
    splitLine = list(signalLine)
    expandedLine = ""
    
    for i in range(0, len(splitLine)):
        splitLine[i] = splitLine[i] * kVal
                
    
    for j in range(0, len(splitLine)):
        expandedLine += splitLine[j]
    
    for k in range(kVal):
        expandedSignal.append(expandedLine)
     

for i in range(1, len(lines)):
    expand(lines[i].strip(), K)



for j in range(0, len(expandedSignal)):   
    sys.stdout.write(expandedSignal[j] + "\n")
sys.stdout.close()


