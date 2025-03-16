"""
ID: rishide4
LANG:PYTHON3
PROG: gift1

"""

fin = open('gift1.in', 'r')
fout = open('gift1.out', 'w')

totalInp = fin.readlines()

for i in range(0, len(totalInp)):
    totalInp[i] = totalInp[i].strip("\n")

NP = int(totalInp[0]) + 1
names = []

for j in range(1, 1 + NP):
    names.append(totalInp[j].strip("\n"))

money = {}

for i in range(0, len(names)):
    money[names[i]] = 0

for k in range(NP, len(totalInp)):

    if NP >= len(totalInp):
        break
    
    money_split = totalInp[NP + 1].split()

    if money_split[0] == '0' or money_split[1] == '0':
        NP = NP + 2 + int(money_split[1])
        continue
    
    valToAdd = int(money_split[0])//int(money_split[1])
    leftover = int(money_split[0]) % int(money_split[1])
    
    money[totalInp[NP]] -= int(money_split[0])
    money[totalInp[NP]] += leftover
    
    for j in range(0, int(money_split[1])):
        money[totalInp[NP + 2 + j]] += valToAdd
        
    NP = NP + 2 + int(money_split[1])

for person in money:
    fout.write(person + " " + str(money[person]) + "\n")

fout.close()




