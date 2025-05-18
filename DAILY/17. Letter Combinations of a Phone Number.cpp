// 17. Letter Combinations of a Phone Number
// 19/05/2025

class Solution {
public:

    void checkcombination(string digit,vector<string>&nums, vector<string>&ans,string combine,int idx){
        if(idx>=digit.size()){
            ans.push_back(combine);
            return;
        }
        int no=digit[idx]-'0';
        string value=nums[no];
        for(int i=0;i<value.size();i++){
            combine.push_back(value[i]);
            checkcombination(digit,nums,ans,combine,idx+1);
            combine.pop_back();

        }

    }



    vector<string> letterCombinations(string digit) {
          vector<string> ans;
          string combine;
          vector<string>nums={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
          if(digit.size()==0)return ans;
          
          checkcombination(digit,nums,ans,combine,0);
          return ans;

        
    }
};
