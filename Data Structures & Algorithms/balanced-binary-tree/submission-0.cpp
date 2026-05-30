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

    int dfs(TreeNode* root){
        if(!root) return 0;

        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        
        if(leftHeight == -1 || rightHeight == -1) return -1;
        
        if(abs(leftHeight-rightHeight)<=1) return 1+max(leftHeight, rightHeight);
        else return -1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        if(dfs(root)!=-1) return true;
        return false;
    }
};
 