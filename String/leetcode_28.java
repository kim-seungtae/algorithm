class Solution {
    public int strStr(String haystack, String needle) {
        if (needle == "") return 0;
        int size = needle.length();
        for (int i=0; i<=haystack.length()-size; i++) {
            if (haystack.substring(i, i+size).equals(needle)) return i;
        }
        return -1;
    }
}