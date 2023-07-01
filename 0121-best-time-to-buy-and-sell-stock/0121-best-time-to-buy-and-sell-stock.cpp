class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int maxprofit = 0;
        int minprice = prices[0];
        
        for (const int price : prices) {
            minprice = min(minprice, price);
            maxprofit = max(maxprofit, price - minprice);
        }
        
        return maxprofit;
    }
};