class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const size_t n = prices.size();
        if(n < 2) return 0;
        vector<vector<int>> L(n, vector<int>(2, 0));
        //L[i][0] is the max_profit when buy stock on day i
        //L[i][1] is the max_profit when sell stock on day i
        L[0][0] = -prices[0], L[0][1] = 0;
        L[1][0] = -prices[1], L[1][1] = max(prices[1] - prices[0], 0);
        int max_profit = L[1][1];
        for(int i = 2; i < n; ++i){
            int profit = prices[i] - prices[i - 1];
            L[i][0] = max(L[i - 2][1] - prices[i], L[i - 1][0] - profit);
            L[i][1] = max(L[i - 1][0] + prices[i], L[i - 1][1] + profit);
            max_profit = max(max_profit, L[i][1]);
        }
        return max_profit;
        
    }
};
