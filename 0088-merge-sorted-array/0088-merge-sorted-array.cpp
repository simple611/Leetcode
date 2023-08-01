class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(n==0)
        {
            return;
        }
        int L[m+n], R[n];
        // if(m==0 && n==1)
        
        for(int i=0;i<m;i++){
            L[i]=nums1[i];
        }
        for(int i=0;i<n;i++){
            R[i]=nums2[i];
        }
        int i=0, j=0, k=0;
        
        while(i<m && j<n)
        {
            if(L[i]<=R[j]){
                nums1[k]=L[i];
                k++;
                i++;
            }
            else{
                nums1[k]=R[j];
                k++;
                j++;
            }
        }
        while(i<m)
        {
            nums1[k]=L[i];
            k++;
            i++;
        }
        while(j<n)
        {
            nums1[k]=R[j];
            k++;
            j++;
        }
    }
};