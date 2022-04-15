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
    // unordered_map<int, int> pre;
    unordered_map<int, int> post;
    
    TreeNode *build(vector<int>& preorder, vector<int>& postorder, int p1, int p2, int po1, int po2){
        if(p1>p2 || po1> po2)
            return nullptr;
        
        int val = preorder[p1];
        TreeNode *root = new TreeNode(val);
//         int t1 = preorder[p1+1];
//         int postIdx = post[t1];
        
//         int t2 = postorder[p2-1];
//         int preIdx = pre[t2];
        if(p1 == p2)
            return root;
        int postIdx = post[preorder[p1+1]];
        int len = postIdx - po1 +1;
        
        root->left = build(preorder, postorder, p1+1, p1+len, po1, postIdx);
        root->right = build(preorder, postorder, p1+len+1, p2, postIdx+1, po2-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int m = postorder.size();
        
        // for(int i=0;i<n;i++)
        //     pre[preorder[i]]=i;
        
        for(int i=0;i<m;i++)
            post[postorder[i]]=i;
        
        return build(preorder, postorder, 0, n-1, 0, m-1);
    }
};