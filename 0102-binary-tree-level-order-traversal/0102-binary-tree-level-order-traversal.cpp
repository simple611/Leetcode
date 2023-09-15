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
   
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        // Iterative Solution
        
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            int levelNum = q.size();
            for(int i=0;i<levelNum;++i)
            {
                TreeNode *tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                
            }
            res.push_back(level);
            
        }
        return res;
        
        
        
    }
};