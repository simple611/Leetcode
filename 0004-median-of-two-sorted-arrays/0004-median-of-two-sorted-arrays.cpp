class Solution {
public:
    // TC: O(m+n)  Sc - O(m+n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> nums3(nums1.size()+nums2.size());
        
        int i=0, j=0;
        int m =nums1.size(), n = nums2.size();
        int k=0;
        
        while(i<= m-1 && j <= n-1){
            
            if(nums1[i] <= nums2[j]){
                nums3[k++] = nums1[i++];
            } else {
                nums3[k++] = nums2[j++];
            }
        }
        
        while(i <= m-1){
            nums3[k++] = nums1[i++];
        }
        
        while(j<=n-1){
            nums3[k++] = nums2[j++];
        }
        
        double ans;
        // cout<<"k="<<k<<endl;
        if( k % 2 ==0){
            int idx = k/2;
            
            ans = (1.0 * nums3[idx] + nums3[idx-1])/2;
        } else {
            int idx = k/2;
            ans = nums3[idx];
        }
        
        return ans;
        
    }
};