"""
Given two integers L and R find maximal values of A xor B, given L<=A<=B<=R
"""

def maxXor(l, r):
    nums = []
    iters = (r - l) + 1

    if l == 0: return r

    while l <= r:
        for i in range(iters):
            nums.append(l ^ (l+i))

        l += 1
        iters = r - l

    return max(nums)

if __name__ == '__main__':
    print(maxXor(10, 15) == 7)
    print(maxXor(1, 10) == 15)
    print(maxXor(0, 1) == 1)
    print(maxXor(1, 2) == 3)


