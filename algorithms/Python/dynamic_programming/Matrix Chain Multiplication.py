'''
Matrix Chain Multiplication
Send Feedback Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications. You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
'''
import sys
from sys import stdin
def matrixChainMemoised(p, i, j):
    if(i == j):
        return 0
     
    if(dp[i][j] != -1):
        return dp[i][j]
     
    dp[i][j] = sys.maxsize
     
    for k in range(i,j):
        dp[i][j] = min(dp[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j)+ p[i - 1] * p[k] * p[j])
     
    return dp[i][j]
def mcm(p,n):
    i = 1
    j = n - 1   
    return matrixChainMemoised(p, i, j)
#main   
n=int(stdin.readline().strip())
dp = [[-1 for j in range(n+1)]for i in range(n+1)]
p=[int(i) for i in stdin.readline().strip().split()]
n=len(p)
print(mcm(p,n))