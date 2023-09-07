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
    /*
    void print(ListNode *head)
    {
        ListNode *tmp =head;
        while(tmp != nullptr)
        {
            cout<<tmp->val<<" ";
            tmp = tmp->next;
        }
        cout<<"\n";
    }
    ListNode * insertAtTail(ListNode *head, int val)
    {
        ListNode *tmp = new ListNode(val);
        if(head == nullptr)
            return tmp;
        
        ListNode *cur = head;
        while(cur->next != nullptr)
        {
            cur= cur->next;
        }
        cur->next = tmp;
        return head;
    }*/
    
    // TC - O(M+N)  SC- O(1)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode *t1= l1, *t2= l2, *t3=nullptr;
//         if(t1 == nullptr)
//             return t2;
//         if(t2 == nullptr)
//             return t1;
        
//         while(t1 != nullptr && t2 != nullptr)
//         {
//             if(t1->val <= t2->val)
//             {
//                 t3= insertAtTail(t3, t1->val);
//                 // cout<<"t1"<<endl;
//                 // print(t3);
//                 t1=t1->next;
//             }
//             else
//             {
//                 t3=insertAtTail(t3, t2->val);
//                 // cout<<"t2"<<endl;
//                 // print(t3);
//                 t2= t2->next;
//             }
//         }
//         while(t1 != nullptr)
//         {
//             t3=insertAtTail(t3, t1->val);
//             // cout<<"t1 1"<<endl;
//             // print(t3);
//             t1= t1->next;
//         }
//         // print(t2);
//         while(t2 != nullptr)
//         {
//             t3=insertAtTail(t3, t2->val);
//             // cout<<"t2 1"<<endl;
//             // print(t3);
//             t2 = t2->next;
//         }
//         return t3;
        
        ListNode *t3 = new ListNode();
        ListNode *head_t3 = t3;
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        
        while(l1!= nullptr && l2 != nullptr)
        {
            if(l1->val <= l2->val)
            {
                t3->next = l1;
                l1=l1->next;
            }
            else
            {
                t3->next = l2;
                l2= l2->next;
            }
            t3 = t3->next;
        }
        if(l1)
        {
            t3->next =l1;
        }
        if(l2)
        {
            t3->next = l2;
        }
        return head_t3->next;
        
    }
};