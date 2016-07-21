def zero_one_knapsack(items, volume):
    """
    : type values: List[int]
    : type things: List[int]
    : type volume: int
    : time complexity: O(NV)
    : space complexity: O(NV)
    """
    # N: number of items; W; maximum weight
    N = len(items) 
    W = volume
    f = [[0] * (W + 1) for _ in xrange(N + 1)]
    
    for i, (value, weight) in enumerate(items):
        # Since 0 has defined, so we plus i by one
        i += 1
        for capacity in xrange(value, W + 1):
            if weight > capacity:
                f[i][capacity] = f[i - 1][capacity]
            else:
                c1 = f[i - 1][capacity]
                c2 = f[i - 1][capacity - weight] + value
                f[i][capacity] = max(c1, c2)
    
    return f[N][W]


def Knapsack(items, volume):
    """
    : type volume: int 
    : type items: List[(int, int)] 
    : time complexity: O(NV)
    : space complexity: O(V)
    """
    N = len(items)
    V = volume
    INF = -0xffffffff
    #f = [0] * (V + 1)
    f = [0] + [INF] * V
    for value, weight in items:
        for capacity in reversed(xrange(value, V + 1)):
            f[capacity] = max(f[capacity], 
                              f[capacity - weight] + value)
    print f
    return f[V]


if __name__ == '__main__':
    values = [92, 57, 49, 68, 60, 43, 67, 84, 87, 72]
    things = [23, 31, 29, 44, 53, 38, 63, 85, 89, 82]
    items = [(values[i], things[i]) for i in range(len(things))]
    volume = 165
    """
    items = [(4, 8), (5, 3), (5, 5)]
    volume = 10
    """
    """
    values = [40, 15, 15]
    things = [85, 30, 50]
    volume = 100
    """
    import time
    start = time.time()
    print zero_one_knapsack(items, volume)
    print time.time() - start
    start = time.time()
    print Knapsack(items, volume)
    print time.time() - start
