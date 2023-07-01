## the code below explains the way to rotate matrix/image by 90 degrees

# let matrix=[[1,2,3],[4,5,6],[7,8,9]]

# matrix_after_rotation=[[7,4,1],[8,5,2],[9,6,3]]

## algorithm:
# -> swap rows using two pointers and then swap the index as a[i][j],a[j][i]=a[j][i],a[i][j]

def matrix_rotation_90_degree(matrix):
    ## using two pointer 
    l,r=0,len(matrix)-1

    while l < r:
        matrix[l],matrix[r] = matrix[r],matrix[l]   ## swapping rows using two pointers
        l+=1
        r-=1
    # result
    # # matrix=[[7,8,9],[4,5,6],[1,2,3]]

    ## swapping the rows and cols of every element of matrix

    for i in range(len(matrix)):
        for j in range(i,len(matrix)):
            ## at every iteration the row is swap with the column anc vice versa
            matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]
    
    # result
    # matrix=[[7,4,1],[8,5,2],[9,6,3]]
    return matrix


#  prints([[7,4,1],[8,5,2],[9,6,3]])
print(matrix_rotation_90_degree([[1,2,3],[4,5,6],[7,8,9]])) 
    

