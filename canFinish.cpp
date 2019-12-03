class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        //广度优先遍历,把入度为0的push到队列中,从队列中弹出并把以该数据为入度的度减一，减一后变成0的继续push，最后如果进入且出来的数据量和numCourses相等，则是拓扑排序
        vector<int> rudu(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            rudu[prerequisites[i][0]] ++;;
        }
        queue<int> qu;
        for(int j = 0; j < numCourses; ++j)
        {
            if(rudu[j] == 0)
            {
                qu.push(j);
            }
        }
        int res = 0;
        while(!qu.empty())
        {
            ++res;
            int front = qu.front();
            qu.pop();
            for(auto& list : prerequisites)
            {
                if(list[1] == front)
                {
                    rudu[list[0]]--;
                    if(rudu[list[0]] == 0)
                    {
                        qu.push(list[0]);
                    }
                }
            }
        }
        return res == numCourses;
    }
};