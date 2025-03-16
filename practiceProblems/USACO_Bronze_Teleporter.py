import sys

sys.stdin = open("teleport.in", "r")
sys.stdout = open("teleport.out", "w")

inp = sys.stdin.readlines()

a, b, x, y = map(int, inp[0].split())

total = b - a

t1 = abs(x - a) + abs(y - b)
t2 = abs(y - a) + abs(x - b)

ls = []
ls.append(t1)
ls.append(t2)
ls.append(total)

ls.sort()

sys.stdout.write(str(ls[0]) + "\n")
