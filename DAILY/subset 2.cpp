// subset 2
// 17/05/2025

class Solution {
public:
    set<vector<int>> st;

    void checkcombination(vector<vector<int>>& ans, vector<int>& nums,
                          vector<int> combine, int idx) {

                            ans.push_back(combine);

                            for(int i=idx;i<nums.size();i++){
                                if(i>idx && nums[i]==nums[i-1])continue;

                                combine.push_back(nums[i]);
                                checkcombination(ans,nums,combine,i+1);
                                combine.pop_back();
                            }
  
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> combine;
        checkcombination(ans, nums, combine, 0);
        return ans;
    }
};
