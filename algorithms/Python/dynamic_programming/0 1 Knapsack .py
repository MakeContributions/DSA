'''
0 1 Knapsack - Problem
Send Feedback A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?
'''


from sys import stdin

def knapsack(weights, values, n, maxWeight) :
    K=[[0 for x in range(maxWeight+1)] for x in range(n+1)]
    for i in range(n+1):
        for w in range(maxWeight+1):
            if i==0 or w==0:
                K[i][w]=0
            elif weights[i-1]<=w:
                K[i][w]=max(values[i-1]+K[i-1][w-weights[i-1]],K[i-1][w])
            else:
                K[i][w]=K[i-1][w]
    return K[n][w]







def takeInput() :
    n = int(stdin.readline().rstrip())

    if n == 0 :
        return list(), list(), n, 0

    weights = list(map(int, stdin.readline().rstrip().split(" ")))
    values = list(map(int, stdin.readline().rstrip().split(" ")))
    maxWeight = int(stdin.readline().rstrip())

    return weights, values, n, maxWeight


#main
weights, values, n, maxWeight = takeInput()

print(knapsack(weights, values, n, maxWeight))