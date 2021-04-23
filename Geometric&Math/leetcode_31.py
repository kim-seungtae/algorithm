class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        idx = 0
        chk = 1
        for i in range(len(nums)-1, 0, -1):
            if nums[i] > nums[i-1]:
                idx = i-1
                chk = 0
                break
        if chk==1:
            nums.sort()
            return
        larger_min = math.inf
        larger_min_idx = idx
        for i in range(idx+1, len(nums)):
            if nums[idx] < nums[i] and larger_min >= nums[i]:
                larger_min_idx = i
                larger_min = nums[i]
        nums[larger_min_idx], nums[idx] = nums[idx], nums[larger_min_idx]
        l = idx+1
        r = len(nums)-1
        while (l < r):
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1