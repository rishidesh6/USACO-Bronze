import sys

sys.stdin = open("taming.in", "r")
sys.stdout = open("taming.out", "w")

inp = sys.stdin.readlines()

n = int(inp[0])
log = [int(inp[1].split()[i]) for i in range(n)]


newLog = []

for i in range(n):

    if i == 0:
        
        newLog.append(0)
    else:
        
        newLog.append(log[i])

tentativeLog = []

for i in range(len(newLog)):

    if newLog[i] == -1:
        
        tentativeLog.append(newLog[i - 1] + 1)
        
    else:
        
        tentativeLog.append(newLog[i])



minimum = 0
for i in tentativeLog:

    if i == 0:
        
        minimum += 1

pos = 0
mid = 0

for i in range(0, len(newLog)):
    
    if i < len(newLog) and newLog[i] == -1 and tentativeLog[i + 1] == 0:
        
        mid += 1
        
    if newLog[i] > -1:
        
        pos = i
        

maximum = minimum + ((len(newLog) - 1) - pos) + mid


for i in range(0, len(tentativeLog)):

    if i == n - 1:
        
        sys.stdout.write(str(minimum) + " " + str(maximum) + "\n")
        break

    if tentativeLog[i + 1] != 0 and (tentativeLog[i + 1] == tentativeLog[i] + 1):

        continue
    
    elif tentativeLog[i + 1] == 0:

        continue

    else:

        sys.stdout.write(str(-1) + "\n")
        break



        
