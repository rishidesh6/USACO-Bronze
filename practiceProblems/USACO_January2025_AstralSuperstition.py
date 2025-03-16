import sys

inp = sys.stdin.readlines()

T = int(inp[0])

#N, A, B = map(int, inp[1].split())

#rows = [list(inp[i]) for i in range(2, N + 2)]

amount = 0
current = 1

for z in range(T):
    amount = 0
    N, A, B = map(int, inp[current].split())
    #print(A, B)
    rows = [list(inp[i].strip()) for i in range(current + 1, N + current + 1)]
    #print(rows)
    current += N + 1

    for i in range(N):
        for j in range(N):
            position = [i, j]

            if A == 0 and B == 0:

                if rows[i][j] == "G" or rows[i][j] == "B":
                    #print(i, j)
                    amount += 1
                    #print(amount)
                continue

            if rows[i][j] == "B":
                amount += 1
            
                

            if rows[i][j] == "G" or rows[i][j] == "B":
                
                position[0] += B
                
                position[1] += A
                

                if i + B < N and j + A < N:
                    
                    if rows[position[0]][position[1]] == "G" or rows[position[0]][position[1]] == "B":
                        #print(position[0], position[1])
                        amount += 1
                else:
                    break
    if amount == 1 and (A > 0 or B > 0):
        print(-1)     
    else:
        print(amount)
