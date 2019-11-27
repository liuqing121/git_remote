class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        //记录当前子序列的乘积最小值的最大值，当遇到负数时，交换最小最大值，让小的更小，大的更大，方便之后再遇到负数，得到更大的正数
        int maxres = INT_MIN;
        int curmax = 1;
        int curmin = 1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] < 0)
            {
                int tmp = curmax;
                curmax = curmin;
                curmin = tmp;
            }
            curmax = max(nums[i],curmax*nums[i]);
            curmin = min(nums[i],curmin*nums[i]);
            maxres = max(curmax, maxres);
        }
        return maxres;
    }
};