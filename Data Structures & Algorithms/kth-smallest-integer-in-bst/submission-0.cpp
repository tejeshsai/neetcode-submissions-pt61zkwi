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
    int count = 0;
    int inorder(TreeNode* node, int k){
        if(!node) return -1;
        int left=inorder(node->left, k);
        if(left!=-1) return left;
        count++;
        if(count == k) return node->val;
        int right = inorder(node->right, k);
        if(right!=-1) return right;
        return -1;

    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;

        return inorder(root, k);
    }
};
