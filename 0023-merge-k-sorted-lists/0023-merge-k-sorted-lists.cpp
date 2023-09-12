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
    
    typedef pair<int, ListNode*> pi;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
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
};