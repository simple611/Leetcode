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
    ListNode* partition(ListNode* head, int x) {
        ListNode *beforeHead = new ListNode(0);
        ListNode *afterHead = new ListNode(0);
        ListNode *beforePtr = beforeHead;
        ListNode *afterPtr = afterHead;
        
        while(head != nullptr){
            if(head->val < x){
                beforePtr->next = head;
                beforePtr = beforePtr->next;
            } else {
                afterPtr->next = head;
                afterPtr = afterPtr->next;
            }
            head = head->next;
        }
        afterPtr->next = nullptr;
        
        beforePtr->next = afterHead->next;
        return beforeHead->next;
    }
};