import sys

sys.stdin = open("triangles.in", "r")
sys.stdout = open("triangles.out", "w")

inp = sys.stdin.readlines()

n = int(inp[0])

xVals = [int(inp[i].split()[0]) for i in range(1, n + 1)]
yVals = [int(inp[i].split()[1]) for i in range(1, n + 1)]



area = 0


for i in range(n):

    distanceX = 0
    distanceY = 0
    
    baseX = xVals[i]
    baseY = yVals[i]



    for j in range(n):

        if abs(xVals[j] - baseX) > 0 and yVals[j] == baseY:

            if abs(xVals[j] - baseX) > distanceX:

                distanceX = abs(xVals[j] - baseX)
                
    for k in range(n):
         
        if abs(yVals[k] - baseY) > 0 and xVals[k] == baseX:

            if abs(yVals[k] - baseY) > distanceY:

                distanceY = abs(yVals[k] - baseY)

    if distanceX > 0 and distanceY > 0:

        triArea = distanceX * distanceY
        
        if triArea > area:

            area = triArea

sys.stdout.write(str(area) + "\n")
