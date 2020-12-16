#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> re;
    vector<string> permutation(string s) {
        sort(s.begin(),s.end());
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

int main()
{
    Solution a;
    auto c = a.permutation("aab");
    for(auto x : c)
    {
//        cout<< x << endl;
    }

}