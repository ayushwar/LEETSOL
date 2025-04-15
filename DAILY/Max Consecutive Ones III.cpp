 // Max Consecutive Ones III
// 15/04/2025
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int leng = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int maxi = 0;
        int zero = 0;
        while (r < n) {
            if (nums[r] == 0)
                zero++;

            if (zero > k) {
                if (nums[l] == 0)
                    zero--;
                l++;
            }
            if (zero <= k) {
                leng = r - l + 1;
                maxi = max(leng, maxi);
            }
            r++;
        }
        return maxi;
    }
};
