// Count Number of Nice Subarrays
// 27/04/2025

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return oddarr(nums ,k)- oddarr(nums ,k-1);
        
    }


    int oddarr(vector<int>& nums, int k){
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        while(r<nums.size()){
            sum+=nums[r]%2;

            while(sum>k){
                sum-=nums[l]%2;
                l++;
            }
            cnt+=r-l+1;
            r++;

        }
        return cnt;
    }
};
