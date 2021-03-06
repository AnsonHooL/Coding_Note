//
// Created by lenovo on 2021/3/4.
//

bool cmpare(vector<int> lhs, vector<int> rhs)
{
    return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmpare);
        int n = envelopes.size();
        vector<int> dp(n, 1);
        int maxre = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {

                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                    // cout<< "x" <<endl;
                }
            }
            maxre = max(maxre, dp[i]);
            //cout<< maxre <<endl;
        }
        return maxre;
    }
};

/**
 * 给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。

当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

注意：不允许旋转信封。

 
示例 1：

输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出：3
解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。


 * */

/**
 * 思路：
 * */
