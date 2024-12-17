arr = []
n = int(input ("\nnumber of students in the array"))

for i in range(n):
    elements = int (input("\nenter elements of the array:"))
    arr.append(elements)

print("array is :", arr)


key = int(input("\nenter the element you want to search"))


def linear_search(arr,key):
    #0(n)
    for i in range(len(arr)):
        if arr[i]== key:
            return i
            

    return -1

index = linear_search(arr,key)

if index == -1:
    print("\nelement not in array")
else:
    print("\nelement index you are trying to search  by linear search is", index)


def sentinal_search(arr,key):
    #0(n)
    last = arr[-1]
    arr[-1]= key
    i = 0 
    while  arr[i]!=key:
        i +=1

    if i != len(arr)-1 :
        return i
    if last == key:
        return len(arr)-1
    
    return -1


index = sentinal_search( arr,key)
if index == -1:
    print("\nelement not present in array")

else :
    print("\nBy sentinal search we got index as :" , index )




def binary_search(arr , key):
    #0(logn)
    left = 0
    right = len(arr)-1


    while left <= right :
        mid = (left + right)// 2
        if arr[mid]==key :
            return mid
        elif arr[mid]< key:
            left = mid +1
        else : 
            right = mid - 1 

    return -1

index = binary_search(arr,key)

if index == -1:
    print("\nelement not present in array")

else :
    print("\nBy binary search we got index as :" , index )


def fibonacci_search(arr, key):
    n = len(arr)
    fib_m_2 = 0  
    fib_m_1 = 1 
    fib = fib_m_1 + fib_m_2 


    while (fib < n):
        fib_m_2 = fib_m_1
        fib_m_1 = fib
        fib = fib_m_1 + fib_m_2

   
    offset = -1

   
    while (fib > 1): 

        i = min(offset + fib_m_2, n - 1)

        
        if arr[i] < key:
            fib = fib_m_1
            fib_m_1 = fib_m_2
            fib_m_2 = fib - fib_m_1
            offset = i

        
        elif arr[i] > key:
            fib = fib_m_2
            fib_m_1 = fib_m_1 - fib_m_2
            fib_m_2 = fib - fib_m_1

        
        else:
            return i

   
    if fib_m_1 and arr[offset + 1] == key:
        return offset + 1

    return -1


index = fibonacci_search(arr, key)

if index == -1:
    print("\nElement not found using Fibonacci search")
else:
    print("\nBy Fibonacci search we got index as:", index)

