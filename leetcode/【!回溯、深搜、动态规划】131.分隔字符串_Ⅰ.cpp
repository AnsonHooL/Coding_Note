//
// Created by lenovo on 2021/3/7.
//

class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    bool palindrome(const string& s, int low, int high)
    {
        for (int i = low, j = high; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void backtracking(const string& s, int startindex)
    {
        if(startindex >= s.size())
        {
            result.push_back(path);
            return;
        }
        for(int i = startindex; i < s.size(); i++)
        {
            if(palindrome(s, startindex, i))
            {
                path.push_back(s.substr(startindex, i - startindex + 1));
                backtracking(s, i + 1); ///换成dfs是一样的
                path.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s)
    {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};

/**
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]




思路：这里有的是回溯（也可以说是深搜，感觉深搜和回溯就是一回事啊）
 abbcd，
 回溯的模板
 1.终止条件
 2.循环处理
 3.处理结果和回退结果

 处理（第1~n个字符切割，）进入回溯；
    终止条件
    回溯（）；
 取消结果；
 进入下一个循环

 2.第二个优化点是用动规提前算好了，字符串的回文状态，避免重复计算

 * */