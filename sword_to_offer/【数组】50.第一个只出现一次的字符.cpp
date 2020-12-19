//
// Created by lenovo on 2020/12/2.
//

class Solution {
public:
    char firstUniqChar(string s) {
        int map[128] ={0};
        int size = s.size();
        for(int i=0;i<size;i++)
        {
            map[s[i]]++;
        }
        for(int i=0;i<size;i++)
        {
            if(map[s[i]] == 1) return s[i];
        }
        return ' ';
    }
};

/**在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例:

s = "abaccdeff"
返回 "b"

s = ""
返回 " "
 */

