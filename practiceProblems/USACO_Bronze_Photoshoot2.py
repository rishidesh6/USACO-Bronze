import sys

inp = sys.stdin.readlines()

n = int(inp[0])

current = [int(inp[1].split()[i]) for i in range(n)]
required = [int(inp[2].split()[i]) for i in range(n)]



needed = []
for i in range(n):

    index = [j for j, x in enumerate(required) if x == current[i]]

    needed.append(index[0] - i)



if max(needed) == 0:

    print(abs(min(needed)))

else:

    print(max(needed))
