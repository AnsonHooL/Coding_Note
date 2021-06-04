//
// Created by lenovo on 2021/3/16.
//

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i <= n; i++){
            dp[0][i] = i;
        }
        for(int i = 0; i <= m; i++){
            dp[i][0] = i;
        }

        for(int i = 1; i <= m; i++){

            for(int j = 1; j <= n; j++){

                if(word2[j-1] == word1[i-1]){

                    dp[i][j] = dp[i-1][j-1];

                }
                else{

                    int mindp =  min(min(dp[i - 1][j], dp[i][j-1]), dp[i-1][j-1]);

                    dp[i][j] = mindp + 1;

                }
            }
        }
        return dp[m][n];
    }
};

/***
 * 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

思路
 相等则后退，如果不相等则考虑三种情况，属实套路题啊


 *
 * /