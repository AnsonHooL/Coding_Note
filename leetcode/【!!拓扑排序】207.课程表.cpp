//
// Created by lenovo on 2021/1/12.
//

class Solution {
public:
    bool toposort(const vector<vector<int>>& graph, vector<int>& deg)
    {
        int n = graph.size();
        queue<int> Q;
        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            if(deg[i] == 0) Q.push(i);
        }
        while(!Q.empty())
        {
            int c = Q.front();
            res.push_back(c);
            Q.pop();
            for(int i = 0; i < n; i++)
            {
                if(graph[c][i] == 1)
                {
                    deg[i]--;
                    if(deg[i] == 0) Q.push(i);
                }
            }
        }
        if(res.size() == n) return true;
        else return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses < 2 || prerequisites.size() < 2)
            return true;
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0));

        vector<int> deg(numCourses, 0);
        for(auto pair : prerequisites)
        {
            graph[pair[1]][pair[0]] = 1;
            deg[pair[0]]++;
        }
        return toposort(graph, deg);
    }
};

/**
 * 你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]

给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？

 

示例 1:

输入: 2, [[1,0]]
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。


 最重要的是拓扑排序：得有一个入度数组，然后每次访问0入度的点即可
 * */