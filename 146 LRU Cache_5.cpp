// 146
// LRU Cache
// https://leetcode.com//problems/lru-cache/
class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)>0)
        {
            moveToEnd(key);
            return mp[key];
        }
        return -1;
    }
    
    void set(int key, int value) {
        if(mp.count(key)>0)
        {    
            mp[key]=value;
            moveToEnd(key);
        }
        else if(mp.size()<capacity)
        {
            mp[key]=value;
            l.push_back(key);
            pos[key]=getLast(l);
        }
        else
        {
            mp.erase(l.front());
            l.pop_front();
            mp[key]=value;
            l.push_back(key);
            pos[key]=getLast(l);
        }

    }
    void moveToEnd(int key)
    {
        l.erase(pos[key]);
        l.push_back(key);
        list<int>::iterator i= l.end();
        i--;
        pos[key]=i;
    }
    list<int>::iterator getLast(list<int> &l)
    {
        auto it = l.end();
        it--;
        return it;
    }
private:
    map<int,int> mp;
    map<int,list<int>::iterator> pos;
    list<int> l;
    int capacity;
};