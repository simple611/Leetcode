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
    vector<string> ans;
    
    // TC - O(N)  SC- O(H)
    void findPaths(TreeNode* root, string t){
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL)
            ans.push_back(t+to_string(root->val));
        
        findPaths(root->left, t + to_string(root->val) + "->");
        findPaths(root->right, t + to_string(root->val) + "->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        findPaths(root, "");
        return ans;
    }
};