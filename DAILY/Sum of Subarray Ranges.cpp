// Sum of Subarray Ranges
// 12/04/2025

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();

        // Arrays to store left/right contribution for min and max
        vector<long long> min_l(n, 0); // # of elements to the left (including self) where current is min
        vector<long long> max_l(n, 0); // # of elements to the left (including self) where current is max
        vector<long long> min_r(n, 0); // # of elements to the right (including self) where current is min
        vector<long long> max_r(n, 0); // # of elements to the right (including self) where current is max

        // ===============================
        // Step 1: Compute min_l (Left span for minimum)
        // ===============================
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            // If stack is empty, entire range [0...i] is valid
            min_l[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        // Clear stack for next use
        st = stack<int>();

        // ===============================
        // Step 2: Compute min_r (Right span for minimum)
        // ===============================
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            // If stack is empty, valid till end of array
            min_r[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        // Clear stack for max calculations
        st = stack<int>();

        // ===============================
        // Step 3: Compute max_l (Left span for maximum)
        // ===============================
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            max_l[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        // Clear stack for next max
        st = stack<int>();

        // ===============================
        // Step 4: Compute max_r (Right span for maximum)
        // ===============================
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            max_r[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        // ===============================
        // Step 5: Calculate the final result
        // For each element, calculate:
        // (contribution as max) - (contribution as min)
        // ===============================
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long max_contrib = max_l[i] * max_r[i];
            long long min_contrib = min_l[i] * min_r[i];
            ans += (long long)nums[i] * (max_contrib - min_contrib);
        }

        return ans;
    }
};
