class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low=1;
        
        int high = INT_MIN;
        
        for(auto x: piles)
            high = max(high, x);
        
        while(low<high){
            int mid = low + (high-low)/2;
            
            int timetaken = 0;
            
            for(auto x: piles){
                timetaken += ceil(1.0*x /mid);
            }
            
            if(timetaken > h){
                low = mid+1;
            } 
            else 
                high = mid;
        }
        
        return low;
        
    }
};