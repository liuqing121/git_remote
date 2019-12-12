class Solution {
public:
    vector<int> countBits(int num) 
    {
        //动态规划加最低有效位,通过找规律得出每个数的二进制和他自己除以2的二进制只有最低位的差别
        vector<int> res(num+1,0);
        for(int i = 1; i <= num; ++i)
        {
            res[i] = res[i>>1] + (i&1);
        }
        return res;
    }
};