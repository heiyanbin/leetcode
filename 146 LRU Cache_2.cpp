// 146
// LRU Cache
// https://leetcode.com//problems/lru-cache/
class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it =mp.find(key);
        if(it!=mp.end())
        {
            l.splice(l.begin(),l,it->second);
            it->second=l.begin();
            return it->second->value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        auto it =mp.find(key);
        if(it!=mp.end())
        {    
            it->second->value=value;
            l.splice(l.begin(),l,it->second);
            it->second=l.begin();
        }
        else
        {
            if(mp.size()>=capacity)
            {
                mp.erase(l.back().key);
                l.pop_back();
            }
            l.push_front(CacheNode(key,value));
            mp[key]=l.begin();
        }
    }
private:
    struct CacheNode
    {
        int key;
        int value;
        CacheNode(int k, int v): key(k),value(v){};
    };
    unordered_map<int,list<CacheNode>::iterator> mp;
    list<CacheNode> l;
    int capacity;
};