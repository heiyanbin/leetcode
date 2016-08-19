// 146
// LRU Cache
// https://leetcode.com//problems/lru-cache/
class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            l.splice(l.begin(),l,mp[key]);
            mp[key]=l.begin();
            return mp[key]->value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        if(mp.find(key)!=mp.end())
        {    
            mp[key]->value=value;
            l.splice(l.begin(),l,mp[key]);
        }
        else if(mp.size()<capacity)
            l.push_front(CacheNode(key,value));
        else
        {
            mp.erase(l.back().key);
            l.pop_back();
            l.push_front(CacheNode(key,value));
        }
        mp[key]=l.begin();
    }
    
private:
    struct CacheNode
    {
        int key;
        int value;
        CacheNode(int k, int v): key(k),value(v){};
    };
    map<int,list<CacheNode>::iterator> mp;
    list<CacheNode> l;
    int capacity;
};