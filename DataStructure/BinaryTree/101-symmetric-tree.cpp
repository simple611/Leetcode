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
    bool isSymUtil(TreeNode * a, TreeNode *b){
        
        if(a == nullptr || b==nullptr)
            return a==b;
        
        if(a->val != b->val)
            return false;
        
        return isSymUtil(a->left, b->right) && isSymUtil(a->right,b->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isSymUtil(root->left, root->right);
        
    }
};