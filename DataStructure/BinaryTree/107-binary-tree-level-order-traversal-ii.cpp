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
     void levelOrder(vector<vector<int>> &res, TreeNode *root, int level){
        if(root == nullptr)
            return;
        if(level >= res.size())
            res.push_back({});
        res[level].push_back(root->val);
        levelOrder(res,root->left, level+1);
        levelOrder(res,root->right, level+1);
    }
    void updatedlevelOrder(vector<vector<int>> &res, TreeNode *root, int level){
        if(root == nullptr)
            return;
        res[level].push_back(root->val);
        updatedlevelOrder(res,root->left, level-1);
        updatedlevelOrder(res,root->right, level-1);
    }
    int depth(TreeNode *root){
        if(!root)
            return 0;
        return max(depth(root->left), depth(root->right))+1;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
//         vector<vector<int>> res;
//         if(root == nullptr)
//             return {};
        
//         queue<TreeNode *> q;
//         q.push(root);
        
//         while(!q.empty()){
//             vector<int> midLevel;
//             int levelSize = q.size();
//             for(int i=0;i<levelSize;i++){
//                 TreeNode *t = q.front();
//                 q.pop();
//                 midLevel.push_back(t->val);
//                 if(t->left)
//                     q.push(t->left);
//                 if(t->right)
//                     q.push(t->right);
//             }
//             res.push_back(midLevel);
//         }
//         reverse(res.begin(),res.end());
//         return res;
        
        //REcursive 1
        // if(root== nullptr)
        //     return {};
        // vector<vector<int>> res;
        // levelOrder(res,root,0);
        // reverse(res.begin(),res.end());
        // return res;
        
        //recursive 2
        if(root== nullptr)
            return {};
        int d = depth(root);
        vector<vector<int>> res(d, vector<int>{});
        updatedlevelOrder(res,root,d-1);
        return res;
    }
};