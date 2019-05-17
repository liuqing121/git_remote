#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows)
	{
		string res;
		vector<string> change(numRows);  //�洢�仯����ַ������±�Ϊ��
		int size = 0;
		while (size < s.size())
		{
			int index = 0;
			while (index < numRows && size < s.size())    //������ȻҪ�ж�Խ��
			{
				change[index++].push_back(s[size++]);
			}
			index--;     //index����Ϊ���һ��
			while (index > 1 && size < s.size())   //����м���ַ�
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