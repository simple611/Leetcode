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
    
    vector<int> nodes;
    
    void dfs(TreeNode* node){
        if(node == nullptr ) return;
        
        if(node->left) dfs(node->left);
        nodes.push_back(node->val);
        if(node->right) dfs(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        
        // sort(nodes.begin(), nodes.end());
        int minDiff = INT_MAX;
        cout<<nodes[0]<<endl;
        for(int i =1;i<nodes.size();i++){
            minDiff = min(minDiff, nodes[i] - nodes[i-1]);
            cout<<nodes[i]<<endl;
        }
        // minDiff = nodes[1] - nodes[0];
        return minDiff;
    }
};