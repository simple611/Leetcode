class Solution {
public:
    // TC - O(n)  SC - O(1)
    int maxProfit_peak_valley(vector<int>& prices) {
        
        //Peak-valley approach
        int n = prices.size();
        int maxProfit=0;
        int valley=0,peak=0;
        for(int i=0;i<n-1;)
        {
            while(i<n-1 && prices[i]>=prices[i+1])
                i++;
            valley=prices[i];
             while(i<n-1 && prices[i]<=prices[i+1])
                i++;
            peak=prices[i];
            maxProfit += peak-valley;
        }
        return maxProfit;
    }
        
    // TC - O(n)  SC - O(1)
    int maxProfit(vector<int>& prices) {
        //Simple pass appraoch
        
        int n = prices.size();
        int maxProfit=0;
        for(int i=0;i<n-1;i++)
        {
            if(prices[i+1]>prices[i])
                maxProfit += prices[i+1]-prices[i];
        }
        return maxProfit;
    }
};