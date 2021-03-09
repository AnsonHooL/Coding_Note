//
// Created by lenovo on 2021/3/8.
//

class Solution {
public:
    int minCut(string s) {
        vector<int> mincutdp(s.size(), INT32_MAX);
        vector<vector<bool>> palindromedp(s.size(), vector<bool>(s.size(), true));
        for(int i = s.size() - 1; i >= 0; i--)
        {
            for(int j = i; j < s.size(); j++)
            {
                palindromedp[i][j] = (s[i] == s[j]) && ((i >= j-1) || palindromedp[i+1][j-1]);
            }
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(palindromedp[0][i])
            {
                mincutdp[i] = 0;
                continue;
            }
            for(int j = 0; j < i; j++)
            {
                if(palindromedp[j+1][i])
                {
                    mincutdp[i] = min(mincutdp[i], mincutdp[j] + 1);
                }
            }
        }
        return mincutdp[s.size() - 1];
    }
};

/**
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。

返回符合要求的 最少分割次数 。

 

示例 1：

输入：s = "aab"
输出：1
解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
示例 2：

输入：s = "a"
输出：0
示例 3：

输入：s = "ab"
输出：1


思路：用两个动规
 动规一：计算出dp[i][j],字符串i-j是否为回文子串，和第五题一样，不过这里简化了动规的转换方程
 动规二：dp【i】是最小分隔次数
 *
 * */