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
            moveToEnd(key);
            return mp[key];
        }
        return -1;
    }
    
    void set(int key, int value) {
        if(mp.find(key)!=mp.end())
        {    
            mp[key]=value;
            moveToEnd(key);
        }
        else if(mp.size()<capacity)
        {
            mp[key]=value;
            l.push_back(key);
            pos[key]=prev(l.end());
        }
        else
        {
            mp.erase(l.front());
            l.pop_front();
            mp[key]=value;
            l.push_back(key);
            pos[key]=prev(l.end());
        }
    }
    void moveToEnd(int key)
    {
        l.erase(pos[key]);
        l.push_back(key);
        pos[key]=prev(l.end());
    }
private:
    map<int,int> mp;
    map<int,list<int>::iterator> pos;
    list<int> l;
    int capacity;
};