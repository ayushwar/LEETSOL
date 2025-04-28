// 28/04/2025
// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/solutions/6695618/approach-for-the-given-code-by-ayushwar-eazy/




class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l=0;
        int r=0;
        
        long long sum=0;
        long long cnt=0;

        while(r<nums.size()){
            sum+=nums[r];
            // len=;

         

            while(sum*(r-l+1)>=k){
                sum-=nums[l];
                l++;
                
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
};
