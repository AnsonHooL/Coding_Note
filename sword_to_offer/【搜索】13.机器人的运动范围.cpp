//
// Created by lenovo on 2020/9/16.
//

struct local
{
    int m;
    int n;
    local(int A, int B) : m(A), n(B)
    {
    }
};

class Solution {
public:
    int movingCountBFS(int m, int n, int k) {
        vector<vector<int>> map;
        map.resize(m);
        int count = 0;
        for(int i=0;i<m;i++)
        {
            map[i].resize(n);
        }
        int row = map.size();
        int col = map[0].size();
        queue<local> bfsqueue;
        local point(0,0);
        bfsqueue.push(point);
        count++;
        map[0][0] = 999;
        while(!bfsqueue.empty())
        {
            local pot = bfsqueue.front();
            bfsqueue.pop();
            if(pot.m-1>=0 && pot.n>=0 && pot.m-1<=row-1 && pot.n<=col-1 && map[pot.m-1][pot.n]!=999 && countxx(pot.m-1,pot.n)<=k)
            {
                local tmp(pot.m-1,pot.n);
                bfsqueue.push(tmp);
                count++;
                map[pot.m-1][pot.n] =999;
            }
            if(pot.m+1>=0 && pot.n>=0 && pot.m+1<=row-1 && pot.n<=col-1 && map[pot.m+1][pot.n]!=999 && countxx(pot.m+1,pot.n)<=k)
            {
                local tmp(pot.m+1,pot.n);
                bfsqueue.push(tmp);
                count++;
                map[pot.m+1][pot.n] =999;
            }
            if(pot.m>=0 && pot.n-1>=0 && pot.m<=row-1 && pot.n-1<=col-1 && map[pot.m][pot.n-1]!=999 && countxx(pot.m,pot.n-1)<=k)
            {
                local tmp(pot.m,pot.n-1);
                bfsqueue.push(tmp);
                count++;
                map[pot.m][pot.n-1] =999;
            }
            if(pot.m>=0 && pot.n+1>=0 && pot.m<=row-1 && pot.n+1<=col-1 && map[pot.m][pot.n+1]!=999 && countxx(pot.m,pot.n+1)<=k)
            {
                local tmp(pot.m,pot.n+1);
                bfsqueue.push(tmp);
                count++;
                map[pot.m][pot.n+1] =999;
            }
        }
        return count;

    }
    int countxx(int m, int n)
    {
        return m/10+m%10+n%10+n/10;
    }
};

class SolutionDFS {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> map;
        map.resize(m);
        for(int i=0;i<m;i++)
        {
            map[i].resize(n);
        }

        return dfs(0,0,k,map);
    }
    int dfs(int m, int n,int k,vector<vector<int>>& map)
    {
        int row = map.size();
        int col = map[0].size();
        if( m<0 || n<0 || m>row-1 || n>col-1 || map[m][n] == 999 ||count(m,n) > k) return 0;
        map[m][n] = 999;
        return 1 + dfs(m-1,n,k,map) + dfs(m+1,n,k,map) + dfs(m,n-1,k,map) + dfs(m,n+1,k,map);
    }

    int count(int m, int n)
    {
        return m/10+m%10+n%10+n/10;
    }
};