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
    void postOrder(TreeNode * root, vector<int> &res)
    {
        if(root == nullptr)
            return;
        postOrder(root->left, res);
        postOrder(root->right, res);
        res.push_back(root->val);
    }
    
    vector<int> postorderTraversal_recur(TreeNode* root) {
        // recursive implementation
        vector<int> res;
        postOrder(root, res);
        return res;
        }
    vector<int> postorderTraversal_2stacks(TreeNode* root) {    
        // Iterative implementation
        
        vector<int> res;
        stack<TreeNode *> s1, s2;
        
        TreeNode *tmp = root;
        if(tmp == nullptr)
            return res;
        s1.push(tmp);
        while(!s1.empty())
        {
            TreeNode *t = s1.top();
            s1.pop();
            s2.push(t);
            if(t->left)
                s1.push(t->left);
            if(t->right)
                s1.push(t->right);
        }
        
        while(!s2.empty())
        {
            TreeNode *t2= s2.top();
            s2.pop();
            res.push_back(t2->val);
        }
        return res;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {    
        // Iterative implementation
        
        vector<int> res;
        stack<TreeNode *> st;
        
        TreeNode *cur = root;
        if(cur == nullptr)
            return res;
        
        while(cur != NULL || !st.empty()){
            if(cur != NULL){
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode * tmp = st.top()->right;
                 if(tmp != NULL){
                     cur = tmp;
                 } else {
                     tmp = st.top();
                     st.pop();
                     res.push_back(tmp->val);
                     
                     while(!st.empty() && tmp == st.top()->right){
                         tmp = st.top();
                         st.pop();
                         res.push_back(tmp->val);
                     }
                 }
            }
        }
        return res;
        }
    
};