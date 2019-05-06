#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		int k = 0;
		int max = 0;
		int j = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			for (j = k; j < i; j++)
			{
				if (s[j] == s[i])
				{
					k = j + 1;
					break;
				}
			}
			if (i - k + 1 > max)
				max = i - k + 1;
		}
		return max;
	}
};
int main()
{
	Solution solu;
	int res = solu.lengthOfLongestSubstring("abababc");
	cout << res << endl;
	system("pause");
}