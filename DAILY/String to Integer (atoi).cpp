// String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/description/
// 02/05/2025

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1; // default positive
        int i = 0;
        int ans = 0;

        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        if (i < s.size() && s[i] == '-') {
            sign = -1;
            i++;
        } else if (i < s.size() && s[i] == '+') {
            sign = 1;
            i++;
        }

        while (i < s.size()) {
            if (s[i] >= '0' && s[i] <= '9') {
                int digit = s[i] - '0';

                if (ans > (INT_MAX - digit) / 10) {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }

                ans = ans * 10 + digit;
                i++;
            } else {
                break;
            }
        }

        return ans * sign;
    }
};
