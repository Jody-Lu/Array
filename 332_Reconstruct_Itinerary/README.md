#Reconstruct Itinerary

##Euler Circuit

**A path that passes all edges in the graph for one time.**

##Heirholzer's Algorithm

**This algorithm is used to find Euler Circuit.**

1. 一個 Euler Circuit ，在某點相交，可拆成兩個 Euler Circuit 。
2. 兩個 Euler Circuit ，可在某點相接，合成一個 Euler Circuit 。
3. 大的 Euler Circuit 可拆成小的，小的可接成大的 —— 自然想到 Divide and Conquer 。

**Code**

```python
import collections
class Solution(object):
    def findItinerary(self, tickets):
        """
        DFS & Backtracking
        Find Euler Path --> Heirholzer's Algorithm
        """
        targets = collections.defaultdict(list)
        for f, t in sorted(tickets)[::-1]:
            targets[f] += t,
        route = []
        print targets
        def visit(airport):
            # Divide
            while targets[airport]:
                visit(targets[airport].pop())
            # Combine the path
            route.append(airport)
        visit("JFK")
        return route[::-1]
```
