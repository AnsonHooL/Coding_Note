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