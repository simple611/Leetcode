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
    Node* copyRandomList_hashmap(Node* head) {
        unordered_map<Node*, Node*> mp;
        
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
    
     Node* copyRandomList(Node* head) {
         if(head == NULL ) return head;
         
         Node *tmp = head;
         
         // Step 1: Create a node and insert in between each original node
         while(tmp != NULL){
             Node *newNode = new Node(tmp->val);
             
             newNode->next = tmp->next;
             tmp->next = newNode;
             tmp = tmp->next->next;  // or tmp = newNode->next
         }
         
         // Step 2: Update random pointer of new nodes
         
         tmp = head;
         
         while(tmp!= NULL){
             if(tmp->random){
                 tmp->next->random = tmp->random->next;  // Since we need to point to newly created node so tmp->random->next
             }
             tmp = tmp->next->next;
         }
         
         // Step 3: Remove old nodes
         
         Node *oldHead = head;
         Node *newHead = head->next;
         
         Node *curOld = oldHead;
         Node *curNew = newHead;
         
         while(curOld){
             curOld->next = curOld->next->next;
             
             curNew->next =  curNew->next ? curNew->next->next : NULL;
             curOld = curOld->next;
             curNew = curNew->next;
         }
         
         return newHead;
         
     }
};