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
    // Array + sorting 
    // TC: O(nlog n) SC- O(n)
    ListNode* mergeKLists_array(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return NULL;
        
        vector<pair<int, ListNode*>> arr;
        
        for(int i=0;i<k;i++){
            ListNode *curNode = lists[i];
            
            while(curNode != NULL){
                arr.push_back({curNode->val, curNode});
                curNode = curNode->next;
            }
        }
        
        if(arr.size() == 0)
            return NULL;
        
        sort(arr.begin(), arr.end());
        
        for(int i=0;i<arr.size() - 1;i++){
            arr[i].second->next = arr[i+1].second;
        }
        
        arr[arr.size()-1].second->next = NULL;
        
        return arr[0].second;
    }
    
    // priority_queue minHeap 
    // TC: O(nlog k) SC- O(k)
    typedef pair<int, ListNode*> pi;
    ListNode* mergeKLists_priorityqueue(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return NULL;
        
        priority_queue<pi, vector<pi>, greater<pi>> minHeap;
        
        for(int i=0;i<k;i++){
            ListNode *curNode = lists[i];
            
            if(curNode != NULL){
                minHeap.push({curNode->val, curNode});
            }
        }
        
        if(minHeap.size() == 0) return NULL;
        
        ListNode *head = new ListNode();
        ListNode *cur = head;
        
        while(!minHeap.empty()){
            
            ListNode *tmp = minHeap.top().second;
            minHeap.pop();
            
            if(tmp->next != NULL){
                minHeap.push({tmp->next->val, tmp->next});
            }
            
            cur->next = tmp;
            cur = cur->next;
        }
        
        cur->next = NULL;
        
        return head->next;
    }
    
    ListNode *merge(ListNode * l1, ListNode *l2){
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
    // Using 2 pointers and merge sort for sorted list
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if( k == 0) return NULL;
        
        // int start = 0, end = k-1;
        
        while(k>1){
            
            for(int i = 0;i<k/2;i++){
                lists[i] = merge(lists[i], lists[k-i-1]);
            }
            k= (k+1)/2;
        }
        
        return lists.front();
        
    }
    
};