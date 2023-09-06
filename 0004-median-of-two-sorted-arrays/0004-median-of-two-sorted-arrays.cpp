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
    double findMedianSortedArrays_mergeSort_without_extraSpace(vector<int>& nums1, vector<int>& nums2) {
        
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
    
    // TC - O(log(min(n1,n2)))  Sc- O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        
        int low =  0, high = n1;
        
        int leftPartition = (n1 + n2 + 1)/2;   // If total is odd 5+1/2 = 3, If even 3+3+1/2 = 3
        
        while( low <= high){
            int mid1 = low + (high-low)/2;
            
            int mid2 = leftPartition - mid1;
            
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            
            if(mid1-1 >= 0) l1 = nums1[mid1-1];
            if(mid2-1 >= 0) l2 = nums2[mid2-1];
            
            if(l1 <= r2 && l2 <= r1){  // Found a valid partition
                if( (n1+n2) %2 == 1){
                    return max(l1, l2);
                } else {
                    return ((double)(max(l1, l2) + min(r1, r2)))/2.0;
                }
            } else if( l1 > r2)
                high = mid1-1;
            else
                low = mid1+1;
                 
            
        }
        
        return 0.0;
    }
    };