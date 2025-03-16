"""
ID: rishide4
LANG:PYTHON3
TASK: ride

"""

fin = open ('ride.txt', 'r')

lines = fin.readlines()
print(lines)

'''

group = lines[0]
groupList = group.split()

comet = lines[1].split()
cometList = comet.split()

groupTotal = 1

for letter in group:
    val = ord(letter) - ord('A') + 1
    groupTotal = groupTotal * val

cometTotal = 1

for letter in comet:
    val2 = ord(letter) - ord('A') + 1
    cometTotal = cometTotal * val2

if groupTotal % 47 == cometTotal % 47:
    print("GO")
else:
    print("STAY")'''
