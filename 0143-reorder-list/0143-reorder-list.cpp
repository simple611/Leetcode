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
    void reorderList(ListNode* head) {
        
        vector<int> tmp;
        
        ListNode* ptr = head;
        
        while(ptr != NULL){
            tmp.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        int l = 0;
        int h = tmp.size()-1;
        
        // ListNode *head = new ListNode();
        ListNode *ans = head; 
        while(l<h){
            // ans->next = new ListNode(tmp[l++]);
            // ans=ans->next;
            // ans->next = new ListNode(tmp[h--]);
            // ans = ans->next;
            ans->val = tmp[l++];
            ans = ans->next;
            ans->val = tmp[h--];
            ans = ans->next;
        }
        
        if(l == h){
            // ans->next = new ListNode(tmp[l]);
            ans->val = tmp[l];
            ans = ans->next;
        }
        
    }
};