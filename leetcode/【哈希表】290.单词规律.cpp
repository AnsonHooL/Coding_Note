//
// Created by lenovo on 2020/12/16.
//

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream is(s);
        string word;
        int i = 0;
        map<string,char> mymap;
        char flag[30] = {0};
        while(is >> word)
        {
            auto it = mymap.find(word);
            if(it == mymap.end() && !flag[pattern[i] - 'a'])
            {
                mymap[word] = pattern[i];
                flag[pattern[i] - 'a'] = 1;
            }else if(it == mymap.end() && flag[pattern[i] - 'a']) return false;
            else if(mymap[word] != pattern[i]) return false;
            i++;
        }
        if(i != pattern.size()) return false;
        return true;
    }
};

/**
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false

思路：注意双向映射，word -》 char char -》 word

 */