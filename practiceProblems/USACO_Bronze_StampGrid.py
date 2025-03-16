import sys

inp = sys.stdin.readlines()

T = int(inp[0])

NVals = [int(inp[i]) for i in range(1, len(inp)) if inp[i - 1] == "\n"]


currentLine = 3
for i in range(T):
    painting = []
    stamp = []
    
    for j in range(currentLine, currentLine + NVals[i]):
        painting.append(inp[j])
        
    currentLine += NVals[i]

    for k in range(currentLine, currentLine + KVals[i]):
        stamp.append(inp[k])

    
    
    
        
        
    
