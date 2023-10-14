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
    string serialize_old(TreeNode* root) {
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
    TreeNode* deserialize_old(string data) {
        if(data.size()<=1)
            return nullptr;
        return decode(data);
    }


    
    string serialize(TreeNode* root) {
        
        if(root == nullptr)
            return "N,";
        string left = serialize(root->left);
        string right = serialize(root->right);
        
        return to_string(root->val) + "," + left + right;
    }
    
    
    TreeNode* makeTree(istringstream& ss){
        
        string s;
        if(!getline(ss, s, ',') || s.empty())
            return NULL;
        // string s;
        // ss >> s;
        
        if(s == "N")
            return nullptr;
        
        TreeNode *newRoot = new TreeNode(stoi(s));
        newRoot->left = makeTree(ss);
        newRoot->right = makeTree(ss);
        return newRoot;
        
    }
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return makeTree(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));