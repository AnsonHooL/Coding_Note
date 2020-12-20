//
// Created by lenovo on 2020/12/20.
//

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int mymap[128] = {0};
        int visited[128] = {0};
        for(auto x : s) { mymap[x]++; } ///统计字符出现次数
        stack<char> mystack;
        for(auto x : s)
        {
            mymap[x]--;
            if(visited[x] == 1) continue; ///如果字符已经出现在栈里，则可以跳过
            while (!mystack.empty() && mystack.top() > x && mymap[mystack.top()]) ///比较字符大小
            {
                visited[mystack.top()] = 0;
                mystack.pop();
            }
            mystack.push(x);
            visited[x] = 1;
        }
        string re;
        while(!mystack.empty())
        {
            re = string(1,mystack.top()) + re;
            mystack.pop();
        }
        return  re;
    }
};
/***
 * 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。 

示例 1：

输入：s = "bcabc"
输出："abc"
示例 2：

输入：s = "cbacdcbc"
输出："acdb"


 思路：每一个字母先统计出现次数，则当每一个字母比前一个字母小，并且前面字母在后面仍然后出现时候，则将前一个字母丢弃。
 这个思路很适合用栈实现

 * /