// Asteroid Collision
// 12/04/2025

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && st.top() > 0 && arr[i] < 0) {

                if (st.top() < -arr[i]) {
                    st.pop();
                    continue;
                } else if (st.top() == -arr[i]) {
                    st.pop();
                    goto skip; // goto is jump the line and goes to where skipis
                               // wriiten is
                } else {
                    goto skip;
                }
            }
            st.push(arr[i]);
        skip:; // when goto call it directly jump to this line
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
