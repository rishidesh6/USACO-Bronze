import sys

sys.stdin = open("revegetate.in", "r")
sys.stdout = open("revegetate.out", "w")

inp = sys.stdin.readlines()

n, m = map(int, inp[0].split())

pasturesLeft = [int(inp[i].split()[0]) for i in range(1, 1 + m)]
pasturesRight = [int(inp[i].split()[1]) for i in range(1, 1 + m)]


#print(pasturesLeft)
#print(pasturesRight)
digits = []


for i in range(1, n + 1):

    if i == 1:

        digits.append(1)

    else:

        valsLower = []
        for j in range(0, m):

            
            if pasturesLeft[j] == i and pasturesRight[j] < i:
                
                valsLower.append(pasturesRight[j])
                
            if pasturesRight[j] == i and pasturesLeft[j] < i:
                
                valsLower.append(pasturesLeft[j])
        #print(valsLower)

                
        if len(valsLower) > 0:

            newDigits = []
            
            for k in range(len(valsLower)):

                newDigits.append(digits[valsLower[k] - 1])
                

            newDigits.sort()
            
            digits.append(newDigits[-1] + 1)

        else:

            digits.append(1)


for i in digits:

    sys.stdout.write(str(i))

sys.stdout.write("\n")
