class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        int minStock = prices[0];
        for(int i=1; i<n; i++){
            if(minStock<prices[i]){
                profit = max(profit, prices[i]-minStock);
            }
            else{
                minStock=prices[i];
            }
        }
        return profit;
    }
};