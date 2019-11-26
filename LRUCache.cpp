
class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity)
    {    
    }
    
    int get(int key)
    {
        auto iter = keyvalue.find(key);
        if(iter == keyvalue.end())
            return -1;
        else
        {
            //删掉重新插入
            auto del = *keyvalue[key];
            keylist.erase(keyvalue[key]);
            keylist.push_front(del);
            keyvalue[key] = keylist.begin();
            return del.second;
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        auto iter = keyvalue.find(key);
        //如果哈希表中没有
        if(iter == keyvalue.end())
        {
            //当前容量是否已满
            if(keyvalue.size() == cap)
            {
                //删除链表尾部的key
                auto del = keylist.back();
                int lastkey = del.first;
                keyvalue.erase(lastkey);
                keylist.pop_back();
            }

        }
        else
        {
            //已经有了，删除后头插
            keylist.erase(iter->second);
            keyvalue.erase(iter);
        }
        keylist.push_front(make_pair(key,value));
        keyvalue[key] = keylist.begin();
    }
    int cap = 0;
    std::list<std::pair<int,int>> keylist;
    std::unordered_map<int, list<pair<int,int>>::iterator> keyvalue;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */