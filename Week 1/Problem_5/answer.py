import sys

fRead = open("word.in", "r")
f = open("word.out", "w")

n, k = map(int,fRead.readline().strip().split())
words = fRead.readline().strip().split()

finalWords = ""
lengthLimit = k



for i in range(0, len(words)):   
    if lengthLimit - len(words[i]) >= 0:
        finalWords += (words[i] + " ")
        
        lengthLimit -= len(words[i])
       
    else:
        f.write(finalWords.strip() + "\n")
        finalWords = ""
        finalWords += (words[i] + " ")
        lengthLimit = k - len(words[i])

if finalWords != "":
    f.write(finalWords.strip())

f.close()
