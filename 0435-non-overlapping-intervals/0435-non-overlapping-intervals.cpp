class Solution {
public:
    
    // TC - O(nlogn)   SC - O(1)
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>&a, vector<int>&b){ 
            return a[1]<b[1];
        });
        
        
        int ans = -1;
        vector<int> prev = intervals[0];
        
        for(auto interval: intervals){
            if(interval[0]< prev[1]){
                ans++;
            } else{
                prev = interval;
            }    
        }
        
        return ans;
    }
};