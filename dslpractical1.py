marklist = []

n = int (input ("enter number of students:"))

#taking marks as input
for i in range(n):
    marks=int(input("enter marks of students(-1 for absent students)"))
    marklist.append(marks)

print("marklist =" , marklist)


#calculating average
print ("solution for a")
total= 0
count= 0
for mark in marklist:
    if mark != -1 :
      total += mark
      count += 1

avgmarks = total/count
print ("average marks of students are=", avgmarks)


#calculate max and min
print ('solution for b')
max_value = marklist[0]
min_value = marklist[0]

for mark in marklist:
    if mark > max_value :
        max_value = mark  
    if mark !=-1:
     if mark < min_value :
        min_value = mark


print("maximum value is :", max_value)
print("minimum value is :", min_value)

#calculating number of absent students
print ("solution for c")
absentstucount = 0
for mark in marklist :
    if mark == -1 :
        absentstucount += 1


print ('absent student count is :', absentstucount)


#calculating frequency
print("solution for d")

freq={}

for mark in marklist:
    if mark!= -1:
        if freq.get(mark) == None:
            freq[mark]= 1
        else :
            freq[mark]+= 1

print("frequnecy is :", freq)

highest_frequency = 0
highest_frequency_marks = 0
for mark in freq:
     if freq[mark] > highest_frequency:
         highest_frequency = freq[mark]
         highest_frequency_marks = mark



print ("highest frequency", highest_frequency_marks)









