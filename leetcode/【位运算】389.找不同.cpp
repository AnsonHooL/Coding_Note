//
// Created by lenovo on 2020/12/18.
//

class Solution {
public:
    char findTheDifference(string s, string t) {
        long sum = 0;
        for(auto it : t)
        {
            sum += it;
        }
        for(auto it : s)
        {
            sum -= it;
        }
        return sum;
    }
};

/**
 * 给定两个字符串 s 和 t，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。

 

示例 1：

输入：s = "abcd", t = "abcde"
输出："e"
解释：'e' 是那个被添加的字母。

思路：字符串和t - 字符串和s
 *
 *
 * */