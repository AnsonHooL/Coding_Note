//
// Created by lenovo on 2020/12/24.
//


///最长回文
///cabbxxxbbaf,返回长度9：abbxxxbba

///暴力法往往能给我们带来提示进行优化
///暴力法也有用的哟，慢慢优化才是正常思维
///暴力法，从pos i ~ j，暴力遍历看是否为回文，j>i O（n*n*n）


///中心扩散O（n*n）
///每个字符都作为中心去看是否有回文串
class Solution {
public:
    int  findlong(const string s,int start, int& len)
    {
        int low = start;
        int high = start;
        while(high < s.size() - 1)
        {
            if(s[high] == s[high+1]) high++;
            else break;
        }
//        while(low > 0)
//        {
//            if(s[low] == s[low-1]) low--;
//            else break;
//        }
        while(low>0  && high<s.size() && s[low-1] == s[high+1])
        {
            low--;
            high++;
        }
        len = high - low + 1;
        return low;
    }
    string longestPalindrome(string s) {
        int size = s.size();
        int maxlen = 0;
        int maxpos = 0;
        int pos = 0;
        int len = 0;
        if(size == 0)  return "";
        for(int i=0; i<size ;i++)
        {
            int pos = findlong(s,i,len);
            if(len > maxlen)
            {
                maxlen = len;
                maxpos = pos;
            }
        }
        return string(s,maxpos,maxlen);
    }
};



///动态规划法O(n*n)
///dp[i][j]表示 i-j字符串是否为回文
///dp[i][j] = dp[i+1][j-1] == 1 && s[i] == s[j]
class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0;
        int low = 0;
//        int high = 0;
        int len = s.size();
        int dp[len + 10][len + 10];
        memset(dp,0, sizeof(int) * (len + 10) * (len + 10));
        for(int i = 0; i < len; i++) ///先令一个字符都是回文
        {
            dp[i][i] = 1;
            low = i;
            max = 1;
        }
        for(int i = 0; i< len -1;i++) ///相邻两个字符是否为回文
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = 1;
                max = 2;
                low = i;
            }
        }
        for(int length = 3; length <= len; length++) ///从3 - len
        {
            for(int i = 0; i <= len - length; i++)
            {
                int j = i + length -1;
                if(s[i] == s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = 1;
                    if(length > max)
                    {
                        max = length;
                        low = i;
                    }
                }
            }
        }
        return s.substr(low,max);

    }
};