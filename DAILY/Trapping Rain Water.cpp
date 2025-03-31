// 42
// 31/03/25
// 42. Trapping Rain Water

class Solution {
public:
    int trap(vector<int>& h) {
        int low=0;
        int high=h.size()-1;
        int ans=0;
        int lmax=0;
        int hmax=0;

        while(low<high){
            lmax=max(lmax,h[low]);
            hmax=max(hmax,h[high]);
            if(lmax<hmax){
                ans+=lmax-h[low];
                low++;

            }
            else{
                ans+=hmax-h[high];
                high--;
            }
        }
        return ans;
    }
};
