// Valid Parentheses
// 03/04/2025
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.size() == 0)
                    return false;

                if ((s[i] == '}' && st.top() == '{') ||
                    (s[i] == ']' && st.top() == '[') ||
                    (s[i] == ')' && st.top() == '(')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};
