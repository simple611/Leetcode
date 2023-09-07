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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int size = 0;
        
//         ListNode *tmp = head;
//         while(tmp != NULL)
//         {
//             size++;
//             tmp= tmp->next;
//         }
//         if(size<n)
//             return NULL;
        
//         tmp = head;
//         ListNode *prev = NULL;
//         for(int i=0;i<size-n;i++)
//         {
//             prev = tmp;
//             tmp = tmp->next;
//         }
//         if(prev == NULL)
//         {
//             head = NULL;
//             return head;
//         }
//         if(prev->next != NULL)
//             prev->next = prev->next->next;
//         else prev->next = NULL;
//         return head;
        
        ListNode *fast = head, *slow = head;
        for(int i=0;i<n;i++)
            fast=fast->next;
        
        //means head needs to be deleted
        if(fast == nullptr)
        {
            ListNode *del= head;
            head = head->next;
            delete del;
            return head;
        }
        
        while(fast->next != nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode *del = slow->next;
        slow->next = slow->next->next;
        delete del;
        return head;
    }
};