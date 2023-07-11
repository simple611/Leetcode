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
    unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
    unordered_map<TreeNode*, bool> visited;
    vector<int> result;
public:

    void findParent(TreeNode * root){
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) { /*First BFS to get a track of parent nodes*/
            TreeNode* current = queue.front(); queue.pop();
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
    
    void dfs( TreeNode* node, int K){
        if( visited[node])
            return;
        visited[node] = true;
        if( K == 0 ){
            result.push_back(node->val);
            return;
        }
        if( node->left ){
            dfs(node->left, K-1);
        }
        if( node->right){
            dfs(node->right, K-1);
        }
        TreeNode* p = parent_track[node];
        if( p )
            dfs(p, K-1);
    }
    
    void bfs(TreeNode* target, int K){
        queue<TreeNode*> queue; 
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            if(curr_level++ == K) break;
            for(int i=0; i<size; i++) {
                TreeNode* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParent(root);
        // bfs(target, k);
        dfs(target, k);
        return result;
    }
};