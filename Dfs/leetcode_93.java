class Solution {
    
    static ArrayList<String> ans = new ArrayList<String>();
    static String[] tmp = new String[4];
    
    public static void dfs(int idx, String s) {
        if (idx == 4) {
            if (s.isEmpty()) ans.add(String.join(".", tmp));
            return;
        }
        if (idx != 4 && s.isEmpty()) return;
        
        if (s.charAt(0) == '0') {
            tmp[idx] = "0";
            dfs(idx+1, s.substring(1));
            return;
        }

        int m = Math.min(s.length(), 3);
        for (int i=0; i<m; ++i) {
            int num = Integer.parseInt(s.substring(0, i+1));
            if (num > 255) break;
            else {
                tmp[idx] = String.valueOf(num);
                dfs(idx+1, s.substring(i+1));
            }
        }
    }
    
    public List<String> restoreIpAddresses(String s) {
        ans.clear();
        dfs(0, s);
        return ans;
    }
}