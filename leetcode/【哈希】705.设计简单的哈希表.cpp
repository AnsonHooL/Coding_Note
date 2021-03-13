//
// Created by lenovo on 2021/3/13.
//

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {

    }

    void add(int key) {
        _hash[key] = true;
    }

    void remove(int key) {
        _hash[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return _hash[key];
    }

    bitset<1000001> _hash;
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

/**
 * 自建哈希表，用了C++的 bitset学习使用
 *
 * */