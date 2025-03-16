numbers = input()

numbers = numbers.split()

print(numbers)

for i in range(len(numbers)):
    numbers[i] = int(numbers[i])


a = numbers[0]
b = numbers[0]
c = numbers[0]


for i in range(len(numbers)):
    
    if numbers[i] <= a:
        a = numbers[i]
        
numbers.remove(a)
        

for i in range(len(numbers)):
    
    if numbers[i] <= b:
        b = numbers[i]
        
    if numbers[i] >= c:
        c = numbers[i]

print(str(a), str(b), str(c))
