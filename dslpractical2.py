def intersection(l1,l2):

    res = []

    for student in l1:
        if student in l2:
            res.append(student)

    return res 


def union(l1,l2):
    res = l2.copy()

    for student in l1:
        if student  not in l2:
            res.append(student)



    return res


def diff(l1,l2):
    res = []

    for student in l1:
        if student  not in l2:
            res.append(student)



    return res
     
a =[1,2,3,4,5,6,7]
b=[2,3,6,7,9,10]
c=[2,4,6,8,10,12]

print ("A =", a )
print ("B=", b)
print ("C =", c )
print ('solution for a')
print ( intersection(a,b))
#print ( union(a,b))


print ("solution for b")
#here sequence matters as we doing setA - SetB
u = union(a,b)
i = intersection(a,b)
print( diff(u,i))



print ( "solution for c")
print (diff(diff(c,b),a))


print ( "solution for d")
print(diff(union(a,c),b))


