class Solution {
public:
    
    int trap(vector<int>& height) {
        // Dynamic Programming
        // TC - O(n)  SC - O(n)
//         int ans = 0;
//         int n = height.size();
//         if(n==0)
//             return 0;
//         vector<int> left_max(n), right_max(n);
        
//         left_max[0] = height[0];
        
//         for(int i=1;i<n;i++){
//             left_max[i] = max(height[i], left_max[i-1]);
//         }
        
//         right_max[n-1] = height[n-1];
//         for(int i=n-2;i>=0;i--){
//             right_max[i]=max(height[i],right_max[i+1]);
//         }
        
//         for(int i=1;i<n-1;i++){
//             ans = ans+ min(left_max[i],right_max[i]) - height[i];
//         }
//         return ans;
        
//         // Using 2 pointers
        
//         int ans =0;
//         int n=height.size();
//         if(n==0)
//             return 0;
        
//         int left_max=0,right_max=0;
        
//         int left =0,right=n-1;
        
//         while(left<right){
//             if(height[left]< height[right]){
//                 if(height[left]>=left_max){
//                     left_max = height[left];
//                 }else{
//                     ans=ans+ left_max-height[left];
//                 }
//                 left++;
//             }
//             else{
//                 if(height[right] >= right_max){
//                     right_max = height[right];
//                 }else{
//                     ans =ans+ right_max - height[right];
//                 }
//                 right--;
//             }
//         }
//         return ans;
        
        // 2 pointers more intuitive
        int ans =0;
        int n = height.size();
        
        if(n ==0 ) return 0;
        
        int left_max = 0, right_max = 0;
        int left = 0, right = n-1;
        
        while(left < right){
            
            left_max = height[left] > left_max ? height[left]: left_max;     
            right_max = height[right] > right_max ? height[right]: right_max;
            
            if(left_max < right_max){
                ans += left_max - height[left];
                left++;
            } else {
                ans+= right_max - height[right];
                right--;
            }
        }
        
        return ans;
    }
};