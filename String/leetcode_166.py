class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"
        ans = ""
        if numerator * denominator < 0:
            ans += "-"
        numerator = abs(numerator)
        denominator = abs(denominator)
        
        quotient, numerator = divmod(numerator, denominator)
        ans += str(quotient)
        
        if numerator == 0:
            return ans
        ans += '.'
        
        quotients, remains = [], []
        while str(numerator) not in remains:
            remains.append(str(numerator))
            numerator = numerator*10
            quotient, numerator = divmod(numerator, denominator)
            quotients.append(str(quotient))
            if numerator == 0:
                ans += ''.join(quotients)
                return ans
        
        #remain에서 numerator의 idx찾기
        iter_start_idx = remains.index(str(numerator))
        
        ans += ''.join(quotients[:iter_start_idx])
        ans += '('
        ans += ''.join(quotients[iter_start_idx:])
        ans += ')'
        return ans
            