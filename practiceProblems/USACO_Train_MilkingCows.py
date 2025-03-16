"""
ID: rishide4
TASK: milk2
LANG: PYTHON3

"""

import sys

inpFile = open("milk2.in", "r")
outFile = open("milk2.out", "w")

inp = inpFile.readlines()

N = int(inp[0])

startTimes = [int(inp[i].split()[0]) for i in range(1, N + 1)]
endTimes = [int(inp[i].split()[1]) for i in range(1, N + 1)]


booleanMilking = [False] * 1000002


noMilking = 0
milking = 0

highestNoMilking = 0
highestMilking = 0


for i in range(0, len(startTimes)):
    
    for j in range(startTimes[i], endTimes[i]):
        
        booleanMilking[j] = True 


for k in range(min(startTimes), max(endTimes) + 1):
    
    if booleanMilking[k]:
        
        milking += 1
        
        if noMilking >= highestNoMilking:
            
            highestNoMilking = noMilking
            
        noMilking = 0

    else:
        
        noMilking += 1

        if milking >= highestMilking:

            highestMilking = milking
            
        milking = 0
outFile.write(str(highestMilking) + " " + str(highestNoMilking) + "\n")
outFile.close()
