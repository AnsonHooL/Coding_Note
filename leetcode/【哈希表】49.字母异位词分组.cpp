//
// Created by lenovo on 2020/12/16.
//

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,multiset<string>>mymap;
        vector<vector<string>> re;
        int i = 0;
        for(auto a : strs)
        {
            sort(a.begin(),a.end());
            mymap[a].insert(strs[i++]);
        }
        re.resize(mymap.size());
        i = 0;
        for(auto setpair : mymap)
        {
            for(auto str : setpair.second)
            {
                re[i].push_back(str);
            }
            i++;
        }
        return re;
    }
};

/****
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

*/