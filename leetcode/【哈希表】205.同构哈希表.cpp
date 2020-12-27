//
// Created by lenovo on 2020/12/27.
//

/**
 * 给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:

输入: s = "egg", t = "add"
输出: true

两个哈希表就行
 * */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() == 0) return true;
        map<char,char> tmap;
        map<char,char> smap;
        for(int i = 0; i < s.size(); i++)
        {
            if(smap.find(s[i]) == smap.end() && tmap.find(t[i]) == tmap.end())
            {
                smap[s[i]] = t[i];
                tmap[t[i]] = s[i];
            }else if(smap.find(s[i]) != smap.end() && tmap.find(t[i]) != tmap.end())
            {
                if(s[i] != tmap[t[i]]) return false;
                if(t[i] != smap[s[i]]) return false;
            } else
            {
                return false;
            }
        }
        return true;
    }
};