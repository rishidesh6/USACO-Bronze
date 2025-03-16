"""
ID: rishide4
TASK: namenum
LANG: PYTHON3

"""

import sys

inpFile = open("namenum.in", "r")
outFile = open("namenum.out", "w")
dictionary = open("dict.txt", "r")

phone = {2: "ABC", 3: "DEF", 4: "GHI", 5: "JKL", 6: "MNO", 7: "PRS", 8: "TUV", 9: "WXY"}

number = ''
validNames = 0

for word in dictionary.readlines():
    #word = dictionary.readlines()[i]

    for j in word:
        if j == "Z" or j == "Q":
            continue 
        for k in phone:
            if j in phone[k]:
                number += str(j)

    if number == inpFile.readlines()[0]:
        validNames += 1
    number = ''

if validNames == 0:
    
    outFile.write("NONE" + "\n")

else:
    
    outFile.write(str(validNames) + "\n")
    
outFile.close()
