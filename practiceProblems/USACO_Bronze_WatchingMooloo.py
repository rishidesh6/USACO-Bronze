import sys

'''inp = sys.stdin.readlines()

N, K = map(int, inp[0].split())

days = inp[1].split()



total = 0
taken = 0
amount = len(days)
cycles = 0

for i in range(0, len(days)):
    
    new_i = i + 1


    if i == len(days) - 1:
           	 
        total += 1 + K
       	 
        break

   	 
    while int(days[new_i]) - int(days[i]) + 1 <= K:
        cycles += 1
        if new_i + 1 <= amount - 1:
            new_i += 1
        else:
            break
        
        
   	 
    if cycles > 0:
        total += (int(days[new_i]) - int(days[i]) + 1) + K
        taken += cycles + 1
   	 
    else:
        total += 1 + K
        taken += 1
   	 
    if taken == amount:
        break
print(total)'''

inp = sys.stdin.readlines()

N, K = map(int, inp[0].split())

days = inp[1].split()



total = 0
taken = 0
amount = len(days)

for i in range(0, len(days)):

    if i == len(days) - 1:
           	 
    	total += 1 + K
       	 
    	break

   	 
    if int(days[i + 1]) - int(days[i]) <= K:
    	total += (int(days[i + 1]) - int(days[i]) + 1) + K
    	taken += 2
   	 
    else:
    	total += 1 + K
    	taken += 1
   	 
    if taken == amount:
    	break
print(total)
