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
    int maxDia = INT_MIN;

    int maxDepth(TreeNode* root){
        if(!root) return 0;

        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }

    void diameter(TreeNode* root){
        if(!root) return;

        int diameterCurr = maxDepth(root->left)+maxDepth(root->right);
        maxDia = max(maxDia, diameterCurr);

        diameter(root->left);
        diameter(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        diameter(root);
        return maxDia;
        
    }
};
