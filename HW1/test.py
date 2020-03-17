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

data = []

header = []

flag1 = 0
flag2 = 0
flag3 = 0
flag4 = 0
flag5 = 0

sum1 = 0
sum2 = 0
sum3 = 0
sum4 = 0
sum5 = 0

i = 0

with open(cwb_filename) as csvfile:

   mycsv = csv.DictReader(csvfile)

   header = mycsv.fieldnames

   for row in mycsv:

      data.append(row)

#=======================================


# Part. 3

#=======================================

# Analyze data depend on your group and store it to target_data like:

# Retrive all data points which station id is "C0X260" as a list.

# target_data = list(filter(lambda item: item['station_id'] == 'C0X260', data))


# Retrive ten data points from the beginning.
while i < 10068:
    if (data[i]['station_id'] == 'C0A880'):
        if (float(data[i]['HUMD']) == -99.000 or float(data[i]['HUMD']) == -999.000):
            flag1 = 1
        else:
            sum1 = sum1 + float(data[i]['HUMD'])
    elif (data[i]['station_id'] == 'C0F9A0'):
        if (float(data[i]['HUMD']) == -99.000 or float(data[i]['HUMD']) == -999.000):
            flag2 = 1
        else:
            sum2 = sum2 + float(data[i]['HUMD'])
    elif (data[i]['station_id'] == 'C0G640'):
        if (float(data[i]['HUMD']) == -99.000 or float(data[i]['HUMD']) == -999.000):
            flag3 = 1
        else:
            sum3 = sum3 + float(data[i]['HUMD'])
    elif (data[i]['station_id'] == 'C0R190'):
        if (float(data[i]['HUMD']) == -99.000 or float(data[i]['HUMD']) == -999.000):
            flag4 = 1
        else:
            sum4 = sum4 + float(data[i]['HUMD'])
    elif (data[i]['station_id'] == 'C0X260'):
        if (float(data[i]['HUMD']) == -99.000 or float(data[i]['HUMD']) == -999.000):
            flag5 = 1
        else:
            sum5 = sum5 + float(data[i]['HUMD'])
    i = i + 1


                
            


#=======================================


# Part. 4

#=======================================

# Print result

if (flag1 == 0):
    print("'C0A880',", sum1)
else:
    print("'C0A880','None'")

if (flag2 == 0):
    print("'C0F9A0',", sum2)
else:
    print("'C0F9A0','None'")

if (flag3 == 0):
    print("'C0G640',", sum3)
else:
    print("'C0G640','None'")

if (flag4 == 0):
    print("'C0R190',", sum4)
else:
    print("'C0R190','None'")

if (flag5 == 0):
    print("'C0X260',", sum5)
else:
    print("'C0X260','None'")
#========================================