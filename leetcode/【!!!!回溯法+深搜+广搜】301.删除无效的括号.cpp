//
// Created by lenovo on 2021/6/8.
//

///回溯法，深搜的变形
class Solution {
public:
    void dfs(string& s, string& cur, int idx, int lcnt, int rcnt, int lnum, int rnum, set<string>& ans){
        if(idx == s.size()){
            if(lcnt == 0 && rcnt == 0) ans.insert(cur);
            return;
        }
        if(lnum < rnum) return; ///不合法，剪枝

        if(s[idx] == '(' && lcnt > 0){  ///删除左括号
            dfs(s, cur, idx+1, lcnt-1, rcnt, lnum, rnum, ans);

        }else if(s[idx] == ')' && rcnt > 0){  ///删除右括号
            dfs(s, cur, idx+1, lcnt, rcnt-1, lnum, rnum, ans);
        }
        //
        /// 保留该字符
        if(s[idx] == '(') lnum++; //更新计数
        else if(s[idx] == ')') rnum++;
        cur.push_back(s[idx]);
        dfs(s, cur, idx+1, lcnt, rcnt, lnum, rnum, ans);
        cur.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        int lcnt = 0, rcnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') lcnt++;
            else if(s[i] == ')'){
                if(lcnt == 0) rcnt++;
                else lcnt--;
            }
        }
        if(lcnt == 0 && rcnt == 0) return {s};

        set<string> set;
        string str;
        dfs(s, str, 0, lcnt, rcnt, 0, 0, set);

        return {set.begin(), set.end()};
    }
};

/**
 * 思路：
 * 1.首先遍历整个字符串，计算出要删除多少左括号和右括号
 * 2.深搜，过程中遇到括号可以添加或者删除，删除只能删除最少数目，可以选择删除或者不删除
 * 3，剪纸，如果右括号数大于左括号,就不合法
 * 4.这题也用了set进行去重
 * *
 *
 *
 *给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。

返回所有可能的结果。答案可以按 任意顺序 返回。

 

示例 1：

输入：s = "()())()"
输出：["(())()","()()()"]

 * *
 * */