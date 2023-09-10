/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        
        Node *head1 = new Node(0);
        Node *tmp = head;
        
        //traversing to create new node for node in original list
        while(tmp != NULL){
            
            Node *x = new Node(tmp->val);
            mp[tmp] = x;
            tmp=tmp->next;
        }
        
        // populate next and random ptr;
        tmp = head;
        
        Node *tmp1 = head1;
        while(tmp != NULL){
            Node *newNode = mp[tmp];
            
            newNode-> next = mp[tmp->next];
            newNode->random = mp[tmp->random];
            tmp1->next = newNode;
            tmp1= tmp1->next;
            tmp = tmp->next;
        }
        
        return head1->next;
    }
};