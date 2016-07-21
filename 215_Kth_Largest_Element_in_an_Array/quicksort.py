def quickSort(nums, p, r):
    if p < r:
        q = partition(nums, p, r)
        print nums, q
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

nums = [5, 3, 2, 6, 4, 1, 3, 7]
#nums = [5, 3, 2]
start = 0
end = 7
quickSort(nums, 0, len(nums) - 1)
print nums
