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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        if(!root) return res;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* node = q.front();
                if(node == nullptr){
                    res+=".#";
                    q.pop();
                    continue;
                } 
                else res+=to_string(node->val)+"#";

                q.pop();

                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        vector<string> tokens;
        string token = "";
        for(int i=0;i<data.size();i++){
            if(data[i]!='#'){
                token+=data[i];
            }else{
                tokens.push_back(token);
                token = "";
            }
        }

        TreeNode* root = new TreeNode(stoi(tokens[0]));

        queue<TreeNode*> q;
        q.push(root);

        int index =1 ;

        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* node = q.front();

                q.pop();

                if(tokens[index]=="."){
                    node->left = nullptr;
                }else{
                    node->left = new TreeNode(stoi(tokens[index]));
                    q.push(node->left);
                }
                index++;
                if(tokens[index]=="."){
                    node->right = nullptr;
                }else{
                    node->right = new TreeNode(stoi(tokens[index]));
                    q.push(node->right);
                }
                index++;
            }

        }
        return root;

    }
};
