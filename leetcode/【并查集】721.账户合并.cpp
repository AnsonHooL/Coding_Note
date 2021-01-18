//
// Created by lenovo on 2021/1/18.
//

class Solution {
public:
    int find(int x ,vector<int>& father)
    {
        if(x == father[x]) return x;
        else
        {
            father[x] = find(father[x], father);
            return father[x];
        }
    }

    void merge(int x, int y, vector<int>& father)
    {
        int xf = find(x, father);
        int yf = find(y, father);
        father[xf] = yf;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int usernum = 0;
        vector<int> father(2000);
        for(int i = 0; i < 2000; i++)
            father[i] = i;
        unordered_map<string, int> emailmap; ///string -> id,邮箱对应id
        unordered_map<int, string> usermap;///id 对应用户名


        for(auto& account : accounts)
        {
            string& accountname = account[0];
            bool olduser = false;
            int oldacount = 0;
            vector<int> olduserid;
            for(int i = 1; i < account.size(); i++)
            {
                if(emailmap.find(account[i]) != emailmap.end())
                {
                    olduser = true;
                    oldacount = emailmap[account[i]];
                    olduserid.push_back(emailmap[account[i]]);
                }
            }

            if(!olduser)
            {
                usermap[usernum] = accountname;
                for(int i = 1; i < account.size(); i++)
                {
                    emailmap[account[i]] = usernum;
                }
                usernum++;
            } else
            {
                for(int i = 1; i < account.size(); i++)
                {
                    emailmap[account[i]] = oldacount;
                }

                olduserid.pop_back();

                for(auto id : olduserid)
                {
                    merge(id, oldacount, father);
                }
            }
        }

        int realid = 0;
        set<int> myset;
        for(int i = 0; i < usernum; i++) myset.insert(find(i,father));

        vector<vector<string>> res(myset.size());

        int k = 0;
        unordered_map<int,int> mymap;
        for(auto id : myset)
        {
            res[k].push_back(usermap[find(id, father)]);
            mymap[find(id, father)] = k;
            k++;
        }

        for(auto email : emailmap)
        {
            res[mymap[find(email.second, father)]].push_back(email.first);
        }

        for(auto& re: res)
        {
            sort(re.begin() + 1, re.end());
        }
        return res;
    }
};

/**
 *给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其余元素是 emails 表示该账户的邮箱地址。

现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。

合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按顺序排列的邮箱地址。账户本身可以以任意顺序返回。

 

示例 1：

输入：
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
输出：
[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
解释：
第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。
第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的。


 思路: 就是哈希表加并查集，太恶心了
 
 * */
