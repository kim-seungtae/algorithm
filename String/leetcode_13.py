class Solution:
    def romanToInt(self, s: str) -> int:
        ans = 0
        
        l = []
        
        for char in s:
            if char == 'I':
                l.append(1)
            elif char == 'V':
                l.append(5)
            elif char == 'X':
                l.append(10)
            elif char == 'L':
                l.append(50)
            elif char == 'C':
                l.append(100)
            elif char == 'D':
                l.append(500)
            else:
                l.append(1000)
        
        size = len(l)
        i = 0
        while i < size-1:
            if l[i] < l[i+1]:
                ans += (l[i+1] - l[i])
                i+=2
            else:
                ans += l[i]
                i+=1
        if i == size-1:
            ans += l[size-1]
        return ans