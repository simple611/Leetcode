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

static const bool init = []{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    return false;
}();

class Solution {
public:
    
    // TC - O(n)   SC - O(n)
    __attribute__((always_inline))
    int maxLevelSum(TreeNode* root) {
        int maxSum=INT_MIN;
        
        int res=0;
        int level=0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty()){
            level++;
            
            int sumAtCurLevel = 0;
            
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                sumAtCurLevel +=node->val;
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right){
                    q.push(node->right);
                }
            }
            
            if(maxSum < sumAtCurLevel)
            { maxSum = sumAtCurLevel;
             res = level;
            }
            
        }
        return res;
    }
};