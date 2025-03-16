import sys

sys.stdin = open("herding.in", "r")
sys.stdout = open("herding.out", "w")

inp = sys.stdin.readlines()

x, y, z = map(int, inp[0].split())



minimum1 = 0
maximum1 = 9

if abs(y - x) == 2:
    
    minimum1 = 1
    maximum1 = abs(y - x) - 1

elif abs(y - x) > 2:
    
    minimum1 = 2
    maximum1 = abs(y - x) - 1
    

minimum2 = 0
maximum2 = 0

if abs(y - z) == 2:
    
    minimum2 = 1
    maximum2 = abs(y - z) - 1
    
    
elif abs(y - z) > 2:
    
    minimum2 = 2
    maximum2 = abs(y - z) - 1
    


if minimum1 < minimum2 or minimum1 == minimum2:

    sys.stdout.write(str(minimum1) + "\n")

else:

    sys.stdout.write(str(minimum2) + "\n")

if maximum1 > maximum2 or maximum1 == maximum2:

    sys.stdout.write(str(maximum1) + "\n")

else:

    sys.stdout.write(str(maximum2) + "\n")

