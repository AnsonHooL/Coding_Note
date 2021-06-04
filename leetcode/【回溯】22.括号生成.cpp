//
// Created by lenovo on 2021/6/2.
//

class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        string str;
        backtrace(n,str,0,0);
        return result;
    }

    void backtrace(int n, string& path,int left, int right){
        if(path.size() == 2 * n){
            result.push_back(path);
            return;
        }

        for(int i = 1; i <= 2 ; i++){
            if(i == 1){
                if(left < n){
                    path.push_back('(');
                    backtrace(n, path, left + 1, right);
                    path.pop_back();
                }
            } else{
                if(right < left){
                    path.push_back(')');
                    backtrace(n, path, left, right + 1);
                    path.pop_back();
                }
            }

        }
        return;
    }
};
/**
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]

思路：就是一道很基础的回溯，然后也不怎么需要剪枝，知道左右括号怎么才是合法的就行，左大于等于右即可， 一次过！

 回溯三部曲：
 终止条件
 每一层的操作，剪枝
 参数


 *
 *
 * */