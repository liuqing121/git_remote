#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows)
	{
		string res;
		vector<string> change(numRows);  //存储变化后的字符串，下标为行
		int size = 0;
		while (size < s.size())
		{
			int index = 0;
			while (index < numRows && size < s.size())    //这里依然要判断越界
			{
				change[index++].push_back(s[size++]);
			}
			index--;     //index返回为最后一行
			while (index > 1 && size < s.size())   //填充中间的字符
			{
				change[--index].push_back(s[size++]);
			}
		}
		for (int i = 0; i < numRows; i++)
		{
			res += change[i];
		}
		return res;
	}
};
int main()
{
	Solution s;
	s.convert("PAYPALISHIRING", 3);
	return 0;
}