class Solution:
    def numTrees(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1
        
        dp = [0]*(n+1)
        dp[0] = 1
        dp[1] = 1
        dp[2] = 2
        
        for num in range(3, n+1):
            tmp = 0
            for root in range(1, num+1):
                left = root - 1
                right = num - root
                tmp += (dp[left] * dp[right])
            dp[num] = tmp
        return dp[-1]
            
            
            