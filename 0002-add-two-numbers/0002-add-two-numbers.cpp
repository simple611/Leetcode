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
    /*ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head;
        ListNode *sum = new ListNode();
        head = sum;
        int s=0;
        int carry=0;
        while(l1 && l2){
            s = l1->val + l2->val + carry;
            if(s <10){
                carry = 0;
                sum->next = new ListNode(s);
            }
            else{
                sum->next = new ListNode(s%10);
                carry = s/10;
            }
            l1 = l1->next;
            l2= l2->next;
            sum = sum->next;
        }
        while(l1){
            s = l1->val + carry;
            if(s < 10){
                carry = 0;
                sum->next = new ListNode(s);
            }
            else{
                sum->next = new ListNode(s%10);
                carry = s/10;
            }
            l1 = l1->next;
            sum = sum->next;
        }
        while(l2){
            s= l2->val + carry;
            if(s<10){
                carry = 0;
                sum->next = new ListNode(s);
            }
            else{
                sum->next = new ListNode(s%10);
                carry = s/10;
            }
            l2= l2->next;
            sum = sum->next;
        }
        if(carry !=0)
            sum->next = new ListNode(carry);
        return head->next;
    }
    */
    
    // TC - O(max(l1,l2))   SC - O(max(l1,l2))
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
        ListNode *head = new ListNode();
        ListNode *sum = head;
        
        int carry = 0;
        int s=0;
        
        while(l1 != nullptr || l2 != nullptr || carry){
            s=0;
            if(l1){
                s= s+l1->val;
                l1=l1->next;
            }
            if(l2){
                s = s+l2->val;
                l2=l2->next;
            }
            s= s+ carry;
            carry = s/10;
            sum->next = new ListNode(s%10);
            sum = sum->next;        
        }
        return head->next;
    }
};