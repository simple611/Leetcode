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
    void inorderTraversal(TreeNode *root, vector<int> &res)
    {
        if(root == nullptr)
            return;
        inorderTraversal(root->left, res);
        res.push_back(root->val);
        inorderTraversal(root->right, res);
            
    }
    vector<int> inorderTraversal(TreeNode* root) {
        //recursive
        // vector<int> res;
        // inorderTraversal(root, res);
        // return res;
        
        //Iterative
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while(cur != nullptr || !st.empty())
        {
            while(cur != nullptr)
            {
                st.push(cur);
                cur= cur->left;
            }
            
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            
            cur = cur->right;
        }
        return res;
    }
};