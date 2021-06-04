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
        while (count < n && high < ssize) ///这里high是负数，如果直接和无符号整型比较，就会隐式转换出错，溢出，切记切记
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

///下面是精简版的思路，维护一个need字典
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128,0);
        int count = 0;
        for(char c : t)
        {
            need[c]++;
        }
        count = t.length();
        int l=0, r=0, start=0, size = INT_MAX;
        while(r<s.length())
        {
            char c = s[r];
            if(need[c]>0)
                count--;
            need[c]--;  //先把右边的字符加入窗口
            if(count==0)    //窗口中已经包含所需的全部字符
            {
                while(l<r && need[s[l]]<0) //缩减窗口
                {
                    need[s[l++]]++;
                }   //此时窗口符合要求
                if(r-l+1 < size)    //更新答案
                {
                    size = r-l+1;
                    start = l;
                }
                need[s[l]]++;   //左边界右移之前需要释放need[s[l]]
                l++;
                count++;
            }
            r++;
        }
        return size==INT_MAX ? "" : s.substr(start, size);
    }
};