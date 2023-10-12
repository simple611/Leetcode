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
    
    int maxPathS(TreeNode* root, int &maxPath){
        if(root == nullptr)
            return 0;
        
        // Ignore nodes with negative values in both left and right subtree
        int leftPath = max(0, maxPathS(root->left, maxPath));
        int rightPath = max(0, maxPathS(root->right, maxPath));
        
        maxPath = max(maxPath, leftPath + rightPath + root->val);
        
        return root->val + max(leftPath, rightPath);
    } 
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        maxPathS(root, maxPath);
        return maxPath;
            
    }
};