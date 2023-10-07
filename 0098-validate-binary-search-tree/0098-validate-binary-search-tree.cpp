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
    bool validBST(TreeNode* root, TreeNode *low, TreeNode *high)
    {
        if(root == nullptr)
            return true;
        
        if((low != nullptr && root->val <= low->val) || (high != nullptr && root->val >= high->val))
            return false;
        
        return validBST(root->right, root, high) && validBST(root->left, low, root);
        
    }
    bool isValidBST_reursion(TreeNode* root) {
        return validBST(root, nullptr, nullptr);
    }
    
    bool isValidBST(TreeNode* root) {
                                                                                                                                                                                                                      
        TreeNode *prev = nullptr;
        TreeNode *cur = root;
        stack<TreeNode*> st;
        
        while(cur || !st.empty()){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            
            if(prev != nullptr && cur->val <= prev->val) return false;
            prev = cur;
            cur = cur->right;
        }
        return true;
    }
    
};