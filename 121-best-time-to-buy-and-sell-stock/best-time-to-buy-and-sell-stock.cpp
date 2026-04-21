class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int buy = prices[0];
        for (auto price: prices){
            if(price < buy){
                buy = price;
            } else { // current price is higher than the buy so we can make a proffit
                profit = profit > (price-buy) ? profit : (price-buy);
            }
        }
        return profit;
    }
};


// 5 4 3 1 7   