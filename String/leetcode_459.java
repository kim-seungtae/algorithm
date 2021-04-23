class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int len = s.length();
        for (int i=len/2; i>=1; --i) {
            if (len%i == 0) {
                String tmp = s.substring(0, i);
                int j;
                for (j=i; j<len; j+=i) {
                    if (!tmp.equals(s.substring(j, j+i))) break;
                }
                if (j == len) return true;
            }
        }
        return false;
    }
}