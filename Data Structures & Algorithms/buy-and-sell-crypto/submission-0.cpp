class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = INT_MIN;

        for(int p: prices){
            if(p < min_price) min_price = p;
            max_profit = max(max_profit, p - min_price); //min_price is where we buy
        }

        return max_profit;
    }
};