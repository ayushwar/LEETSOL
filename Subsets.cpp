// 03/05/2025

// Subsets//
class Solution {
public:
    vector<vector<int>> func(vector<int> nums, int ind, vector<vector<int>> ans,
                             vector<int> temp) {

        if (ind >= nums.size()) {
            ans.push_back(temp);
            return ans;
        }
        temp.push_back(nums[ind]);
        ans = func(nums, ind + 1, ans, temp);
        temp.pop_back();
        ans = func(nums, ind + 1, ans, temp);
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        return func(nums, 0, ans, temp);
    }
};
