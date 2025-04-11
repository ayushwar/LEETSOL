// Sum of Subarray Minimums
// 11/04/2025
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n,-1);
        vector<int>right(n,n);
        stack<int>st;
        long long ans=0;
        int mod = (int) 1e9 + 7;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i] ){
                st.pop();
            }
            if(!st.empty()){
                left[i]=st.top();
            }
            st.push(i);

        }
        st= stack<int>();

        for(int i=n-1;i>=0;--i){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=st.top();
            }
            st.push(i);

        }
        for(int i=0;i<n;i++)
        {
            ans+=(long)((i-left[i])*(right[i]-i))%mod*arr[i]%mod;
            ans%=mod;

        }
        return ans;
    }
};
