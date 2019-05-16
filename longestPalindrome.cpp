//中心扩展法
class Solution {
public:
    string longestPalindrome(string s) 
    {
        //构造一个新的string，在原来字符串的每个相邻字符中间和字符串的首尾都插入分隔符，这样奇偶长度的字符串可以一起处理
        //字符串头用$符是为了让循环从1开始，避免right越界
        string tmpStr = "$#";
        for(int i = 0; i < s.size(); ++i)
        {
            tmpStr += s[i];
            tmpStr += '#';
        }
        //回文字符串的中心下标
        int pos = 0;
        //回文字符串的最右下标
        int right = 0;
        //回文字符串开始位置的下标(原串下标)
        int start = 0;
        //最长回文字符串的长度(原串)
        int maxlen = 0;
        //每个字符为中心的最右下标到字符的长度
        vector<int> len(tmpStr.size(),0);
        for(int i = 1; i < tmpStr.size(); ++i)
        {
            //若i大于right，则需要从1开始重新计算该位置的len[i]
            len[i] = i < right? min(len[2*pos-i], right-i) : 1;
            //i+len[i]实际是以i为中心的回文的右边界下标，i-len[i]是左边,这里得到len[i]的值
            while(i + len[i] < tmpStr.size() && i - len[i] > 0 && tmpStr[i+len[i]] == tmpStr[i-len[i]])
            {
                ++len[i];
            }
            //如果i+len[i]大于上一个有边界，则更新右边界和pos
            if(i + len[i] > right)
            {
                pos = i;
                right = i + len[i];
            }
            //len[i]-1实际上就是回文字符的长度，(i-len[i])/2是回文字符的开始位置
            if(len[i]-1 > maxlen)
            {
                start = (i - len[i])/2;
                maxlen = len[i]-1;
            }
        }
        return s.substr(start, maxlen);
    }
};