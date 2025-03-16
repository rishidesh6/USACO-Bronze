import sys

sys.stdin = open('billboard.in', 'r')
sys.stdout = open('billboard.out', 'w')

x1, y1, x2, y2 = map(int, input().split()) 
x3, y3, x4, y4 = map(int, input().split())


sideX = x2 - x1
sideY = y2 - y1

areaBad = sideX * sideY

def overlap(val1, val2, val3, val4):
    
    if val1 == val3:
        if val4 >= val2:
            return abs(val4 - val1)
        else:
            return abs(val2 - val1)
    
    if val1 < val3:
        if val2 < val3 < val4:
            return 0
        if val3 < val2 < val4:
            return abs(val2 - val3)
        if val3 < val4 < val2:
            return abs(val4 - val3)

    if val3 < val1:
        if val4 < val1 < val2:
            return 0
        if val1 < val4 < val2:
            return abs(val4 - val1)
        if val1 < val2 < val4:
            return abs(val2 - val1)


areaToCover = 0
overlapX = overlap(x1, x2, x3, x4)
overlapY = overlap(y1, y2, y3, y4)

if x3 <= x1 and x4 >= x2 and y3 <= y1 and y4 >= y2:
    print(areaToCover)

elif x3 <= x1 and x4 >= x2 and y3 <= y1 and y4 < y2:

    areaToCover = areaBad - (overlapX * overlapY)
    print(areaToCover)

elif x3 <= x1 and x4 >= x2 and y3 > y1 and y4 >= y2:

    areaToCover = areaBad - (overlapX * overlapY)
    print(areaToCover)

elif x3 <= x1 and x4 < x3 and y3 <= y1 and y4 >= y2:
    
    areaToCover = areaBad - (overlapX * overlapY)
    print(areaToCover)
    
elif x3 > x1 and x4 >= x2 and y3 <= y1 and y4 >= y2:

    areaToCover = areaBad - (overlapX * overlapY)
    print(areaToCover)

else:
    
    areaToCover = areaBad
    print(areaToCover)
