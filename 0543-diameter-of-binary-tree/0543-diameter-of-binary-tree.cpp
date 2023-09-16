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
        int lh = height(root->left);
        int rh = height(root->right);
        
        return 1 + max(lh,rh);
        
    }
    
    // TC - O(N * H )  --> Worst case O(N^2)
    // SC - O(N)
    int diameterOfBinaryTree_brute(TreeNode* root) {
        if( root == NULL)
            return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        int maxPath = lh+rh;
        
        int maxLeft = diameterOfBinaryTree(root->left);
        int maxRight = diameterOfBinaryTree(root->right);
        
        return max(maxPath, max(maxLeft, maxRight));   
    }
    
    int helpDia(TreeNode * root, int &maxDia){
        if(root == NULL) return 0;
        
        int lh = helpDia(root->left, maxDia);
        int rh = helpDia(root->right, maxDia);
        
        maxDia = max(maxDia, lh+rh);
        
        return 1 + max(lh,rh);
    }
    // TC - O(N)  SC - O(N)
    int diameterOfBinaryTree(TreeNode* root) {
         if(root == NULL) return 0;
         int maxDia = INT_MIN;
         helpDia(root, maxDia);
         return maxDia;
     }
    
};