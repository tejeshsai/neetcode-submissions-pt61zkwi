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

    int globalMax = INT_MIN;
    int dfs(TreeNode* node){
        if(!node) return 0;

        int left = dfs(node->left);
        left = left > 0? left : 0;
        int right = dfs(node->right);
        right = right>0?right:0;

        globalMax = max(left+node->val+right, globalMax);
        
        return max(node->val+left, node->val+right);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return globalMax;
    }
};
