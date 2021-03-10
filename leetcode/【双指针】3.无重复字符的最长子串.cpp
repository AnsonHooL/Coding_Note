//
// Created by lenovo on 2021/3/9.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int high = 0;
        int maxdist = 0;
        unordered_map<char,int> mymap;
        for(int i = 0; i < s.size(); i++)
        {
            if(mymap.find(s[i]) == mymap.end() || mymap[s[i]] < low)
            {
                mymap[s[i]] = i;
                high = i + 1;
                maxdist = max(maxdist, high - low);
            } else ///这里的细节要相当小心，就是指针如何更新
            {
                low = mymap[s[i]] + 1;
                mymap[s[i]] = i;
                high = i + 1;
                maxdist = max(maxdist, high - low);
            }
        }
        return maxdist;
    }
};

/**
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

思路：双指针即可
 *
 *
 * */