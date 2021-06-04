//
// Created by lenovo on 2021/6/2.
//

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);

        int result = 0;

        for(int i = 1; i < s.size(); i++){
            if(s[i] == '('){

                dp[i] = 0;

            } else if(s[i] == ')'){

                if(s[i - 1] == ')'){

                    int len = dp[i-1];

                    if(i - len - 1 >= 0 && s[i - len -1] == '('){

                        dp[i] = len + 2;

                        if(i - len - 1 - 1 > 0){

                            dp[i] += dp[i - len - 1 - 1];

                        }

                    }

                } else if(s[i - 1] == '('){

                    dp[i] = 2;

                    if(i - 2 > 0){

                        dp[i] += dp[i-2];

                    }

                }

                result = max(result, dp[i]);

            }
        }
        return result;
    }
};

/**
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

 

示例 1：

输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"
示例 2：

输入：s = ")()())"
输出：4
解释：最长有效括号子串是 "()()"
示例 3：

输入：s = ""
输出：0
 

思路：
 用了笨方法动规，就是标记第i个结尾的最长有效长度，然后疯狂计算


 * */

 ///用栈模拟一遍，将所有无法匹配的括号的位置全部置1
 ///例如: "()(()"的mark为[0, 0, 1, 0, 0]
 ///再例如: ")()((())"的mark为[1, 0, 0, 1, 0, 0, 0, 0]
 ///经过这样的处理后, 此题就变成了寻找最长的连续的0的长度
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<bool> mark(s.length());
        for(int i = 0; i < mark.size(); i++) mark[i] = 0;
        int left = 0, len = 0, ans = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') st.push(i);
            else {
                // 多余的右括号是不需要的，标记
                if(st.empty()) mark[i] = 1;
                else st.pop();
            }
        }
        // 未匹配的左括号是不需要的，标记
        while(!st.empty()) {
            mark[st.top()] = 1;
            st.pop();
        }
        // 寻找标记与标记之间的最大长度
        for(int i = 0; i < s.length(); i++) {
            if(mark[i]) {
                len = 0;
                continue;
            }
            len++;
            ans = max(ans, len);
        }
        return ans;
    }
};