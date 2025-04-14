// 13/04/2025
class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int> st;         // Stack to store indices of histogram bars
        int maxi = 0;          // Variable to store the maximum area found
        int n = nums.size();   // Total number of bars in histogram

        // Traverse each bar in the histogram
        for (int i = 0; i < nums.size(); i++) {
            // Jab tak stack empty nahi hai aur current height chhoti hai top of stack se
            // Tab tak hum stack ke top element ke liye area calculate karenge
            while (!st.empty() && nums[st.top()] > nums[i]) {
                int ele = st.top();    // Index of the height being processed
                st.pop();              // Remove it from the stack

                int nse = i;           // Next smaller element is the current index
                int pse = st.empty() ? -1 : st.top(); // Previous smaller element

                // Area = height * width
                // Width = nse - pse - 1
                maxi = max(maxi, (nse - pse - 1) * nums[ele]);
            }
            st.push(i);  // Push current index to stack
        }

        // Abhi bhi agar stack mein elements bache hain, unka area calculate karna hoga
        while (!st.empty()) {
            int nse = n;             // End of array is next smaller
            int ele = st.top();      // Index of element
            st.pop();

            int pse = st.empty() ? -1 : st.top(); // Previous smaller element

            // Area calculation same as before
            maxi = max(maxi, (nse - pse - 1) * nums[ele]);
        }

        return maxi;  // Final maximum area
    }
};
