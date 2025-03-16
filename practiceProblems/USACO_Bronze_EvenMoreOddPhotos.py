import sys

inp = sys.stdin.readlines()

n = int(inp[0])

ids = [int(inp[1].split()[i]) for i in range(n)]


evens = []
for i in ids:

    if i % 2 == 0:

        evens.append(i)

        ids.remove(i)

evens.sort()

ids.sort()

evens.append(ids)


current = "even"
amount = 0

for i in range(len(ids)):

    if current == "even":

        if ids[i] % 2 == 0:

            amount += 1

            current = "odd"
            
        else:

            total = ids[i]

            for j in range(i + 1, len(ids)):

                if total + ids[j] % 2 == 0:

                    amount += 1

                    current = "odd"

                    break
                
                else:

                    total += ids[j]

                if j == len(ids) - 1:

                    amount -= 1

                    

                    
    else:

        if ids[i] % 2 == 1:

            amount += 1

            current = "even"

        else:

            total = ids[i]

            for k in range(i + 1, len(ids)):

                if total + ids[k] % 2 == 1:

                    amount += 1

                    current = "even"

                    break
                
                else:

                    total += ids[k]

                if k == len(ids) - 1:

                    amount -= 1
print(amount)

            
