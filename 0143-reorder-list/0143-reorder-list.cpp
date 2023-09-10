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
    
    // TC - O(N)  SC - O(N)
    void reorderList_array(ListNode* head) {
        
        vector<int> tmp;
        
        ListNode* ptr = head;
        
        while(ptr != NULL){
            tmp.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        int l = 0;
        int h = tmp.size()-1;
        
        ListNode *ans = head; 
        while(l<h){
            ans->val = tmp[l++];
            ans = ans->next;
            ans->val = tmp[h--];
            ans = ans->next;
        }
        
        if(l == h){
            ans->val = tmp[l];
            ans = ans->next;
        }
        
    }
    
    ListNode* reverse(ListNode *head){
        if(head == NULL|| head->next == NULL)
            return head;
        
        ListNode *prev = NULL;
        ListNode *cur = head;
        while(cur != NULL){
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        
        return prev;
    }
    
    void merge(ListNode* l1, ListNode* l2){
        
        while(l1){
            ListNode *p1 = l1->next;
            ListNode *p2 = l2->next;
            
            l1->next = l2;
            
            if(p1 == NULL){
                break;

            }
            l2->next = p1;
            l1 = p1;
            l2 = p2;
        }
    }
    
    void reorderList(ListNode *head){
        // Find middle node, split in half,
        // Reverse 2nd half of list,
        // Merge both list
        
        
        // Edge case
        if(head == NULL || head->next == NULL )
            return ;
        
        // find middle node
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        while(fast && fast->next!= NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        ListNode* l1 = head;
        ListNode* l2 = reverse(slow);
        
        merge(l1, l2);
        
    }
};