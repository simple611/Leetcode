/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    // TC - O(N)   SC- O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1)
            return head;
        
        ListNode *dummy = new ListNode();
        dummy->next = head;
        
        ListNode *cur = head;
        
        int count = 0;
        while(cur){
            count++;
            cur = cur->next;
        }
        
        int numOfGroups = count/k;
        
        ListNode *prev = NULL;
        cur = head; 
        
        ListNode *start = dummy, *remaining;
        for(int i=0;i<numOfGroups;i++){
            prev = NULL;
            remaining = cur;
            
            for(int i=0;i<k;i++){
                ListNode *nex = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nex;
            }
            
            start->next = prev;
            remaining->next = cur;
            start = remaining;
            
        }
        
        return dummy->next;
    }
};