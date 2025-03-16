import sys

inp = sys.stdin.readlines()

T = int(inp[0])

nVals = [int(inp[i].split()[0]) for i in range(1, 1 + T * 2) if i % 2 == 1]
kVals = [int(inp[i].split()[1]) for i in range(1, 1 + T * 2) if i % 2 == 1]

sequences = [inp[i].split() for i in range(1, 1 + T * 2) if i % 2 == 0]

def divisors(n, k, sequence):

    val1 = int(n/k)
    val2 = int(n/k * 2)
    val3 = int(n/k * 3)

    if k == 2:

        if sequence[0: val1] == sequence[val1: val2]:

            return True
        else:

            return False

    elif k == 3:


        if sequence[0: val1] == sequence[val1: val2] == sequence[val2: val3]:

            return True

        else:

            return False
        

'''def duplicates(n, k, sequence):

    occurred = []
    amount = n
    
    for i in range(n):

        if i == 0:

            occurred.append(sequence[i])

        else:

            if sequence[i] not in occurred:

                occurred.append(sequence[i])

            else:

                count = sequence.count(sequence[i])

                amount -= count - 1

    if amount <= k:

        return True
    else:
        return False'''

def duplicates(n, k, sequence):

    occurred = []
    amount = n

    current = sequence[0]
    
    for i in range(len(sequence)):

        if i == 0:

            continue

        if sequence[i] == current:

            amount -= 1

        else:

            current = sequence[i]
                

    if amount <= k:

        return True
    
    else:
        return False


for i in range(T):

    N = nVals[i]
    
    K = kVals[i]
    
    sequence = sequences[i]

    if K == 1:

        if duplicates(N, K, sequence):

            print("YES")

        else:

            print("NO")
            
    if K == 2:

        if divisors(N, K, sequence) == True or duplicates(N, K, sequence) == True:

            print("YES")
            
        else:
            
            print("NO")

    if K == 3:

        if divisors(N, K, sequence) == True or duplicates(N, K, sequence) == True:

            print("YES")

        else:

            print("NO")

            






















    
