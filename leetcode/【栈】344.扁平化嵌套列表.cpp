//
// Created by lenovo on 2021/3/23.
//

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
public:
    vector<int> v;
    int pos = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }

    int next() {
        return v[pos++];

    }

    bool hasNext() {
        return pos < v.size();
    }
    void dfs(const vector<NestedInteger> &nestedList)
    {
        int size = nestedList.size();
        for(int i = 0; i < size; i++)
        {
            if(nestedList[i].isInteger()) v.push_back(nestedList[i].getInteger());
            else dfs(nestedList[i].getList());
        }
    }
};

/**
 * 给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。

列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。

 

示例 1:

输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
示例 2:

输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,4,6]。


 * */
