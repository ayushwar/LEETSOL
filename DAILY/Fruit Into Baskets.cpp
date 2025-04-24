 // Fruit Into Baskets
// 24/04/2025
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int r = 0;
        int length = INT_MIN;
        unordered_map<int, int> mpp;

        while (r < fruits.size()) {
            mpp[fruits[r]]++;

            while (mpp.size() > 2) {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            if (mpp.size() <= 2) {
                length = max(length, r - l + 1);
            }
            r++;
        }

        return length;
    }
};
