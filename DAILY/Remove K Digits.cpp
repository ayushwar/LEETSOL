// 13/04/2025
 // vv

class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char> st;  // Stack to store digits while building the smallest number

        // Iterate through each digit in the string
        for (int i = 0; i < s.size(); i++) {
            // While the stack is not empty, we still need to remove digits,
            // and the top of the stack is greater than the current digit,
            // remove the top (greedily removing larger digits to get smaller number)
            while (!st.empty() && k > 0 && (st.top() - '0') > (s[i] - '0')) {
                st.pop();
                k--;
            }
            // Push current digit onto the stack
            st.push(s[i]);
        }

        // If we still have digits to remove (k > 0), remove from the end (top of the stack)
        if (k > 0) {
            while (k != 0) {
                st.pop();
                k--;
            }
        }

        // If the stack is empty, return "0" (all digits removed)
        if (st.empty()) return "0";

        // Build the result string from stack (in reverse order)
        string res = "";
        while (!st.empty()) {
             res.push_back(st.top()); // pushing stack top to string
              // Append each character from the stack
            st.pop();
        }

        // Reverse the result string since stack gives reversed order
        reverse(res.begin(), res.end());

        // Remove leading zeros
        int idx = 0;
        while (idx < res.size() && res[idx] == '0') {
            idx++;
        }
        res = res.substr(idx);  // Trim leading zeros

        // If the result is empty after removing zeros, return "0"
        if (res.empty()) return "0";

        // Return the final processed string
        return res;
    }
};
