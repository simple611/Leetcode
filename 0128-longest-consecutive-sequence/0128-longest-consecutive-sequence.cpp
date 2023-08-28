class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        
        // TC - O(nlogn)  SC - O(1)
//         int n = nums.size();
//         if( n==0) return 0;
        
//         sort(nums.begin(), nums.end());
        
//         int longestS=0;
//         int curC=1;
//         for(int i=1;i<n;i++){
//             if(nums[i] != nums[i-1]){
//                 if(nums[i] == nums[i-1]+1){
//                     curC+=1;
//                 } else {
//                     longestS = max(longestS, curC);
//                     curC = 1;
//                 }
//             }
//         }
//         return max(longestS, curC);
        
        
        int n = nums.size();
        if(n==0) return 0;
        
        sort(nums.begin(), nums.end());
        
        int prev = nums[0];
        int count = 1;
        int largest = 1;
        
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]+1){
                count++;
                prev = nums[i];
            } else if( nums[i] != prev){
                count = 1;
                prev = nums[i];
            }    
            largest = max(largest, count);
        }
        return largest;
        
        
        
//         // TC - O(n)  SC - O(n)
//         int n = nums.size();
//         if(n==0) return 0;
        
//         unordered_set<int> uSet(begin(nums), end(nums)); 
// 	    int longestS = 0;
// 	    for(auto& num : uSet) {
// 		    int curC = 1;
// 		// find consecutive elements in the backward and forward direction from num
// 		    for(int j = 1; uSet.count(num - j); j++) uSet.erase(num - j), curC++;
// 		    for(int j = 1; uSet.count(num + j); j++) uSet.erase(num + j), curC++;
// 		    longestS = max(longestS, curC);  // update longest to hold longest consecutive sequence till now
// 	    }
// 	    return longestS;
        
    }
};