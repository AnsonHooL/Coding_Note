//
// Created by lenovo on 2020/12/23.
//

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> map(26,-1);
        int i = 0;
        for(auto x : s)
        {
            if(map[x - 'a'] == -1) map[x - 'a'] = i;
            else if(map[x - 'a'] >= 0) map[x - 'a'] = -999;
            i++;
        }
        i = 0;
        for(auto x : s)
        {
            if(map[x - 'a'] >= 0) return i;
            i++;
        }
        return -1;
    }
};

/**
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

 

示例：

s = "leetcode"
返回 0

s = "loveleetcode"
返回 2

注意审题
 *
 * */