percentage = []
n = int(input ("\nnumber of students in the array"))

for i in range(n):
    value = float (input("\nenter value of percentage of the students:"))
    percentage.append(value)

print("unsorted array of percentage  is :", percentage)

def insertion(arr):
    n = len(arr)

    for i in range (1,n):
        key = arr[i]
        j = i -1
        while j>=0 and arr[j] > key:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1]= key

#best T.C = 0(n)- already sorted
#worst T.C = 0(n^2)


insertion (percentage)
print ("\nSorting by insertition sort is:", percentage)


def shellsort(arr):
    n = len(arr)
    gap = n//2
    while gap >0 :
        for i in range(gap,n):
            temp = arr [i]
            j = i 
            while j >= gap and arr[j - gap]> temp :
                arr[j] = arr[j-gap]
                j = j - gap
            arr[j] = temp
            gap= gap//2



print ("\n Sorting by shellsort is", percentage)

#best T.C = 0(nlogn)
#worst T.C = 0(n^2)


        
def display_top_scores(arr):
    for i in range(1,6):
        print(arr[-i])

print("\nto display top 5 percentage :")
display_top_scores(percentage)



