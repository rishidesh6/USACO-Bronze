import sys

sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w")

inp = sys.stdin.readlines()

N = int(inp[0])

aVals = [int(inp[i].split()[0]) for i in range(1, 1 + N)]
bVals = [int(inp[i].split()[1]) for i in range(1, 1 + N)]
gVals = [int(inp[i].split()[2]) for i in range(1, 1 + N)]




highestScore = 0
for i in range(3):
    emptyOrNot = {1: "", 2: "", 3: ""}
    emptyOrNot[i] = "X"
    currentScore = 0
    for j in range(N):
        if emptyOrNot[aVals[j]] == "X":
            emptyOrNot[aVals[j]] = ""
            emptyOrNot[bVals[j]] = "X"
            
        elif emptyOrNot[bVals[j]] == "X":
            emptyOrNot[bVals[j]] = ""
            emptyOrNot[aVals[j]] = "X"

        if emptyOrNot[gVals[j]] == "X":
            currentScore += 1
    if currentScore >= highestScore:
        highestScore = currentScore
    

sys.stdout.write(str(highestScore))
sys.stdout.close()
