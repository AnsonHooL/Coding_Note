//
// Created by lenovo on 2021/1/6.
//
/**思路一：Floyd思路*/
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        unordered_map<string, int> mymap;
        int nvar = 0;
        for(auto& x : equations)
        {
            if(mymap.find(x[0]) == mymap.end()) mymap[x[0]] = nvar++; ///建立索引
            if(mymap.find(x[1]) == mymap.end()) mymap[x[1]] = nvar++;
        }
        vector<vector<double>> Graph(nvar, vector<double>(nvar, 0));

        for(int i = 0; i < nvar; i++) Graph[i][i] = 1.0;

        for(int i = 0; i < n; i++)
        {
            int left  = mymap[equations[i][0]];
            int right = mymap[equations[i][1]];
            Graph[left][right] = values[i];
            Graph[right][left] = 1 / values[i];
        }
        for(int k = 0; k < nvar; k++)   ///外层循环是点，每加一个点，遍历所有边
        {
            for(int i = 0; i < nvar; i++)
            {
                for(int j = 0; j < nvar; j++)
                {
                    if(Graph[i][k] != 0 && Graph[k][j] != 0)
                    {
                        Graph[i][j] = Graph[i][k] * Graph[k][j];
                    }
                }
            }
        }

        vector<double> re;
        for(auto& x : queries)
        {
            double num = -1.0;
            if(mymap.find(x[0]) != mymap.end() && mymap.find(x[1]) != mymap.end())
            {
                int left  = mymap[x[0]];
                int right = mymap[x[1]];
                if(Graph[left][right] != 0) num = Graph[left][right];
            }
            re.push_back(num);
        }
        return re;
    }
};


/**思路二：广搜*/

class Solution {
public:
    double bfs(vector<vector<double>>Graph, int lhs, int rhs)
    {
        if(Graph[lhs][rhs] != 0) return Graph[lhs][rhs];
        int n = Graph.size();
        vector<int> flag(n,0);
        flag[lhs] = 1;
        queue<int> myqueue;
        myqueue.push(lhs);
        while(!myqueue.empty())
        {
            int size = myqueue.size();
            for(int i = 0; i < size; i++)
            {
                int num = myqueue.front();
                myqueue.pop();
                for(int j = 0; j < n; j++)
                {
                    if(Graph[num][j] != 0 && flag[j] == 0)
                    {
                        Graph[lhs][j] = Graph[lhs][num] * Graph[num][j];
                        flag[j] = 1;
                        myqueue.push(j);
                    }
                }
            }
        }

        if(Graph[lhs][rhs]) return Graph[lhs][rhs];
        else return -1.0;

    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        unordered_map<string, int> mymap;
        int nvar = 0;
        for(auto& x : equations)
        {
            if(mymap.find(x[0]) == mymap.end()) mymap[x[0]] = nvar++;
            if(mymap.find(x[1]) == mymap.end()) mymap[x[1]] = nvar++;
        }
        vector<vector<double>> Graph(nvar, vector<double>(nvar, 0));
        for(int i = 0; i < nvar; i++) Graph[i][i] = 1.0;
        for(int i = 0; i < n; i++)
        {
            int left  = mymap[equations[i][0]];
            int right = mymap[equations[i][1]];
            Graph[left][right] = values[i];
            Graph[right][left] = 1 / values[i];
        }

        vector<double> re;

        for(auto& x : queries)
        {
            double num = -1.0;

            if(mymap.find(x[0]) != mymap.end() && mymap.find(x[1]) != mymap.end())
            {
                int left  = mymap[x[0]];
                int right = mymap[x[1]];
                num = bfs(Graph, left, right);
            }

            re.push_back(num);
        }
        return re;
    }
};


/**并查集 **/


///每个点都有父节点，那么一个集合的点构成一棵树，但是这样搜索的时候是树的高度
///主要是两个操作 find 、 merge。find就是递归找到这个结点的祖宗结点，merge就是把不在一个集合的两个点合并
///压缩路径能解决每次搜索都是树的高度

///这道题里用了压缩路径，使得集合所有点都有同一个root结点，这样路径就压缩了，还能使得一个集合的点都能用root结点作为中介计算除法
///这题还是带状态的并查集，有点难度
class Solution {
public:
    int findroot(vector<int>& root, vector<double>& wvalue, int x) ///压缩路径
    {
        if(root[x] != x)
        {

            int xroot = root[x];
            root[x] = findroot(root, wvalue, xroot);
            wvalue[x] = wvalue[xroot] * wvalue[x];
            return root[x];
        } else return x;
    }
    void merge(vector<int>& root, vector<double>& wvalue, int x, int y, double values)
    {
        int xroot = findroot(root, wvalue, x); ///这时候一条线上的结点都变成了同一个root结点
        int yroot = findroot(root, wvalue, y);
        root[xroot] = yroot;
        wvalue[xroot] = (wvalue[y] / wvalue[x]) * values; /// 设置 x的root的root是 ， y的root
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size(); ///等式的个数
        unordered_map<string, int> mymap;
        int nvar = 0; ///字符串的个数
        for(auto& x : equations)
        {
            if(mymap.find(x[0]) == mymap.end()) mymap[x[0]] = nvar++;
            if(mymap.find(x[1]) == mymap.end()) mymap[x[1]] = nvar++;
        }

        vector<int> root(nvar, 0); ///保存每个结点的父亲结点
        vector<double> wvalue(nvar, 0); ///保存（每个结点的值/父亲结点的值）（父亲结点作为中介点）

        for(int i = 0; i < nvar; i++) root[i]   = i;
        for(int i = 0; i < nvar; i++) wvalue[i] = 1;

        for(int i = 0; i < n; i++)
        {
            int x = mymap[equations[i][0]];
            int y = mymap[equations[i][1]];
            merge(root, wvalue, x, y, values[i]);
        }


        vector<double> re;

        for(auto& x : queries)
        {
            double num = -1.0;

            if(mymap.find(x[0]) != mymap.end() && mymap.find(x[1]) != mymap.end())
            {
                int left  = mymap[x[0]];
                int right = mymap[x[1]];
                int leftroot  = findroot(root, wvalue, left);
                int rightroot = findroot(root, wvalue, right);
                if(leftroot == rightroot)///在同一个集合
                {
                    num = wvalue[left] / wvalue[right];
                }

            }

            re.push_back(num);
        }
        return re;
    }
};


/**
 * 给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。

另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。

返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。

 

注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。

 

示例 1：

输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
解释：
条件：a / b = 2.0, b / c = 3.0
问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]


 思路：就是一道图的题目，a/b b/c 得到 a/c
 1.最简单的思路就是floyd，求所有点-点的最短距离
 2.广搜
 3.并查集（同一个集合里所有元素，同一个root，然后保存一个 w = 自己的值 / root的值 即可，那么只要判断两个数相除，是否在同一个集合里面即可）
 * */