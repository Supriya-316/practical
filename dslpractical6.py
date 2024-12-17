#best T.C = 0(nlogn)
#worst T.C = 0(n^2)


def quicksort(arr,left,right):
    if left < right:
        pivot = partition (arr,left,right)
        quicksort(arr,left,pivot -1)
        quicksort(arr,pivot +1,right)


def partition(arr,left,right):
    i = left
    j= right-1
    p = arr [right]
    
    while i < j:
        while i < right  and arr[i] < p :
            i += 1
        while j > left  and arr[j]> p :
            j -= 1
        if i < j :
            arr[i],arr[j] =arr[j],arr[i]
        

    if arr[i] > p :
        arr [i],arr [right] = arr[right],arr[i]

    return i  


percentage = []
n = int(input ("\nnumber of students in the array"))

for i in range(n):
    value = float (input("\nenter value of percentage of the students:"))
    percentage.append(value)

print("unsorted array of percentage  is :", percentage)

quicksort(percentage,0,len(percentage)-1)
print("Sorted array of percentages is", percentage)

def display_top_scores(arr):
    for i in range(1,6):
        print(arr[-i])

print("\nTo display top 5 percentage :")
display_top_scores(percentage)



    
