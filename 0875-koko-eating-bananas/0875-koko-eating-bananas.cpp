class Solution {
public:
    
    // TC - O(N log)
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low=1;
        
        int high = INT_MIN;
        
        for(auto x: piles)
            high = max(high, x);
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            long int timetaken = 0;
            
            for(auto x: piles){
                timetaken += ceil((double)x /mid);
            }
            
            if(timetaken > h){
                low = mid+1;
            } 
            else 
                high = mid-1;
        }
        
        return low;
        
    }
};