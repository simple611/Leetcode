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
    int search(vector<int>& inorder, int ele){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i] == ele)
                return i;
        }
        return -1;
    }
    TreeNode * build(vector<int>& inorder, vector<int>& postorder, int inStrt, int inEnd, int &postIdx){
        if(postIdx <0 || inStrt>inEnd)
            return nullptr;
        
        TreeNode *root = new TreeNode(postorder[postIdx--]);
        // int indx = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        // int indx= search(inorder, root->val);
        
        int indx = mp[root->val];
        
        root->right = build(inorder, postorder, indx+1, inEnd, postIdx);
        root->left = build(inorder, postorder, inStrt, indx-1, postIdx);
        return root;
    }
    
    // TC - O(N)   SC- O(N)
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postIdx = n-1;
        
        // Use unordered map to reduce search complexity
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return build(inorder, postorder, 0, n-1, postIdx);
    }
};