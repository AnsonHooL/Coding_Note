//
// Created by lenovo on 2021/6/6.
//

class LRUCache {
public:
    struct LRUlist{
        LRUlist* prev;
        LRUlist* next;
        int val;
        int key;
        LRUlist(int k): key(k) {}
        LRUlist() = default;
    };
    unordered_map<int, LRUlist*> map;

    LRUlist head;
    LRUlist tail;

    LRUCache(int capacity) {
        head.next = &tail;
        head.prev = nullptr;
        tail.prev = &head;
        tail.next = nullptr;
        for(int i = 0; i < capacity; i++){
            auto t = new LRUlist(-1);
            t->next = head.next;
            t->prev = &head;
            head.next->prev = t;
            head.next = t;

        }
    }

    void topLRUlist(LRUlist* t){

        t->prev->next = t->next;
        t->next->prev = t->prev;


        t->next = head.next;
        head.next->prev = t;
        head.next = t;
        t->prev = &head;

    }


    void setLRUlist(int key, int value){
        LRUlist* t = tail.prev;

        if(t->key != -1)
            map.erase(t->key);

        t->val = value;
        t->key = key;

        topLRUlist(t);

        map[key] = t;
    }

    LRUlist* getLRUlist(int key){
        auto iter = map.find(key);
        if(iter == map.end()){
            return NULL;
        } else{
            return iter->second;
        }
    }


    int get(int key) {
        auto t = getLRUlist(key);
        if(t == NULL) return -1;
        else
            topLRUlist(t);
        return t->val;

    }

    void put(int key, int value) {
        auto t = getLRUlist(key);
        if(t != NULL){
            t->val = value;
            topLRUlist(t);
        } else{
            setLRUlist(key, value);
        }
    }
};

/****
 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

 

 * **/