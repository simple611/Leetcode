class Solution {
public:
    // TC - O(n)  SC-O(1)
    int maxArea(vector<int>& height) {
        int area=0;
        int n=height.size();
        // if(n==0 || n==1)
        //     return 0;
        int l=0,r=n-1;
        
        while(l<r){  
            int minH = min(height[l], height[r]);
            int a = minH * (r-l);
            area = max(a,area);
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
            
        }
        return area;
    }
};