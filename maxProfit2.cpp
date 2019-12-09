class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        //动态规划，三个状态转移方程
        int hold = INT_MIN;    //持有股票
        int rest = 0;   //什么都不做
        int sold = 0;   //卖出股票
        for(int p : prices)
        {
            int pre_sold=sold;
            sold = hold+p;   //卖出的话，利润是上一次持有的利润加上当前的价格
            hold = max(hold, rest-p);   //持有可能是前一天就持有，也可能是当天持有（也就是刚刚买入，那前一天一定是什么都没做）
            rest = max(rest, pre_sold);   //继续什么都不做，或者因为前一天卖出了所以什么都不做
        }
        return max(rest, sold);    //最后一天卖出或者什么都不做
    }
};