//
// Created by lenovo on 2020/12/20.
//

class Solution {
public:
    string removeKdigits(string num, int k) {
        int remain = num.size() - k;
        int count = 0; ///记录去除数字的次数
        stack<char> mystack;
        string re;
        for(auto x : num)
        {
            while(!mystack.empty() && mystack.top() > x && count < k) ///while循环是究极关键，不断的往前退，把所有的不合格数去掉
            {
                mystack.pop();
                count++;
            }

            mystack.push(x);
        }
        while(mystack.size() > remain)
        {
            mystack.pop();
        }
        while(!mystack.empty())
        {
            re = string(1,mystack.top()) + re;
            mystack.pop();
        }

        for(int i = 0; i<re.size();i++)
        {
            if(re[i] != '0') return string(re.begin()+i,re.end());
        }

        return string("0");
    }
};

/**
 *
 *
 * 给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:

num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :

输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
示例 2 :

输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
示例 3 :

输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。


 思路：1 2 4 3 去掉1位，必然是遇到 前面的数字 > 后面的数字则将前面的数字删掉

 */