//
// Created by lenovo on 2021/1/24.
//

class Solution{
public:
    string minWindow(string s, string t) {
        vector<int> tmap(256,0);
        vector<int> smap(256,0);
        for(auto c : t) tmap[c - '\0']++;
        int n = t.size();
        int low = 0;
        int high = -1;
        int count = 0;
        int ssize = s.size() - 1;
        int lowre = 0;
        int highre = 0;
        int maxre  = INT32_MAX;
        while (count < n && high < ssize)
        {
            high++;
//            cout<< high <<endl;
            int c = s[high] - '\0';
            if(smap[c] < tmap[c])
            {
                count++;
            }
            smap[c]++;
        }

        if(count < n) return string("");

        while(low < high)
        {
            int c = s[low];
            if(tmap[c] == 0)
            {
                low++;
            } else if(smap[c] > tmap[c])
            {
                smap[c]--;
                low++;
            } else
            {
                break;
            }
        }
        lowre = low;
        highre = high;
        maxre = high - low + 1;

        while(high < ssize)
        {
            high++;
            int c = s[high] - '\0';
            smap[c]++;
            while (low < high)
            {
                int c = s[low];
                if(tmap[c] == 0)
                {
                    low++;
                } else if(smap[c] > tmap[c])
                {
                    smap[c]--;
                    low++;
                } else
                {
                    break;
                }
            }
            if(high - low + 1 < maxre)
            {
                maxre = high - low + 1;
                highre = high;
                lowre = low;
            }
        }


        return s.substr(lowre, highre - lowre + 1);
    }
};

/**
 *
 *给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
示例 2：

输入：s = "a", t = "a"
输出："a"
 

提示：

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成


 思路：双指针即可！！！，维护两个哈希表，然后high++，low疯狂往前移动，看是否能覆盖住即可。即哈希表中是否大于他，那就可以跳过并减减

 * */