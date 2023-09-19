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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;
                if(root == NULL)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        
        bool isLtoR = true;   // true of even level no.
        
        while(!q.empty()){
            int size = q.size();
            vector<int> ansRow(size);
            
            for(int i=0;i<size;i++){
                TreeNode *tmp= q.front();
                q.pop();
                
                int index = (isLtoR) ? i : (size-1-i);
                ansRow[index] = tmp->val;
                
                if(tmp->left)
                    q.push(tmp->left);
                
                if(tmp->right)
                    q.push(tmp->right);
                
            }
            
            res.push_back(ansRow);
            isLtoR = !isLtoR;
        }
        
        return res;
        
    }
};