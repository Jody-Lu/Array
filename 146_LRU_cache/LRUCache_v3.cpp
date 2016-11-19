class LRUCache{
public:
    LRUCache(int capacity): _capacity(capacity) {}

    int get(int key) {
        auto it = _cache.find(key); // check whether item exists
        if(it == _cache.end()) // not exist, return -1
            return -1;
        else { // exists
            touch(it); // touch!
            return it->second.first; // return its value
        }
    }

    void set(int key, int value) {
        auto it = _cache.find(key);
        if(it != _cache.end()) // key exists
            touch(it);
        else { // key doesn't exist
            if(_capacity == _cache.size()) {
                _cache.erase(_used.back()); // erase the least recently used item
                _used.pop_back(); // same above
            }
            _used.push_front(key); // add new item
        }
        // add new item
        // no matter the key exists or not
        // because of the situation that there exists same key but different value
        _cache[key] = make_pair(value, _used.begin());
    }

private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HPII;

    /* Reorder _used list*/
    void touch(HPII::iterator it) {
        int key = it->first; // get key
        _used.erase(it->second.second); // erase the old item
        _used.push_front(key); // move the most recent item to the front of _used 
        it->second.second = _used.begin(); // set item's new iterator
    }

    int _capacity; // capacity
    HPII _cache; // <key, pair<value, key_iterator>>
    LI _used; // record recently used items

};