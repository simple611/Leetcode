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
    void preOrderRecur(vector<int> &res, TreeNode* root){
        if(root == nullptr)
            return ;
        res.push_back(root->val);
        preOrderRecur(res,root->left);
        preOrderRecur(res, root->right);
    }
    // TC - O(N)  SC- O(N)
    vector<int> preorderTraversal_REcur(TreeNode* root) {
        
        // REcursive
        if(root== nullptr)
            return {};
        vector<int> res;
        preOrderRecur(res, root);
        return res;
    }
    
    // TC - O(N)  SC- O(N)
    vector<int> preorderTraversal(TreeNode* root) {
        
       // Iterative
        vector<int> res;
        stack<TreeNode *> st;
        if(root == nullptr)
            return {};
        st.push(root);
        
        while(!st.empty()){
            TreeNode *node = st.top();
            if(node != nullptr)
                res.push_back(node->val);
            st.pop();
            if(node->right)
                st.push(node->right);
            if(node->left)
                st.push(node->left);
        }
        return res;
        }
};