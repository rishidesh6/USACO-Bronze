import sys

inpFile = open("gymnastics.in", "r")
outFile = open("gymnastics.out", "W")

inp = inpFile.readlines()

K, N = map(int, inp[0].split())

rankings = [int(inp[i].split()) for i in range(1, K + 1)]

lowestPlace = 1
count = 0

for i in range(1, N + 1):
    cowToCheck = i
    
    for j in range(K):
        ranking = rankings[k]
        
        for k in range(len(ranking)):
            if ranking[k] == cowToCheck:
                
                place = k + 1

                if place >= lowestPlace:
                    lowestPlace = place
                    rankingOfLowest = k
                    
    if lowestPlace == 1:
        count += N - 1

    elif lowestPlace == 6:
        lowestPlace = 1
    else:

        for l in range(rankingOfLowest, N):

            for m in range(K):

                
