// Next Greater Element II
// 08/04/2025/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        stack<int> st;
        int n = nums.size();
        vector<int> temp(n, -1);

        for (int i = 2 * (n - 1); i >= 0; i--) {
            while (st.size() > 0 && nums[i % n] >= st.top()) {
                st.pop();
            }
            if (!st.empty()) {
                temp[i % n] = st.top();
            }
            st.push({nums[i % n]});
        }
        return temp;
    }
};
