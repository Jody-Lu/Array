def Knapsack(items, maxweight):
    
    #@memoized
    def bestvalue(i, j):
        if i == 0: return 0
        value, weight = items[i - 1]
        if weight > j:
            return bestvalue(i - 1, j)
        else:
            return max(bestvalue(i - 1, j),
                       bestvalue(i - 1, j - weight) + value)
    
    N = len(items)
    W = maxweight
    return bestvalue(N, W) 

items = [(4, 8), (5, 3), (5, 5)]
maxweight = 10
print Knapsack(items, maxweight) 

