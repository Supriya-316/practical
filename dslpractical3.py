def display(a):
    for i in range (m):
        print ('\n')
        for j in range (n):
           print(a[i][j] , end = " ")



def ADD():
    for i in range (m):
        for j in range (n):
            C[i][j] = A[i][j] + B[i][j]

    display(C)


def SUB():
    for i in range (m):
        for j in range (n):
            C[i][j] = A[i][j] - B[i][j]

    display(C)


def MUL():
    for i in range (m):
        for j in range (q):
            for k in range(n):
                C[i][j] = A[i][k]* B[k][j]

    display(C)


def  Trans():
    for i in range(m):
        for j in range (n):
            C[j][i]= A[i][j]
    print ("\ntranpose of matrix1 " )
    display(C)



    for i in range(p):
        for j in range (q):
            C[j][i]= B[i][j]
    print ("\ntranpose of matrix2 " )
    display(C)




m = int (input ("\nenter number of rows for matrix 1 :"))
n = int ( input ( "\nenter number of columns for matrix 1:"))

A = [[0 for j in range (n)] for i in range (m)]

print("\nenter elements of matrix A")
for i in range (m):
    for j in range (n):
        A[i][j] = int (input ("enter element A{}{}".format(i , j)))
       
display (A)


p = int (input ("\nenter number of rows for matrix 2 :"))
q = int ( input ( "\nenter number of columns for matrix 2:"))

B = [[0 for j in range (q)] for i in range (p)]

print("\nenter elements of matrix B")
for i in range (p):
    for j in range (q):
        B[i][j] = int (input ("enter element B{}{}".format(i , j)))
       
display (B)


C = [[0 for j in range (n)]for i in range(m)]
if m==p and n==q:
    print('\nAddition of MATRIX is')
    ADD()
else :
    print("Addition not possible")

if m==p and n==q:
    print('\nSubtraction of MATRIX is')
    SUB()
else:
    print("\nSubtraction not possible")

if  n==p:
    print ("\nMultiplication of matrices is")
    MUL()
else :
    print ("\n Multiplication not possible")
print( "\nTranspose of matrices are")
Trans()














