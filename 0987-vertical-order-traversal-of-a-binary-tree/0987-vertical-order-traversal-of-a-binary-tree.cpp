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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;   // [dist][level] = val
        
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0,0}});  // {TreeNode*, {dist, level}}
        
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            int x = tmp.second.first;
            int y = tmp.second.second;
            
            mp[x][y].insert((tmp.first)->val);
            
            if(tmp.first->left)
                q.push({tmp.first->left, {x-1, y+1}});
            
            if(tmp.first->right)
                q.push({tmp.first->right, {x+1, y+1}});
        }
        
        for(auto x: mp){
            vector<int> col;
            
            for(auto a: x.second){
                for(auto ele: a.second){
                    col.push_back(ele);
                }
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};