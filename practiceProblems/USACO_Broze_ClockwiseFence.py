import sys

inp = sys.stdin.readlines()

N = int(inp[0])


paths = [inp[i].strip() for i in range(1, N + 1)]

for i in range(N):
    current = paths[i]
    
    if current[-2] + current[-1] == "SW":
        print("CW")
    elif current[-2] + current[-1] == "SE":
        print("CCW")
    elif current[-2] + current[-1] == "WS":
        print("CCW")
    elif current[-2] + current[-1] == "ES":
        print("CW")

    elif current[-2] + current[-1] == "NW":
        print("CCW")
    elif current[-2] + current[-1] == "NE":
        print("CW")
    elif current[-2] + current[-1] == "WN":
        print("CW")
    elif current[-2] + current[-1] == "EN":
        print("CCW")



'''import sys

inp = sys.stdin.readlines()

N = int(inp[0])

paths = [inp[i] for i in range(1, N + 1)]

for i in range(N):
    current = paths[i]

    if paths[-2] + paths[-1] == "SW":
        print("CW")
    elif paths[-2] + paths[-1] == "SE":
        print("CCW")
    elif paths[-2] + paths[-1] == "WS":
        print("CCW")
    elif paths[-2] + paths[-1] == "ES":
        print("CW")

    elif paths[-2] + paths[-1] == "NW":
        print("CCW")
    elif paths[-2] + paths[-1] == "NE":
        print("CW")
    elif paths[-2] + paths[-1] == "WN":
        print("CW")
    elif paths[-2] + paths[-1] == "EN":
        print("CCW")
'''
