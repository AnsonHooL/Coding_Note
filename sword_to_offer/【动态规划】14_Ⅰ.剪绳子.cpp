//
// Created by lenovo on 2020/9/18.
//
//减绳子
class Solution {
public:
    int cuttingRope(int n) {

        vector<uint64_t > dp;
        dp.push_back(0);
        dp.push_back(1);
        for(int i=2;i<=n;i++)
        {
            dp.push_back( dynamic(i,dp) );
        }
        return dp[n];
    }
    int dynamic(int n, vector<uint64_t >& dp)
    {
        int max = 0;
        for(int i=1; i<=n/2; i++)
        {
            int c1 = dp[i]*dp[n-i];
            if(max<c1) max=c1;
            int c2 = dp[i]*(n-i);
            if(max<c2) max=c2;
            int c3 = i*dp[n-i];
            if(max<c3) max=c3;
            int c4 = i*(n-i);
            if(max<c4) max=c4;
        }
        return max%1000000007;
    }

};