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
    
    int ans;
    // TC - O(N)  SC- O(N)
    void dfs(TreeNode* root, int curMax){
        if(root== NULL)
            return;
        
        if(root->val >= curMax){
            ans++;
            curMax = root->val;
        }
        
        dfs(root->left, curMax);
        dfs(root->right, curMax);
    }
    int goodNodes(TreeNode* root) {
        ans = 0;
        dfs(root, root->val);
        return ans;
    }
};