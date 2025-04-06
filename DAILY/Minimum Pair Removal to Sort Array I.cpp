// Minimum Pair Removal to Sort Array I
// 05/04/2025
class Solution {
public:
    bool check(vector<int> nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i])
                return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int oper = 0;
        while (!check(nums)) {
            int mini = INT_MAX;
            int index = -1;
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < mini) {
                    mini = sum;
                    index = i;
                }
            }
            vector<int> temp;
            for (int i = 0; i < nums.size(); i++) {
                if (i == index) {
                    temp.push_back(nums[i] + nums[i + 1]);
                    i++;
                } else {
                    temp.push_back(nums[i]);
                }
            }
            nums = temp;
            ++oper;
        }
        return oper;
    }
};
