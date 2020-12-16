//
// Created by lenovo on 2020/9/29.
//
/***输入abc 输出字符串的排序：abc acb bca bac cab cba 不能重复
 *思路一：用set做去重
 *思路二：先排序，然后再用回溯做？不需要用set，因为前面的字母已经试过了所以没必要，再弄
 *
 *
 *
 *
 *
 * ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 * 思路三： 不用排序，用这个思路，从左到右，每次固定一个位置，那么这个位置上，每个字母只能出现一次
 * 不断地递归，从左到右，每次固定一个位置的字母,dfs，固定固定固定，出现多一次的剪枝剪掉
 *
 * **/

/***解法一***/
class Solution {
public:
    vector<string> res;
    unordered_set<string> myset;
    vector<string> permutation(string s) {
        if(s.size() == 0) return res;
        string src;
        dfs(s, src,0);
        return res;
    }
    void dfs(string& s, string src, int p)
    {
        if(p == s.size()  && myset.find(src) == myset.end())
        {
            myset.insert(src);
            res.push_back(src);
        }

        for(int i=0; i<s.size() ;i++)
        {
            if(s[i] == '#') continue;
            src.push_back(s[i]);
            char tmp = s[i];
            s[i] = '#';
            p++;
            dfs(s,src,p);
            p--;
            s[i] = tmp;
            src.pop_back();
        }

    }
};

/***解法二***/
class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        if(s.size() == 0) return res;
        sort(s.begin(),s.end());
        string src;
        dfs(s, src,0);
        return res;
    }
    void dfs(string& s, string src, int p)
    {
        if(p == s.size()  )
        {
            res.push_back(src);
        }

        for(int i=0; i<s.size() ;i++)
        {
            if(s[i] == '#' || (i>0 && s[i] == s[i-1])) continue;
            src.push_back(s[i]);
            char tmp = s[i];
            s[i] = '#';
            p++;
            dfs(s,src,p);
            p--;
            s[i] = tmp;
            src.pop_back();
        }

    }
};


///解法二的另一个实现版本
class Solution {
public:
    vector<string> re;
    vector<string> permutation(string s) {
        // sort(s.begin(),s.end());
        dfs(s,0);
        return re;

    }
    void dfs(string s,int pos)
    {
        if(pos == s.size()-1)
        {
            re.push_back(s);
            cout<< s << endl;
            return;
        }
        set<char> myset;
        for(int i = pos; i < s.size();i++)
        {
            if(myset.find(s[i]) == myset.end())
            {
                myset.insert(s[i]);
                swap(s[i],s[pos]);
                dfs(s,pos+1);
                swap(s[pos],s[i]);
            }
        }
    }
};