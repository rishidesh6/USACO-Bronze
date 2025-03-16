"""
ID: rishide4
LANG:PYTHON3
PROG: ride

"""

fin = open ('ride.in', 'r')
fout = open ('ride.out', 'w')

lines = fin.readlines()

group = lines[0].strip("\n")

groupTotal = 1

for i in range(0, len(group)):
    val = ord(group[i]) - ord('A') + 1
    groupTotal = groupTotal * val

comet = lines[1].strip("\n")

cometTotal = 1

for i in range(0, len(comet)):
    val2 = ord(comet[i]) - ord('A') + 1
    cometTotal = cometTotal * val2

if groupTotal % 47 == cometTotal % 47:
    fout.write("GO\n")
else:
    fout.write("STAY\n")

fout.close()
