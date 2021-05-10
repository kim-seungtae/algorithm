class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if (len == 1 || numRows == 1 || len == numRows) return s;
        bool *visited = new bool[len];
        for (int i=0; i<len; ++i) visited[i] = false;
        
        int cycle = numRows + (numRows - 2);
        int down = cycle, up = 0;
        
        string answer = "";
        int rows = min(len, numRows);
        for (int row=0; row<rows; ++row) {
            int idx = row;
            answer += s[idx];
            visited[idx] = true;
            while (idx < len) {
                idx += down;
                if (idx >= len) break;
                if (!visited[idx]) {
                    visited[idx] = true;
                    answer += s[idx];
                }
                idx += up;
                if (idx >= len) break;
                if (!visited[idx]) {
                    visited[idx] = true;
                    answer += s[idx];
                }
            }
            down -= 2;
            up += 2;
        }
        return answer;
    }
};