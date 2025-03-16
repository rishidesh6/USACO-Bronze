import sys

inp = sys.stdin.readlines()

T = int(inp[0])

nVals = [int(inp[i]) for i in range(1, 1 + T*2) if i % 2 == 1]

cases = [inp[i].split() for i in range(1, 1 + T*2) if i % 2 == 0]

for i in range(T):

    delta = []
    amount = 0
    
    for j in range(nVals[i]):


        
        if j < nVals[i]:

            delta.append(int(cases[i][j + 1]) - int(cases[i][j]))



    for k in range(len(delta)):

        
        if k < len(delta):

            if delta[k + 1] == delta[k]:

                continue

            else:

                amount += 1
    print(amount)

            
