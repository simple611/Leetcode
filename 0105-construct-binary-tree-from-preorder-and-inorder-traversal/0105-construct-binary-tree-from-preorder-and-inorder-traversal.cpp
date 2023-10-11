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
    unordered_map<int, int> mp;
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int strtIdx, int endIdx, int &preIdx){
        if(strtIdx > endIdx)
            return nullptr;
        int val = preorder[preIdx++];
        TreeNode * root= new TreeNode(val);
        
        int idx = mp[val];
        
        root->left = build(preorder,inorder, strtIdx, idx-1, preIdx);
        root->right = build(preorder,inorder, idx+1, endIdx, preIdx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if (n==0)
            return nullptr;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int preIdx = 0;
        return build(preorder, inorder, 0, n-1, preIdx);
        
    }
};