//
// Created by lenovo on 2021/1/12.
//

class Solution {
public:
    vector<int> toposort(const vector<vector<int>>& graph, vector<int>& deg, vector<int>& ids)
    {
        queue<int> Q;
        vector<int> res;
        for(auto x: ids)
        {
            if(deg[x] == 0) Q.push(x);
        }
        while(!Q.empty())
        {
            int c = Q.front();
            res.push_back(c);
            Q.pop();
            for(auto i : graph[c])
            {
                deg[i]--;
                if(deg[i] == 0) Q.push(i);
            }
        }
        if(res.size() == ids.size()) return res;
        else return vector<int>{};
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        vector<vector<int>> Groupitem(n+m);///保存每个组做哪些项目

        int leftid = m;
        for(int i = 0; i < n; i++)
        {
            if(group[i] == -1) group[i] = leftid++;
            Groupitem[group[i]].push_back(i);
        }

        vector<int> itemdegree(n, 0);///项目的入度
        vector<int> groupdegree(n+m, 0);///小组的入度

        vector<vector<int>> itemgraph(n); ///第i个则装着，他指向的item, 小组内项目的依赖关系
        vector<vector<int>> groupgraph(n + m); /// 第i个则装着，他指向的group,  小组的依赖关系 如果用图的话，时间复杂度太高了

        for(int i = 0; i < n; i++)
        {
            auto& vec = beforeItems[i];
            int groupID = group[i]; ///哪个小组
            for(auto item : vec)
            {
                int groupitemID = group[item];

                if(groupitemID == groupID) ///组内依赖
                {

                    itemgraph[item].push_back(i);
                    itemdegree[i]++;
                }
                else ///组间依赖
                {
                    groupgraph[groupitemID].push_back(groupID);
                    groupdegree[groupID]++;
                }
            }
        }
        vector<int> groupids(n+m);

        for(int i = 0; i < n+m; i++) groupids[i] = i;

        vector<int> Grouptopo = toposort(groupgraph, groupdegree, groupids);

        if(Grouptopo.size() == 0) return vector<int>{};

        vector<int> re;
        for(auto& g : Grouptopo)
        {
            if(Groupitem[g].empty()) continue;
            auto revec = toposort(itemgraph, itemdegree, Groupitem[g]); ///组内依赖关系
            if(revec.size() == 0) return vector<int>{};
            else
            {
                for(auto x : revec) re.push_back(x);
            }
        }

        return re;
    }
};

/**
 * 公司共有 n 个项目和  m 个小组，每个项目要不无人接手，要不就由 m 个小组之一负责。

group[i] 表示第 i 个项目所属的小组，如果这个项目目前无人接手，那么 group[i] 就等于 -1。（项目和小组都是从零开始编号的）小组可能存在没有接手任何项目的情况。

请你帮忙按要求安排这些项目的进度，并返回排序后的项目列表：

同一小组的项目，排序后在列表中彼此相邻。
项目之间存在一定的依赖关系，我们用一个列表 beforeItems 来表示，其中 beforeItems[i] 表示在进行第 i 个项目前（位于第 i 个项目左侧）应该完成的所有项目。
如果存在多个解决方案，只需要返回其中任意一个即可。如果没有合适的解决方案，就请返回一个 空列表 。



 思路：
 1.这里不仅有组内项目的拓扑排序，还有小组之间的拓扑排序
 2.入度图哪里不要 n *n ，时间复杂度太高，可以每个点对应的vector只把自己的点包进来。
 * */