// combination sum II
// 16/05/2025
class Solution {
public:
    void checkcombination(vector<int>& arr, vector<vector<int>>& ans,
                          vector<int>& combine, int idx, int tar) {
        if (tar == 0) {

            ans.push_back(combine);

            return;
        }
        if (idx == arr.size() || tar < 0) {
            return;
        }
        for (int i = idx; i < arr.size(); i++) {

            if (i > idx && arr[i] == arr[i - 1])
                continue;

            combine.push_back(arr[i]);
            checkcombination(arr, ans, combine, i + 1, tar - arr[i]);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        sort(candidates.begin(), candidates.end());
        checkcombination(candidates, ans, combine, 0, target);
        return ans;
    }
};
