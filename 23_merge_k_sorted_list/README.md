##23 Merge k Sorted List

**What's Heap**

Heaps are binary trees for which every parent node has a value less than or equal to any of its children.

**Heap Sort**

By pushing all values onto a heap and then popping off the smallest values one at a time.

```python
def heapSort(iterable):
	h = []
	for value in iterable:
		heappush(h, value)
	return [heappop(h) for i in xrange(len(h))]
``` 