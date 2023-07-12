class Solution {
public:
    int getNextNum(int n){
        int ans=0;
        while(n>0){
            int d = n%10;
            n = n/10;
            ans += d*d;
        }
        return ans;
    }
    
    // TC - O(log n) SC- O(log n) 
    bool isHappy_mapSol(int n) {
        map<int,int> mp;
        
        while(n != 1){
            if(mp[n]==1)
                return false;
            else
                mp[n]++;
            int next = getNextNum(n);
            n = next;
            // mp[next]++;
        }
        return true;
        
    }
    
    // TC - O(log n) SC- O(1)  Floydd cycle detection algo
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = getNextNum(slow);
            fast = getNextNum(fast);
            fast = getNextNum(fast);
        } while(slow != fast);
        if (slow == 1) return 1;
        else return 0;
   }
};