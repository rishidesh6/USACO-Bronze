"""
ID: rishide4
TASK: ride
LANG: PYTHON3

"""

fin = open('friday.txt', 'r')
fout = open('friday.out', 'w')

N = fin.read()

daysInMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

daysOfWeek = [1, 0, 0, 0, 0, 0, 0]

day = 0


for year in range(0, N):
    
    for i in range(0, len(daysInMonth)):
        month = daysInMonth[i]
        if i == 1:
            if year % 4 == 0:
            
                if year % 100 == 0:
                
                    if year % 400 == 0:
                        month += 1
                else:
                    month += 1
                
        day = (day + daysInMonth[i]) % 7 
        daysOfWeek[day] += 1

print(daysOfWeek)
