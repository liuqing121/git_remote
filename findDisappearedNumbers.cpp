class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        //数组中出现数字作为下标加上数组长度，第二次循环中查看哪个下标对应的数字小于数组大小
        for(int i = 0; i < nums.size(); ++i)
        {
            int index = (nums[i]-1) % nums.size();  //防止越界
            nums[index] += nums.size();
        }
        std::vector<int> res;
        for(int j = 0; j < nums.size(); ++j)
        {
            if(nums[j] <= nums.size())
            {
                res.push_back(j+1);
            }
        }
        return res;
    }
};