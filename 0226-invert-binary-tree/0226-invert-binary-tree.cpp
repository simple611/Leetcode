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
    // TC - O(N)  SC - O(N)
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
    TreeNode* invertTree_old(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode *tempRight = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(tempRight);
        return root;
        
//         stack<TreeNode*> st;
//         st.push(root);
        
//         while(!st.empty()){
//             auto node = st.top();
//             st.pop();
            
//             TreeNode * tmp = node->right;
//             node->right = node->left;
//             node->left = tmp;
            
//             if(node->left)
//                 st.push(node->left);
//             if(node->right)
//                 st.push(node->right);
//         }
        
//         return root;
    }
};