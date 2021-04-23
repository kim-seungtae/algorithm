class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        version1 = list(version1.split('.'))
        version1 = list(map(str,list(map(int, version1))))
        version2 = list(version2.split('.'))
        version2 = list(map(str,list(map(int, version2))))
        
        while len(version1) > 0 and version1[-1] == '0':
            del version1[-1]
        while len(version2) > 0 and version2[-1] == '0':
            del version2[-1]
            
        for a,b in zip(version1, version2):
            if int(a) > int(b):
                return 1
            elif int(a) < int(b):
                return -1
        
        if len(version1) > len(version2):
            return 1
        elif len(version1) < len(version2):
            return -1
        else:
            return 0