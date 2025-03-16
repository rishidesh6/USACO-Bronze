import sys

sys.stdin = open("breedflip.in", "r")
sys.stdout = open("breedflip.out", "w")

inp = sys.stdin.readlines()

n = int(inp[0])

wanted = inp[1]
got = inp[2]


oppList = []


oppositesRow = 0
for i in range(n):

    if got[i] != wanted[i]:

        oppositesRow += 1

    else:

        if oppositesRow > 0:

            oppList.append(oppositesRow)
            
        #print(oppList)
        oppositesRow = 0

sys.stdout.write(str(len(oppList)) + "\n")
