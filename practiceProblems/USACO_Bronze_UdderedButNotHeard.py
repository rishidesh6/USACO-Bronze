import sys

inp = sys.stdin.readlines()

cowphabet = inp[0].strip()

heardStr = inp[1].strip()

indexes = []

for i in range(len(heardStr)):

    for j in range(len(cowphabet)):

        if heardStr[i] == cowphabet[j]:

            indexes.append(j)


row = 0
amount = 0

for i in range(len(indexes)):

    if i == len(indexes) - 1:
        amount += 1
        break
        
        
    #print(indexes[i], indexes[i + 1])
    if indexes[i] < indexes[i + 1]:

        row += 1

    else:

        row = 0
        amount += 1

print(str(amount))
