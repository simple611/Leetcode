/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//     TreeNode* ans = nullptr;
//     bool recurseTree(TreeNode *curNode, TreeNode* p, TreeNode* q){
//         if(ans != nullptr)
//             return false;
        
//         if(curNode == nullptr)
//             return false;
        
//         int left = recurseTree(curNode->left, p, q)? 1:0;
//         int right = recurseTree(curNode->right, p, q)?1:0;
        
//         int mid = (curNode == p || curNode == q) ?1:0;
        
//         if(mid+left+right >=2)
//             ans = curNode;
        
//         return (mid+left+right >0);
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         recurseTree(root, p, q);
//         return ans;
//     }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        if(root == p || root ==q)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left == nullptr)
            return right;
        else if(right == nullptr)
            return left;
        else return root;
    }
};