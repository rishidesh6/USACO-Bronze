import sys

inp = sys.stdin.readlines()

N = int(inp[0])

txt = inp[1].split()

duplicates = 0
totalInts = []

moos = []


for i in range(N):

    
    current = int(txt[i])

    if current not in totalInts:
        
        totalInts.append(current)

    if i < N - 1 and current == int(txt[i + 1]):
        #print(totalInts)
        for j in range(len(totalInts)):


            if totalInts[j] != current and str(totalInts[j]) + str(current) + str(current) not in moos:

                moos.append(str(totalInts[j]) + str(current) + str(current))
                #print(moos)

print(len(moos))



'''import sys

inp = sys.stdin.readlines()

N = int(inp[0])

txt = inp[1].split()



duplicates = 0
totalInts = []
count = 0

for i in range(N - 1):
    
    current = int(txt[i])

    if i > 0 and current != int(txt[i - 1]):
        
        totalInts.append(current)

        if i < N - 1 and current == int(txt[i + 1]):

            duplicates += 1

            count += len(totalInts)

print(count)'''
