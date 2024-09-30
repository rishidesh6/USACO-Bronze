import sys


sys.stdin = open("square.in", "r")

sys.stdout = open("square.out", "w")


x1, y1, x2, y2 = map(int, input().split())


x3, y3, x4, y4 = map(int, input().split())


leftSide = min(x1, x3)


rightSide = max(x2, x4)


bottom = min(y1, y3)


top = max(y2, y4)


side = max(rightSide - leftSide, top - bottom)


print(side * side)
