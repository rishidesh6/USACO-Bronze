"""
ID: rishide4
TASK: transform
LANG: PYTHON3

"""

import sys

inpFile = open("transform.in", "r")
outFile = open("transform.out", "w")

inp = inpFile.readlines()
N = int(inp[0])

current = [inp[i].strip() for i in range(1, N + 1)]
needed = [inp[i].strip() for i in range(N + 1, N + (N + 1))]

def reverse(string):
  
  newString = ''
  
  for i in range(len(string) - 1, -1, -1):
    newString += string[i]
    
  return newString


def reflection(grid):
  newGrid = [''] * N
  
  for i in range(N):
    newGrid[i] = reverse(grid[i])
  
  return newGrid
    
def rotation(grid):
  newGrid = [''] * N
  
  for i in range(N):
    for j in range(N):
      newGrid[i] += grid[N - 1 - j][i]
  return newGrid

def answer(grid):
  new_grid = rotation(grid)
  if new_grid == needed:
    return 1
  
  new_grid = rotation(new_grid)
    
  if new_grid == needed:
    return 2
    
  new_grid = rotation(new_grid)
  
  if new_grid == needed:
    return 3
    
  if reflection(grid) == needed:
    return 4
  
  reflected = reflection(grid)
  reflected90 = rotation(reflected)
  reflected180 = rotation(reflected90)
  reflected270 = rotation(reflected180)
  
  if reflected90 == needed or reflected180 == needed or reflected270 == needed:
    return 5
    
  if current == needed:
    return 6
  
  return 7


outFile.write(str(answer(current)) + "\n")
