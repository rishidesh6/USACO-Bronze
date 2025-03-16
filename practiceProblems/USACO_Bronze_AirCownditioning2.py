import sys

inp = sys.stdin.readlines()

N, M = map(int, inp[0].split())

S = [int(inp[i].split()[0]) for i in range(1, N + 1)]
T = [int(inp[i].split()[1]) for i in range(1, N + 1)]
coolAmounts = [int(inp[i].split()[2]) for i in range(1, N + 1)]

A = [int(inp[i].split()[0]) for i in range(N + 1, M + (N + 1))]

B = [int(inp[i].split()[0]) for i in range(N + 1, M + (N + 1))]
tempRed = [int(inp[i].split()[0]) for i in range(N + 1, M + (N + 1))]
costs = [int(inp[i].split()[0]) for i in range(N + 1, M + (N + 1))]


current = 0
lowest = sum(costs)

cows = {}
cur = 0

for i in range(100):
    if cur < len(S) and i >= S[cur] and i <= T[cur]:
            cows[i] = coolAmounts[cur]
            cur += 1
    else:
        cows[i] = 0


for i in range(0, 2 ** M):
     binary = bin(i)[2:]
     binList = []
     newCows = cows
     
     for j in range(len(binary)):
         binList.append(int(binary[j]))

     for k in range(len(binList)):
         if k == 1:
             for l in range(A[k], B[k]):
                 newCows[l] -= tempRed[k]

     #print(cows)
     satisfied = False
     for m in range(len(newCows)):
         if newCows[m] > 0:
             satisfied = False
             break
         satisfied = True
         
     if satisfied:
         for n in range(len(binList)):
             if n == 1:
                 current += costs[n]
         if current != 0 and current <= lowest:
             lowest = current
         current = 0

print(lowest)
                
             

     
