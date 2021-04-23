class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dic = {}
        dic['2'] = 'abc'
        dic['3'] = 'def'
        dic['4'] = 'ghi'
        dic['5'] = 'jkl'
        dic['6'] = 'mno'
        dic['7'] = 'pqrs'
        dic['8'] = 'tuv'
        dic['9'] = 'wxyz'
        
        l = []
        for char in digits:
            l.append(dic[char])
        if l == []:
            return []
        ans = product(*l)
        ans = [''.join(item) for item in ans]
        return ans