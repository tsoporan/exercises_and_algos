"""
Example merge sort, recursive
"""

def merge_sort(nums):
    if len(nums) < 2:  # Sorted
        return nums

    midpoint = len(nums) // 2

    # Sort both sides
    left = merge_sort(nums[:midpoint])
    right = merge_sort(nums[midpoint:])

    results = []

    # Merge step
    while len(results) < len(nums):  # Until we've sorted all
        if left and ((not right) or left[0] < right[0]):
            results.append(left.pop(0))
        else:
            results.append(right.pop(0))

    return results


if __name__ == "__main__":
    _sorted = merge_sort([2, 5, 9, 8, 1, 3, 4, 5, 5])
    assert _sorted == [1, 2, 3, 4, 5, 5, 5, 8, 9]

    assert merge_sort([]) == []
    assert merge_sort([1]) == [1]
    assert merge_sort([9, 6, 3]) == [3, 6, 9]
