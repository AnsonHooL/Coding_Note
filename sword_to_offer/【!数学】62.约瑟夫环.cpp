//
// Created by lenovo on 2020/12/9.
//

//数学法
class Solution {
public:
    int lastRemaining(int n, int m) {
//        list<int> mylist;
//        mylist.remove()

        int idx = 0; ///最终获胜者的下标必为0
        ///每次删除一个数字后，获胜者下标减少3
        ///反推上一轮，获胜者下标加3
        for(int i = 2; i<=n; i++)
        {
            idx = (idx + m) % i;
        }
        return idx;
    }
};



///第一轮：1 2 3 4 5 6 ，报数3，删除3
///第二轮：4 5 6 1 2   ，相当于每个数字下标前移了3
///因此第n轮，逆推n-1轮，就是每次下标 + m


//下面是暴力法
class Solution {
public:
    int lastRemaining(int n, int m) {
        list<int> mylist;
        for(int i =0;i<n;i++)
        {
            mylist.push_back(i);
        }
        auto it = mylist.begin();

        for(int i = 0;i<n-1;i++)
        {
            for(int j =0;j < m-1;j++)
            {
                it++;
                if(it == mylist.end()) it = mylist.begin();
            }
            // cout<< *it <<endl;
            mylist.erase(it++);
            if(it == mylist.end()) it = mylist.begin();
        }
        return *mylist.begin();

    }
};
