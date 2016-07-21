##Quick Sort

**實作:**

```
1. 觀念就是：利用 pivot 將 list partition 成三個部分:
	- 小於 pivot, pivot, 大於 pivot
2. pivot 處於不動的狀態
3. 將 pivot 之前及之後的 list 丟進去 quickSort
```

**注意:**

```
1. 在 partition 時，要注意回傳的值必須是一開始選定的 pivot
2. 所以最簡單的實作方法是將 list[0] 選為 pivot
3. 再從 list[1], list[-1] 開始做交換
4. 最後再將 pivot 移到 partition 的位置  
```

**代碼:**

```python
def quickSort(nums, p, r):
    if p < r:
        q = partition(nums, p, r)
        quickSort(nums, p, q - 1)
        quickSort(nums, q + 1, r)


def partition(nums, start, end):
    pivot = nums[start]
    left = start + 1
    right = end
    while True:
        while left <= right and nums[left] <= pivot:
            left += 1
        while nums[right] >= pivot and right >= left:
            right -= 1

        if left <= right:
            nums[left], nums[right] = nums[right], nums[left]
        else:
            break
    # We have to insure that we return the pivot
    nums[right], nums[start] = nums[start], nums[right]
    return right
```

##Merge Sort

