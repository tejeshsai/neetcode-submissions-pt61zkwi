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
    unordered_map<int,int> inorderIndex;

    TreeNode* dfs(int& preIndex,int inLeft,int inRight, vector<int>& preorder, vector<int>& inorder){
        if(inLeft > inRight) return nullptr;
        TreeNode* node = new TreeNode(preorder[preIndex]);
        
        int rootInInorder = inorderIndex[preorder[preIndex]];
        preIndex++;
        node->left = dfs(preIndex, inLeft, rootInInorder-1, preorder, inorder);
        node->right = dfs(preIndex, rootInInorder+1, inRight, preorder, inorder );

        return node;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        
        for(int i=0;i<inorder.size(); i++){
            inorderIndex[inorder[i]] = i;
        }

        int preIndex = 0;
        int inLeft = 0;
        int inRight = inorder.size()-1;
        return dfs(preIndex , inLeft, inRight, preorder, inorder);
    }
};
