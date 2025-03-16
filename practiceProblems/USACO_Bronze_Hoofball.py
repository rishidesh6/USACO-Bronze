import sys

sys.stdin = open("hoofball.in", "r")
sys.stdout = open("hoofball.out", "w")

inp = sys.stdin.readlines()

n = int(inp[0])

cowsList = [int(inp[1].split()[i]) for i in range(n)]
cowsList.sort()


cowsDict = {}
for i in cowsList:
    cowsDict[i] = ''


for i in range(n):

    if i != 0 and i != n - 1:

        if (cows[i + 1] - cows[i]) 


