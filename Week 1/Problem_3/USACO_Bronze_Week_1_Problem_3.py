import sys

sys.stdin = open("billboard.in", "r")
sys.stdout = open("billboard.out", "w")

x1, y1, x2, y2 = map(int, input().split()) 
x3, y3, x4, y4 = map(int, input().split()) 
x5, y5, x6, y6 = map(int, input().split()) 


def overlap(val1, val2, val3, val4):
    
    if val1 == val3:
        return val4 - val1

    
    if val1 < val3:
        if val2 < val3 < val4:
            return 0
        if val3 < val2 < val4:
            return val2 - val3
        if val3 < val4 < val2:
            return val4 - val3

    if val3 < val1:
        if val4 < val1 < val2:
            return 0
        if val1 < val4 < val2:
            return val4 - val1
        if val1 < val2 < val4:
            return val2 - val1

side1 = x2 - x1
side2 = y2 - y1
area1 = side1 * side2

side3 = x4 - x3
side4 = y4 - y3
area2 = side3 * side4

areaVisible = area1 + area2

overlapX = overlap(x1, x2, x5, x6)
overlapY = overlap(y1, y2, y5, y6)

areaBlocked1 = overlapX * overlapY

areaVisible -= areaBlocked1

overlapX2 = overlap(x3, x4, x5, x6)
overlapY2 = overlap(y3, y4, y5, y6)

areaBlocked2 = overlapX2 * overlapY2

areaVisible -= areaBlocked2




print(areaVisible)

