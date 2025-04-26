// Binary Subarrays With Sum
//26/04/2025

class Solution {
public:

    int atMost(vector<int>& nums, int goal){
         int l = 0, r = 0;
        int count = 0;
        int sum = 0;

        while (r < nums.size()) {
            sum += nums[r];

            while (l <= r && sum > goal) {
                sum -= nums[l];
                l++;
            }

      
            count+=(r-l+1);
            r++;
        }

        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
         return atMost(nums, goal) - atMost(nums, goal - 1);
       
    }
};
