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
    int ans =0;
    int max(int a , int b)
    {
        if(a>=b)
            return a;
        else
            return b;
            
    }
    void maxDepTop(TreeNode *root, int depth)
    {
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr)
        {
            ans = max(ans, depth);
        }
        maxDepTop(root->left, depth+1);
        maxDepTop(root->right, depth+1);
    }
    int maxDepBottom(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        int leftH = maxDepBottom(root->left);
        int rightH = maxDepBottom(root->right);
        int res = max(leftH, rightH) +1;
        return res;
    }
    // TC- O(N)  SC- O(N)
    int maxDepth(TreeNode* root) 
    {
        // return maxDepBottom(root);
        maxDepTop(root, 1);
        return ans;
    }
};