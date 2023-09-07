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
    //TC - O(N)  SC- O(1)
    ListNode* reverseList_iterative(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *next = NULL;
        while(cur != NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    //TC - O(N)  SC- O(N)
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* prev = NULL;
        
        ListNode* head2 = reverseList(head->next);
        
        head->next->next = head;
        head->next = prev;
        return head2;
    }
    
};