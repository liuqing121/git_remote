class Solution {
public:
    //定义比较仿函数
    struct cmp
    {
        bool operator()(pair<int,int>&a, pair<int,int>&b)
        {
            return a.second>b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> countmap;
        for(int num : nums)
        {
            countmap[num]++;
        }

        //建一个小堆
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> lessheap;
        for(auto count : countmap)
        {
            lessheap.push(count);
            if(lessheap.size() > k)
            {
                lessheap.pop();
            }
        }
        std::vector<int> res(lessheap.size(),0);
        while(k--)
        {
            //因为是小堆，所以结果从后往前填充
            res[lessheap.size()-1] = lessheap.top().first;
            lessheap.pop();
        }
        return res;
    }
};