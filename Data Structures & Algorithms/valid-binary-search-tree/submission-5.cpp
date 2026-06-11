/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool dfs(TreeNode* node, int lowerlimit, int upperlimit){
        if(!node) return true;
        cout << node->val;
        if(node->val <= lowerlimit || node->val >= upperlimit) return false;
        return dfs(node->left, lowerlimit, node->val) &&
               dfs(node->right, node->val, upperlimit);
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        return dfs(root, INT_MIN, INT_MAX);
    }
};
