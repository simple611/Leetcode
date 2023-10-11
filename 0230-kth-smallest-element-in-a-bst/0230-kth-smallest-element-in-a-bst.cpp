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
    // TC - O(N)  SC - O(N)
    void inorder(TreeNode* root, vector<int>& res){
        if(root == nullptr)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    
    
    void inorder_optimized(TreeNode* root, int &k, int &res){
        if(root == nullptr)
            return;
        
        inorder_optimized(root->left, k, res);
        k--;
        if(k == 0){
            res = root->val;
            return;
        }
        inorder_optimized(root->right, k, res);
    }
    int kthSmallest_inorder(TreeNode* root, int k){
        vector<int> res;
        inorder(root, res);
        return res[k-1];
    }
    
    int kthSmallest(TreeNode* root, int k){
        int res;
        inorder_optimized(root, k, res);
        return res;
    }
};