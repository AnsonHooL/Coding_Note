//
// Created by lenovo on 2021/6/9.
//

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.size()>s.size()||s.size()==0) return ans;
        vector<int>need(128);
        vector<int>windows(128);
        for(char a:p) need[a]++;
        for(int i=0;i<p.size()-1;i++) windows[s[i]]++;
        int l=0,r=p.size()-1;//窗口是[l,r]
        while(r<s.size())
        {
            windows[s[r++]]++;
            ///还能这么比较我惊了，不过性能很差吧。。不管了。可以用26位数组来代替，这样能接收了

            if(windows==need) ans.push_back(l);
            windows[s[l++]]--;
        }
        return ans;
    }
};

/**
 * 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
示例 1:

输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。

 *
 * */