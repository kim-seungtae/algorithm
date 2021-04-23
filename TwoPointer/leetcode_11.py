class Solution:
    def maxArea(self, height: List[int]) -> int:
        size = len(height)
        ans = 0
        i, j = 0, size-1
        
        while i < j:
            if height[i] > height[j]:
                ans = max(height[j] * (j-i), ans)
                j-=1
            else:
                ans = max(height[i] * (j-i), ans)
                i+=1
        
        return ans