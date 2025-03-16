import sys

inp = sys.stdin.readlines()

n = int(inp[0])

cowHeights = [int(inp[1].split()[i]) for i in range(n)]

heightLimits = [int(inp[2].split()[i]) for i in range(n)]



needed = []


for i in cowHeights:

    amount = 0
    
    for j in heightLimits:

        if i <= j:

            amount += 1

    needed.append(amount)




