class Solution:
    def intToRoman(self, num: int) -> str:
        ans = ""
        if num // 1000 > 0:
            ans += ("M" * (num // 1000))
    
        num %= 1000
        if num // 100 > 0:
            if num // 100 < 4:
                ans += ("C" * (num // 100))
            elif num // 100 == 4:
                ans += "CD"
            elif num // 100 < 9:
                ans += ("D" + "C" * ((num // 100)-5))
            elif num // 100 == 9:
                ans += "CM"
        
        num %= 100
        if num // 10 > 0:
            if num // 10 < 4:
                ans += ("X" * (num // 10))
            elif num // 10 == 4:
                ans += "XL"
            elif num // 10 < 9:
                ans += ("L" + "X" * ((num // 10)-5))
            elif num // 10 == 9:
                ans += "XC"
        
        num %= 10
        if num > 0:
            if num < 4:
                ans += ("I" * num)
            elif num == 4:
                ans += "IV"
            elif num < 9:
                ans += ("V" + "I" * (num-5))
            elif num == 9:
                ans += "IX"
                
        return ans