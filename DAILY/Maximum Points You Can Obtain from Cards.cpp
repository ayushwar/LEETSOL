// Maximum Points You Can Obtain from Cards
// 28/04/2025
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lmax = 0;
        int rmax = 0;

        for (int i = 0; i < k; i++) {
            lmax += nums[i];
        }
        int maxi = lmax;
        int r = nums.size() - 1;
        for (int i = k - 1; i >= 0; i--) {
            lmax -= nums[i];
            rmax += nums[r];
            r--;
            maxi = max(maxi, (lmax + rmax));
        }
        return maxi;
    }
};
