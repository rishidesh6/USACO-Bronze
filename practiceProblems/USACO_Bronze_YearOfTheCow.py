import sys

inp = sys.stdin.readlines()

N = int(inp[0])

firstCows = [inp[i].split()[0] for i in range(1, N + 1)]

time = [inp[i].split()[3] for i in range(1, N + 1)]

year = [inp[i].split()[4] for i in range(1, N + 1)]

secondCows = [inp[i].split()[-1] for i in range(1, N + 1)]

years = {"Ox": 0, "Tiger": 1, "Rabbit": 2, "Dragon": 3, "Snake": 4, "Horse": 5, "Goat": 6, "Monkey": 7, "Rooster": 8, "Dog": 9, "Pig": 10, "Rat": 11}

cows = {"Bessie": "Ox"}
timeAway = {"Bessie": 0}

for i in range(0, N):
    calc = secondCows[i]
    yearNeeded = year[i]
    firstCow = firstCows[i]

    if time[i] == "previous":
        #print(time[i])
        position = years[cows[calc]]

        if position > years[yearNeeded]:
            val = position - years[yearNeeded]
                         
        else:
            val = 12 - (years[yearNeeded] - position)
            
        timeAway[firstCow] = timeAway[calc] - val
        #print(timeAway)
        #cows[firstCow] = yearNeeded
                         
    else:
        #print(time[i])
        position = years[cows[calc]]
                         
        if position < years[yearNeeded]:
            val = years[yearNeeded] - position
        else:
            val = 12 - (position - years[yearNeeded])
            
        timeAway[firstCow] = timeAway[calc] + val
        #print(timeAway)
    cows[firstCow] = yearNeeded
    #print(cows)
                         
print(abs(timeAway["Elsie"]))        
        



'''import sys

inp = sys.stdin.readlines()

N = int(inp[0])

firstCows = [inp[i].split()[0] for i in range(1, N + 1)]

time = [inp[i].split()[3] for i in range(1, N + 1)]

year = [inp[i].split()[4] for i in range(1, N + 1)]

secondCows = [inp[i].split()[-1] for i in range(1, N + 1)]

years = {"Ox": 0, "Tiger": 1, "Rabbit": 2, "Dragon": 3, "Snake": 4, "Horse": 5, "Goat": 6, "Monkey": 7, "Rooster": 8, "Dog": 9, "Pig": 10, "Rat": 11}

cows = {"Bessie": "Ox"}
timeAway = {"Bessie": 0}


for i in range(0, N):
    
    calc = secondCows[i]
    yearNeeded = year[i]
    firstCow = firstCows[i]

    if time[i] == "previous":
        print(time[i])
        
        position = years[cows[calc]
                         
        if position > years[yearNeeded]:
            val = position - years[yearNeeded]
                         
        else:
            val = 12 - (yearNeeded - position)
            
        timeAway[firstCow] = timeAway[calc] - val
        cows[firstCow] = yearNeeded
                         
    else:

        position = years[cows[calc]
                         
        if position < years[yearNeeded]:
            val = yearNeeded - position
        else:
            val = 12 - (position - yearNeeded)
            
        timeAway[firstCow] = timeAway[calc] + val
        cows[firstCow] = yearNeeded
                        
                         
        
print(timeAway["Elsie"])'''        
        
