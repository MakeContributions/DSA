# Given a list of items with values and weights, as well as the maximum capacity
# Return the maximum value from the items list where the total weights is less than the maximum capacity

"""
Input:
    list = [[1, 2], [4,3], [5,6], [6,7]] #[[value,weight]]
    capacity = 10

Output: 10
"""

def knapsack(items, capacity):
    dp = [[0 for _ in range(capacity+1)] for _ in range(len(items)+1)]

    for row in range(1, len(dp)):
        for col in range(1, len(dp[row])):
            current_weight = items[row-1][1]
            current_value = items[row-1][0]

            if current_weight > col:
                dp[row][col] = dp[row-1][col]
            else:
                dp[row][col] = max(dp[row-1][col], dp[row-1][col-current_weight]+current_value)
    return dp[-1][-1]



# I will use the input from above but feel free to modify the input to test

items = [[1, 2], [4,3], [5,6], [6,7]]
capacity = 10

knapsack_value = knapsack(items, capacity)

print(knapsack_value)  # Should print 10