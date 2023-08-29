class Solution {
public:
    int maxProfit(vector<int>& prices) {
//         int maxP=0;
//         for(int i=0;i<prices.size();++i)
//         {
//             for(int j=i+1;j<prices.size();++j)
//             {
//                 if(prices[j] - prices[i] > maxP)
//                     maxP = prices[j]-prices[i];
//             }
            
//         }
//         return maxP;
        
        
        // int n = prices.size();
//         if(prices.size() == 0)
//             return 0;
//         int maxP = 0;
//         int minP = INT_MAX;
        
//         for(int i=0;i<prices.size();++i)
//         {
//             minP = min(minP, prices[i]);
//             maxP = max(maxP, prices[i] - minP);
//         }
//         return maxP;
        
        // int n = prices.size();
        // int buyAtPrice = INT_MAX;
        // int maxProfit = 0;
        // for(int i=0; i<n; i++){
        //     buyAtPrice = min(buyAtPrice, prices[i]);
        //     maxProfit = max(maxProfit, prices[i] - buyAtPrice); 
        // }
        // return maxProfit;
        
        
        int n = prices.size();
        int minEle = INT_MAX;
        int maxProfit = 0;
        for(int i=0; i<n; i++){
            // buyAtPrice = min(buyAtPrice, prices[i]);
            // maxProfit = max(maxProfit, prices[i] - buyAtPrice); 
            
            if(prices[i] < minEle)
                minEle = prices[i];
            else if(prices[i] - minEle > maxProfit)
                maxProfit = prices[i] - minEle;
        }
        return maxProfit;
    }
};