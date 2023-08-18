class Solution {
public:
    // TC - O(N + M)  SC- O(1)
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int MOD = 1e9+7;
        int n = nums1.size(), m = nums2.size();
        
        long long int sum1=0, sum2=0, ans = 0;
        
        int i=0, j=0;
        
        while(i<n && j <m){
            if(nums1[i] < nums2[j]){
                sum1+=nums1[i++];
            } else if(nums2[j] < nums1[i]){
                sum2+=nums2[j++];
            } else {
                ans +=max(sum1, sum2) + nums1[i];
                i++;
                j++;
                sum1=0;
                sum2=0;
            }
        }
        
        while(i<n){
            sum1+=nums1[i++];
        }
        
        while(j<m){
            sum2+=nums2[j++];
        }
        
        ans+=max(sum1, sum2);
        ans = ans%MOD;
        return (int)ans;

    }
};