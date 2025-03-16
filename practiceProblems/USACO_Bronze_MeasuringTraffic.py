import sys

sys.stdin = open("traffic.in", "r")
sys.stdout = open("traffic.out", "w")

inp = sys.stdin.readlines()

n = int(inp[0])

rangesX = [int(inp[i].split()[1]) for i in range(1, 1 + n)]
rangesY = [int(inp[i].split()[2]) for i in range(1, 1 + n)]

ramps = [inp[i].split()[0] for i in range(1, 1 + n)]


initialRange = []
endRange = []
for i in range(n):

    if ramps[i] == "on" and i == 0:

        if i < n:
            
            initialRange.append(rangesX[i + 1] - rangesX[i])
            initialRange.append(rangesY[i + 1] - rangesX[i])
            
            endRange.append(rangesX[i + 1])
            endRange.append(rangesY[i + 1])
        
    elif ramps[i] == "on" and i != 0:

        endRange[0] += rangesX[i]
        endRange[1] += rangesY[i]

    elif ramps[i] == "off":

        endRange[0] -= (rangesY[i])
        endRange[1] -= (rangesX[i])
        
    elif ramps[i] == "none" and i == 0:

        initialRange.append(rangesX[i])
        initialRange.append(rangesY[i])
            
        endRange.append(rangesX[i])
        endRange.append(rangesY[i])
        
        
    else:

        if rangesX[i] < endRange[0]:

            endRange[0] = rangesX[i]

        if rangesY[i] > endRange[1]:

            endRange[1] = rangesY[i]

sys.stdout.write(str(initialRange[0]) + " " + str(initialRange[1]) + "\n")

sys.stdout.write(str(endRange[0]) + " " + str(endRange[1]) + "\n")
