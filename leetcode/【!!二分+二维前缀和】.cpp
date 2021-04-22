//
// Created by lenovo on 2021/4/22.
//

/**思路一，用前缀和求任意大小矩形面积，朴素二维前缀和*/

///这题要注意公式怎么推导 +1 -1等等，看清楚我是晕了反正
class Solution {
public:
    int sum[1000][1000];
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        //vector<vector<int>> sum(m + 1,vector<int>(n + 1,0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        int ans = INT32_MIN;
//        for(int top = 1; top <= m; top++){
//            for(int bot = top; bot <= m; bot++){
//                set<int> st;
//                st.insert(0);
//                for(int r = 1; r <= n; r++){
//                    int right = sum[bot][r] - sum[top - 1][r];
//                    auto left = st.lower_bound(right - k);
//                    if(left != st.end()){
//                        int cur = right - *left;
//                        ans = max(ans,cur);
//                    }
//                    st.insert(right);
//                }
//            }
//        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                for(int r = 1; r <= i; r++){
                    for(int c = 1; c <= j; c++)
                    {
                        int cur = sum[i][j] + sum[r-1][c-1] - sum[r-1][j] - sum[i][c-1];
                        if(cur <= k){
                            ans = max(ans,cur);
                            if(ans == k) return k;
                        }
                    }
                }

            }
        }
        return ans;
    }
};

///思路二：利用区域前缀，四条边的矩形，确定了三条，只需要用二分查找剩下的一条就行
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sum(m + 1,vector<int>(n + 1,0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        int ans = INT_MIN;
        for(int top = 1; top <= m; top++){
            for(int bot = top; bot <= m; bot++){
                set<int> st;
                st.insert(0);
                for(int r = 1; r <= n; r++){
                    int right = sum[bot][r] - sum[top - 1][r];
                    auto left = st.lower_bound(right - k);
                    if(left != st.end()){
                        int cur = right - *left;
                        ans = max(ans,cur);
                    }
                    st.insert(right);
                }
            }
        }
        return ans;
    }
};

/**
 * 给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。

题目数据保证总会存在一个数值和不超过 k 的矩形区域。


 * */