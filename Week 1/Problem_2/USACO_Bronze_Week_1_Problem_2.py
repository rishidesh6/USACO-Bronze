import sys


import random



sys.stdin = open("buckets.in", "r")


sys.stdout = open("buckets.out", "w")



for i in range(10):


    row = input()


    for j in range(10):


        if row[j] == "R":


            rock_x = i


            rock_y = j


        elif row[j] == "B":


            barn_x = i


            barn_y = j


        elif row[j] == "L":


            lake_x = i


            lake_y = j


cows = abs(barn_x - lake_x) + abs(barn_y - lake_y) - 1



if ((rock_x == barn_x == lake_x) and (barn_y < rock_y < lake_y or lake_y < rock_y < barn_y)):

    cows = cows + 2


if ((rock_y == barn_y == lake_y) and (barn_x < rock_x < lake_x or lake_x < rock_x < barn_x)):

	cows = cows + 2


print(cows)
