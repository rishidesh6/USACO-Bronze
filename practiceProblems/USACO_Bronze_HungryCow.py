import sys

inp = sys.stdin.readlines()

N, T = map(int, inp[0].split())

dVals = [int(inp[i].split()[0]) for i in range(1, 1 + N)]
bVals = [int(inp[i].split()[1]) for i in range(1, 1 + N)]

total = 0

'''for i in range(0, len(dVals)):
    
    if i == len(dVals) - 1:
        if bVals[i] >= (T - dVals[i]) and (T - dVals[i]) != 0:
            
            total += (T - dVals[i])
            
        elif bVals[i] < (T - dVals[i]):
            total += bVals[i]
            
        else:

            total += 1
        break
            
        
    
    if bVals[i] >= (dVals[i + 1] - dVals[i]):
        
        total += (dVals[i + 1] - dVals[i])
        #if remainder < T:
            
         #   if (bVals[i] - (dVals[i + 1] - dVals[i])) > T - dVals[i]:
          #      remainder = T - dVals[i]
        
    elif bVals[i] < (dVals[i + 1] - dVals[i]):
        
        total += bVals[i]


print(total)'''



#print(dVals)

total = 0
amountAvailable = 0
current = 0

for i in range(1, T + 1):
    #print(current)
    if dVals[current] == i:
        amountAvailable += bVals[current]
        
        if current + 1 < len(dVals):            
            current += 1

        
    if amountAvailable > 0:
        total += 1
        amountAvailable -= 1

print(total)
