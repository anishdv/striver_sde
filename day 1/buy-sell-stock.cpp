// this is solution to  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int min_so_far=prices[0];
        

        for(int i=0;i<prices.size();i++){
            min_so_far=min(min_so_far,prices[i]);
            int profit=prices[i]-min_so_far;
            max_profit=max(max_profit,profit);
        }
        
        return max_profit;
    }
};