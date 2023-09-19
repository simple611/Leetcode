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
    void preOrder(TreeNode* root, vector<int>&res, int lev){
        if(root == nullptr)
            return;
        if(res.size()<lev){
            res.push_back(root->val);
        }
        preOrder(root->right, res, lev+1);
        preOrder(root->left, res, lev+1);
    }
    
    // TC - O(N)  SC - O(H)  , O(N) for stack space
    vector<int> rightSideView_Recursive(TreeNode* root) {
        vector<int> res;
        preOrder(root, res, 0);
        return res;
    }
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int sz = q.size();
            
            for(int i=sz-1;i>=0;i--){
                TreeNode *node = q.front();
                q.pop();
                
                if(i == sz-1){
                    res.push_back(node->val);
                }
                
                if(node->right)
                    q.push(node->right);
                
                if(node->left)
                    q.push(node->left);
                
            }
            
        }
        return res;
    }
};