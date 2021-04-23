class Solution {
public:
    int myAtoi(string s) {
        int minus=1;
        long long INTMIN = -2147483648, INTMAX = 2147483647, answer = 0;
        int len = s.length();
        int i=0;
        while (i < len) {
            if (s[i] == ' ') i++;
            else if (s[i] == '-') {i++; minus = -1; break;}
            else if (s[i] == '+') {i++; break;}
            else if (s[i] >= '0' && s[i] <= '9') break;
            else return answer;
        }
        
        while (i < len) {
            if (s[i] >= '0' && s[i] <= '9') {
                answer = answer * 10 + (s[i] - '0'); i++;
                if (answer > INTMAX) break;
            }
            else break;
        }
        
        answer = answer * minus;
        if (INTMIN >= answer) answer = INTMIN;
        if (INTMAX <= answer) answer = INTMAX;
        return answer;
    }
};