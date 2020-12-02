//
// Created by lenovo on 2020/12/1.
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

/***
 *s = "abaccdeff"
返回 "b"

s = ""
返回 " "

 很简单，结合前面学的用数组，作为字符的map就行
 *
 *
 *
 *
 *
 * /