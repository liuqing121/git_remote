class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::vector<int> result;
        std::unordered_map<int,int> tmpmap;
        for(unsigned int i = 0; i < nums.size(); ++i)
        {
            int sub = target - nums[i];
            unordered_map<int,int>::iterator iter = tmpmap.find(sub);
            if(iter != tmpmap.end())
            {
                result.push_back(tmpmap[sub]);
                result.push_back(i);
            }
            tmpmap[nums[i]] = i;
        }
        return result;
    }
};