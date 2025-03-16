import sys

sys.stdin = open("swap.in", "r")
sys.stdout = open("swap.out", "w")


inp = sys.stdin.readlines()

n, k = map(int, inp[0].split())

a1, a2 = map(int, inp[1].split())

b1, b2 = map(int, inp[2].split())


ls = []
for i in range(1, 1 + n):

    ls.append(i)



for i in range(k):

    

    listToReverse = ls[a1 - 1:a2]
    listToReverse.reverse()
    ls[a1 - 1: a2] = listToReverse


    listToReverse2 = ls[b1 - 1:b2]
    listToReverse2.reverse()
    ls[b1 - 1: b2] = listToReverse2



for i in range(n):

    sys.stdout.write(str(ls[i]) + "\n")

