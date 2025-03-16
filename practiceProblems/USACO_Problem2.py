import sys

#inp = open("blocks.in", "r")
#out = open("blocks.out", "w")

alphabet = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]

letterDict = {}

for letter in alphabet:
    letterDict[letter] = 0
print(letterDict)

#blocks = inp.readlines()
#words = blocks.split(" ")

def rows(word1, word2):

    dict1 = {}
    dict2 = {}
    finalDict = {}
    
    for i in word1:
        if i in dict1:
            dict1[i] += 1
        else:
            dict1[i] = 1
            
    for i in word2:
        if i in dict2:
            dict2[i] += 1
        else:
            dict2[i] = 1
    
    for i in dict1:
        for j in dict2:
            if i == j:
                if dict1[i] > dict2[j]:
                    finalDict[i] = dict1[i]
                else:
                    finalDict[j] = dict2[j]
            else:
                finalDict[i] = dict1[i]
                finalDict[j] = dict2[j]
                
    return finalDict


values = rows("box", "fox")

print(values)

        
'''for i in range(0, len(word2)):
        list2.append(word2[i])

    for i in list1:
        dict1[i]
        

for letter in letters:
    for i in alphabet:
        if letter == i:
            letterDict[i] += 1


for i in letterDict:
    print(letterDict[i] + "\n")'''
