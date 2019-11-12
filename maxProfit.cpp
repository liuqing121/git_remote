class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minprice = INT_MAX;
        int maxlirun = 0;
        for(int i = 0; i < prices.size(); ++i)
        {
            if(prices[i] < minprice)
            {
                minprice = prices[i];
            }
            else
            {
                //上一次的最大利润和当前价格与前几天的最小价格差值哪个大即为当前最大利润
                maxlirun = max(prices[i]-minprice, maxlirun);
            }
        }
        return maxlirun;
    }
};