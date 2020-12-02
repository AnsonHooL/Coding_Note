//
// Created by lenovo on 2020/12/1.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos = 0;
        int size = s.size();
        if(size == 0) return 0;
        int max = 0;
        map<char,int> mymap;
        for(int i =0; i<size; i++)
        {
            if(mymap.find(s[i]) == mymap.end() || mymap[s[i]] < pos)
            {
                mymap[s[i]] = i;
            }
            else
            {
                max = (i-pos)>max?(i-pos):max;
                int tmp = pos;
                pos = mymap[s[i]] + 1;
                mymap[s[i]] = i;
            }
        }
        max = (size-pos)>max?(size-pos):max;
        return max;
    }
};

/**
 *输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

1.字符的题目，优化可以用数组char[128]代替hashmap
 2. 可以用跳过的方式，优化掉erase操作
 *
 *
 * /