import sys

sys.stdin = open("paint.in", "r")
sys.stdout = open("paint.out", "w")

a, b = map(int(), input().split())
c, d = map(int(), input().split())



if a < b < c < d or c < d < a < b:
    print((b - a) + (d - c))
    
elif a < c < b < d or c < a < d < b:
    
    if a < c < b < d:
        print(d - a)
        
    else:
        print(b - c)
else:
    
    if a < c < d < b:
        print(b - a)
        
    elif c < a < b < d:
        print(d - c) 
