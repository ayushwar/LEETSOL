// 199. Binary Tree Right Side View
// 28/05/2025
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void order(TreeNode* root, int level, vector<int>& ans) {
        if (root == NULL) {

            return;
        }
        if (ans.size() == level)
            ans.push_back(root->val);
        order(root->right, level + 1, ans);
        order(root->left, level + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        order(root, 0, ans);
        return ans;
    }
};
