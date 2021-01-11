//
// Created by lenovo on 2021/1/11.
//

class Solution {
public:
    int findfa(int x, vector<int>& fa)
    {
        if(fa[x] == x) return x;
        else
        {
            fa[x] = findfa(fa[x], fa);
            return fa[x];
        }
    }

    void merge(int x, int y, vector<int>& fa)
    {
        int xf = findfa(x, fa);
        int yf = findfa(y, fa);
        fa[xf] = yf;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> fa(n,1);
        for(int i = 0; i < n; i++) fa[i] = i;
        for(auto pair : pairs)
        {
            int x = pair[0];
            int y = pair[1];
            merge(x, y, fa);
        }

        int count = 0;
        unordered_map<int, vector<int>> mymap;
        for(int i = 0; i < n; i++)
        {
            int xfa = findfa(i,fa);
            //    if(mymap.find(xfa) == mymap.end()) mymap[xfa] = vector<int>{s[i]};
            //    else mymap[xfa].push_back(s[i]);
            mymap[xfa].push_back(s[i]); ///可以直接pushback
        }
        for(auto& x: mymap)
        {
            sort(x.second.begin(), x.second.end(), greater<int>()); ///这里greater<int>要加括号，传入一个对象
        }
        for(int i = 0; i < n; i++)
        {
            s[i] = mymap[findfa(i,fa)].back();
            // cout<< s[i] << endl;
            mymap[findfa(i,fa)].pop_back(); ///巧妙退出
        }

        return s;
    }
};

/**
 * 给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，其中 pairs[i] = [a, b] 表示字符串中的两个索引（编号从 0 开始）。

你可以 任意多次交换 在 pairs 中任意一对索引处的字符。

返回在经过若干次交换后，s 可以变成的按字典序最小的字符串。

 

示例 1:

输入：s = "dcab", pairs = [[0,3],[1,2]]
输出："bacd"
解释：
交换 s[0] 和 s[3], s = "bcad"
交换 s[1] 和 s[2], s = "bacd"
示例 2：

输入：s = "dcab", pairs = [[0,3],[1,2],[0,2]]
输出："abcd"
解释：
交换 s[0] 和 s[3], s = "bcad"
交换 s[0] 和 s[2], s = "acbd"
交换 s[1] 和 s[2], s = "abcd"



 思路：并查集找出字符联通，然后再按找联通的字符进行排序，
 这道题最麻烦是最后的排序，如何优化时间复杂度的问题
 * */