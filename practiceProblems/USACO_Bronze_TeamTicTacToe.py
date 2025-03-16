import sys

sys.stdin = open("tttt.in", "r")
sys.stdout = open("tttt.out", "w")

inp = sys.stdin.readlines()

lines = [list(inp[i]) for i in range(0, 3)]
print(lines[0][0])

letters = []


duo = 0
individual = 0

for i in range(3):
    lettersUsed = []
    amount = 0
    
    if lines[0][i] not in lettersUsed:
        lettersUsed.append(lines[0][i])
        amount += 1

    if amount == 3:
        break
    elif amount == 2:
        duo += 1
    else:
        individual += 1
#++++++++++++++++++++++++
    
for i in range(3):
    
    lettersUsed = []
    amount = 0
    
    if lines[1][i] not in lettersUsed:
        lettersUsed.append(lines[1][i])
        amount += 1

    if amount == 3:
        break
    elif amount == 2:
        duo += 1
    else:
        individual += 1
        
#+++++++++++++++++++++++
        
for i in range(3):
    lettersUsed = []
    amount = 0
    
    if lines[2][i] not in lettersUsed:
        lettersUsed.append(lines[2][i])
        amount += 1

    if amount == 3:
        break
    elif amount == 2:
        duo += 1
    else:
        individual += 1

#+++++++++++++++++++++++
        
for i in range(3):

    lettersUsed = []
    amount = 0

    if lines[i][0] not in lettersUsed:
        lettersUsed.append(lines[i][0])
        amount += 1

    if amount == 3:
        break
    elif amount == 2:
        duo += 1
    else:
        individual += 1

#++++++++++++++++++++++++

for i in range(3):

    lettersUsed = []
    amount = 0

    if lines[i][1] not in lettersUsed:
        lettersUsed.append(lines[i][1])
        amount += 1

    if amount == 3:
        break
    elif amount == 2:
        duo += 1
    else:
        individual += 1

#++++++++++++++++++++++++

for i in range(3):

    lettersUsed = []
    amount = 0

    if lines[i][2] not in lettersUsed:
        lettersUsed.append(lines[i][2])
        amount += 1

    if amount == 3:
        break
    elif amount == 2:
        duo += 1
    else:
        individual += 1

#+++++++++++++++++++++++++

lettersUsed = []
amount = 0

if lines[0][0] not in lettersUsed:
    lettersUsed.append(lines[0][0])
    amount += 1
    
if lines[1][1] not in lettersUsed:
    lettersUsed.append(lines[1][1])
    amount += 1

if lines[2][2] not in lettersUsed:
    lettersUsed.append(lines[2][2])
    amount += 1

if amount == 2:
    duo += 1
elif amount == 1:
    individual += 1

#+++++++++++++++++++++++++++

lettersUsed = []
amount = 0

if lines[0][2] not in lettersUsed:
    lettersUsed.append(lines[0][2])
    amount += 1
    
if lines[1][1] not in lettersUsed:
    lettersUsed.append(lines[1][1])
    amount += 1

if lines[2][0] not in lettersUsed:
    lettersUsed.append(lines[2][0])
    amount += 1

if amount == 2:
    duo += 1
elif amount == 1:
    individual += 1

#+++++++++++++++++++++++++++

sys.stdout.write(str(individual))
sys.stdout.write(str(duo) + "/n")
sys.stdout.close()
