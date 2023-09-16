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
    
    int height(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int lH = height(root->left);
        if(lH == -1)  
            return -1;
        
        int rH = height(root->right);
        if(rH == -1)
            return -1;
        
        if(abs(lH - rH) > 1) 
            return -1;
        
        return 1 + max(lH, rH);
    }
    
    // TC - O(N)   SC- O(N)
    bool isBalanced1(TreeNode* root) {
        return height(root) != -1;
    }
    
    int heightTree(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int lh = heightTree(root->left);
        int rh = heightTree(root->right);
        
        return max(lh, rh) +1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        
        if(abs(heightTree(root->left) - heightTree(root->right)) > 1)
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
    }
};