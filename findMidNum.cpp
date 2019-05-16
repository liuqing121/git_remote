#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int size1 = nums1.size();
		int size2 = nums2.size();
		if (!size1 && !size2)
			return 0.0;

		//��������λ�����±�
		int pos = (size1 + size2 - 1) >> 1;   //ʹ����λ�ƴ��������Ч�ʻ�ߵ�
		int left = max(0, pos - size2);
		int right = min(pos, size1);
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (nums1[mid] < nums2[pos - mid - 1])
				left = mid + 1;
			else
				right = mid;
		}

		if ((size1 + size2) & 1)   //�ܳ�Ϊ����
		{
			if (left >= size1)   //˵����λ����nums2��
			{
				return nums2[pos - left];
			}
			if (pos - left > size2)  //˵����nums1��
			{
				return nums1[left];
			}
			if (nums1[left] < nums2[pos - left])
			{
				return nums1[left];
			}
			return nums2[pos - left];
		}
		else   //�ܳ�Ϊż��
		{
			if (left >= size1)
			{
				return 0.5 * (nums2[pos - left] + nums2[pos - left + 1]);
			}
			if (pos - left >= size2)
			{
				return 0.5 * (nums1[left] + nums1[left + 1]);
			}
			if (pos - left + 1 < size2 && nums1[left] > nums1[left + 1])
			{
				return 0.5 * (nums2[pos - left] + nums2[pos - left + 1]);
			}
			else if (left + 1 < size1 && (nums1[left] > nums1[left + 1]))
			{
				return 0.5 * (nums1[left] + nums1[left + 1]);
			}
			else
				return 0.5 * (nums1[left] + nums2[pos - left]);
		}
	}
};
int main()
{
	Solution so;
	vector<int> nums1 = { 1, 2, 3 };
	vector<int> nums2 = { 4,5,6 };
	so.findMedianSortedArrays(nums1, nums2);
	return 0;
}