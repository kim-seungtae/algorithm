class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) <= 1:
            return s
        
        ans = ""
        size = 0
        
        for idx in range(len(s)):
            tmp = s[idx]
            l = 0
            while idx-l >= 0 and idx+l < len(s) and s[idx-l] == s[idx+l]:
                l += 1
            tmp = s[idx-l+1:idx+l]
            if size < len(tmp):
                ans = copy.deepcopy(tmp)
                size = len(ans)
                
        for idx in range(len(s)):
            tmp = ""
            l = 0
            
            while idx-l >= 0 and idx+1+l < len(s) and s[idx-l] == s[idx+1+l]:
                l += 1
            
            tmp = s[idx-l+1:idx+l+1]
            if size < len(tmp):
                ans = copy.deepcopy(tmp)
                size = len(ans)
                
        return ans