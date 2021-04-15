//
// Created by lenovo on 2021/4/14.
//

class Trie {
public:
    /** Initialize your data structure here. */
    vector<bool> v;
    vector<Trie*> p;
    Trie() : v(26, false), p(26, nullptr)
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* t;
        char c = word[0];
        int index = c - 'a';
        if(p[index])
        {
            t = p[index];
            if(word.size() == 1)
                v[index] = true;
            else
                t->insert(word.substr(1));
        }
        else
        {
            p[index] = new Trie;
            if(word.size() == 1)
                v[index] = true;
            else
                p[index]->insert(word.substr(1));
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* t;
        char c = word[0];
        int index = c - 'a';

        if(p[index])
        {
            t = p[index];
            if(word.size() == 1)
            {
                return v[index] ?  true: false;
            }
            else
                return t->search(word.substr(1));

        } else
        {
            return false;
        }

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        string word = prefix;
        Trie* t;
        char c = word[0];
        int index = c - 'a';

        if(p[index])
        {
            t = p[index];
            if(word.size() == 1)
                return true;
            else
                return t->search(word.substr(1));

        } else
        {
            return false;
        }

    }
};

/**
 * Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。




 思路：这里可以优化bool。只需要一个bool作为终结点就行，但是需要多开一个数组貌似。
 *
 * */