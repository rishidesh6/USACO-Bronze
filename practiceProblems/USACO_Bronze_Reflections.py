import sys

inp = sys.stdin.readlines()

N, U = map(int, inp[0].split())

xVals = [int(inp[i].split()[0]) for i in range(1 + N, (1 + N) + U)]
yVals = [int(inp[i].split()[1]) for i in range(1 + N, (1 + N) + U)]

xVals.reverse()
yVals.reverse()

vals = []
counter = []
count = 0


for i in range(len(xVals)):


    if i == 0:

        vals.append(str(xVals[i]) + str(yVals[i]))

        count += 1

        counter.append(count)

    else:

        current = str(xVals[i]) + str(yVals[i])

        if current not in vals:

            vals.append(current)

            count += 1

            counter.append(count)

            
            
        else:
            
            count -= 1

            counter.append(count)
            
counter.append(counter[-1] + 1)

counter.reverse()

for i in counter:

    print(i)


