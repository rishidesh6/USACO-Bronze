
#PROBLEM: https://usaco.org/index.php?page=viewproblem2&cpid=663

#MY SOLUTION:


import sys


#opening the required files 
sys.stdin = open("square.in", "r")
#read input on first file
sys.stdout = open("square.out", "w")
#second file opened in write mode to enter results


#splitting the input coordinates into the 2 different rectangles
x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())



#finding the corner sides by using the min and max functions(square surrounds both rectangles)
leftSide = min(x1, x3)


rightSide = max(x2, x4)

#finding the top height and bottom height of the two rectangles via min and max
bottom = min(y1, y3)


top = max(y2, y4)


#using max to find the largest side length out of the two, as the pasture surrounding the two rectangles is a square, meaning it's values should be the same
side = max(rightSide - leftSide, top - bottom)


print(side * side)
