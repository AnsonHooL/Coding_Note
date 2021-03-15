//
// Created by lenovo on 2021/3/14.
//

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() : buckets(797){

    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % 797;
        auto iter = buckets[index].begin();
        while(iter != buckets[index].end())
        {
            if((*iter).first == key)
            {
                (*iter).second = value;
                return;
            }
            iter++;
        }
        buckets[index].emplace_front(make_pair(key,value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key % 797;
        auto iter = buckets[index].begin();
        while(iter != buckets[index].end())
        {
            if((*iter).first == key) return (*iter).second;
            iter++;
        }
        return -1;
    }


    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = key % 797;
        auto iter = buckets[index].begin();
        while(iter != buckets[index].end())
        {
            if((*iter).first == key)
            {
                buckets[index].erase(iter);
                return;
            }
            iter++;
        }
    }

    vector<list<pair<int,int>>> buckets;

};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

 /**
  * 思路：用了vector 和 list 简单实现了一个哈希表
  * */