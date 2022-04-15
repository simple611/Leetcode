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
    
    
    TreeNode* searchBST(TreeNode* root, int val) {
        
        //REcursive
//         if(root== nullptr)
//             return nullptr;
        
//         TreeNode *node;
//         if(root->val == val)
//             node=root;
//         else if(root->val < val)
//             node = searchBST(root->right, val);
//         else
//             node = searchBST(root->left, val);
//         return node;
        
        //Iterative
        
        if(root == nullptr)
            return root;
        while(root && root->val != val){
            if(root->val < val)
                root= root->right;
            else if (root->val > val)
                root = root->left;
        }
        return root;
       
    }
};