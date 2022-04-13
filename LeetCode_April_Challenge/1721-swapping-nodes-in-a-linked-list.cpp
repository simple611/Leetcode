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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *s = head;
        ListNode *f = head;
        ListNode *res=head;
        
        for(int i=1;i<k;i++){
            s=s->next;
        }
        ListNode *first = s;
        
        while(s->next!= nullptr){
            s=s->next;
            f=f->next;
        }
        
        int tmp = first->val;
        first->val = f->val;
        f->val = tmp;
        return res;
    }
};