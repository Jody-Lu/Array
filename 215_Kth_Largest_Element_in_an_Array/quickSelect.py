def quickSelect(nums, p, r, x):
    if p == r: return nums[p]
    q = partition(nums, p, r)
    if q == x - 1:
        return nums[q]
    if q > x - 1:
        return quickSelect(nums, p, q - 1, x)
    else:
        return quickSelect(nums, q + 1, r, x)

def partition(nums, begin, end):
    left = begin + 1
    right = end
    pivot = nums[begin]

    while True:
        while left <= right and nums[left] <= pivot:
            left += 1
        while right >= left and nums[right] >= pivot:
            right -= 1

        if left <= right:
            nums[right], nums[left] = nums[left], nums[right]
        else:
            break

    nums[begin], nums[right] = nums[right], nums[begin]
    return right


nums = [3, 2, 1, 5, 6, 4]
x = 2
print sorted(nums)
print quickSelect(nums, 0, len(nums) - 1, len(nums) - x + 1)
