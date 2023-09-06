class Solution {
public:
    // TC: O(m+n)  Sc - O(m+n)
    double findMedianSortedArrays_mergeSort(vector<int>& nums1, vector<int>& nums2) {
        
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
    
    // TC - O(m+n)  SC - O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();
        
        int idx1, idx2;
        
        idx2 = (m+n)/2;
        idx1 = idx2-1;
        
        int count=0;
        
        int idx1el = -1, idx2el = -1;
        int i=0, j=0;
        
        while(i<m && j<n){
            
            if(nums1[i] <= nums2[j]){
                if(count == idx1)  idx1el=nums1[i];
                if(count == idx2)  idx2el=nums1[i];
                count++;
                i++;
            } else{
                if(count == idx1)  idx1el=nums2[j];
                if(count == idx2)  idx2el=nums2[j];
                count++;
                j++;
            }
        }
        
        while(i<m){
            if(count == idx1)  idx1el=nums1[i];
            if(count == idx2)  idx2el=nums1[i];
            count++;
            i++;
        }
        
        while(j<n){
            if(count == idx1)  idx1el=nums2[j];
            if(count == idx2)  idx2el=nums2[j];
            count++;
            j++;
        }
        
        if((m+n) %2 == 1){
            return idx2el;
        }
        
        return (double)((double)idx1el + idx2el)/2.0;
        
    }
};