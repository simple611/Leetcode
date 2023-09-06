class Solution {
public:
    // TC - O(log n)
    int searchInsert(vector<int>& arr, int x) {
        
//         int l= 0;
//         int h = nums.size() -1;
//         int m;
        
//         while(l<=h){
//             m = l + (h-l)/2;
//             if(nums[m] == target)
//                 return m;
//             else if(nums[m] < target)
//                 l = m+1;
//             else
//                 h= m-1;
//             }
//         return l;
        
//     int n = arr.size();
//     int low = 0, high = n-1;
// 	int ans = n;


// 	while(low <= high){
// 		int mid = low + (high-low)/2;

// 		if(arr[mid] >= x){
// 			// look for small index in left
// 			ans = mid;
// 			high = mid - 1;
// 		} else {
// 			//look for right
// 			low = mid + 1;
// 		}
// 	}

// 	return ans;
        
    return lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    }
};