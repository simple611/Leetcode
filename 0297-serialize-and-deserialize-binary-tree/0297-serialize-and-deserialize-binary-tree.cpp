/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    
    void preorderDFS(TreeNode* root, string& s){
        if(root == nullptr){
            s.append("#");
            return;
        }
        s.append(to_string(root->val)+",");
        preorderDFS(root->left,s);
        preorderDFS(root->right,s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        preorderDFS(root,s);
        return s;
    }

    TreeNode *decode(string& data){
        if(data.size() == 0)
            return nullptr;
        if(data[0] == '#'){
            data = data.substr(1);
            return nullptr;
        }
        string no="";
        int pos=0;
        while(data[pos] != ','){
            no+=data[pos++];
        }
        TreeNode* curNode = new TreeNode(stoi(no));
        data = data.substr(pos+1);
        curNode->left = decode(data);
        curNode->right = decode(data);
        return curNode;
        
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()<=1)
            return nullptr;
        return decode(data);
    }


};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));