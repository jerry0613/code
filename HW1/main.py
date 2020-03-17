# Part. 1

#=======================================

# Import module

#  csv -- fileIO operation

import csv

#=======================================


# Part. 2

#=======================================

# Read cwb weather data

cwb_filename = '107061141.csv'
target = ['C0A880', 'C0F9A0', 'C0G640', 'C0R190', 'C0X260']
data = []
sum = 0
flag = 0
j = 0
answer = []
temp = []

with open(cwb_filename) as csvfile:

   mycsv = csv.DictReader(csvfile)

   for row in mycsv:

      data.append(row)

#=======================================
# Part. 3

# Analyze data depend on your group and store it to target_data like:
for i in target:
    temp.append(i)
    for row in data:
        if (row['station_id'] == i):
            if (float(row['HUMD']) == -99.000 or float(row['HUMD']) == -999.000):
                flag = 1
                break    
            else:
                sum = sum + float(row['HUMD'])
    if (flag == 0):
        temp.append(sum)
    else:
        temp.append('None')
    flag = 0
    sum = 0
    answer.append(temp)
    temp = []
                


#=======================================
# Part. 4

# Print result
print(answer)


