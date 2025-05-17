// combination sum III
// 17/05/2025

class Solution {
public:
    void checkcombination(vector<int>& nums, vector<vector<int>>& ans,
                          vector<int> combine, int len, int tar, int idx) {

        if (len == 0 && tar == 0) {
            ans.push_back(combine);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (len <= 0)
                break;
            if (tar - nums[i] < 0)
                break;

            combine.push_back(nums[i]);
            checkcombination(nums, ans, combine, len - 1, tar - nums[i],
                             i + 1);
            combine.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> combine;
        vector<vector<int>> ans;
        if (k > n)
            return ans;
        checkcombination(nums, ans, combine, k, n, 0);

        return ans;
    }
};
