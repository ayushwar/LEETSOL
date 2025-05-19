// 131. Palindrome Partitioning
// 19/05/2025


class Solution {
public:
    bool ispalind(string s){
        string ss=s;
        reverse(ss.begin(),ss.end());
        return s==ss;
    }

    void checkcombination(string s, vector<vector<string>>& ans,
                          vector<string> combination) {
                            if(s.size()==0){
                                ans.push_back(combination);
                                return;
                            }


        for (int i = 0; i < s.size(); i++) {

            string part = s.substr(0, i + 1);
            if (ispalind(part)) {
                combination.push_back(part);
                checkcombination(s.substr(i+1), ans, combination);
                combination.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> combination;

        checkcombination(s, ans, combination);
        return ans;
    }
};
