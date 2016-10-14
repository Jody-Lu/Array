#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>

using namespace std;

class LRUCache {
    public:
        LRUCache(int capacity): _capacity(capacity) {}

        int get(int key) {
            auto it = _cache.find(key);
            if(it == _cache.end()) return -1;
            touch(it);
            return it->second.first;
        }

        void set(int key, int value) {
            auto it = _cache.find(key);
            /* key exists */
            if(it != _cache.end()) touch(it);
            else {
                /* Meet the maximum capacity. */
                /* Remove the least recently used (i.e., the last element in _used)*/
                /* Both from _used and _cache. */
                if(_cache.size() == _capacity) {
                    _cache.erase(_used.back());
                    _used.pop_back();
                }
                /* Add the new element to most recently used. */
                _used.push_front(key);
            }
            _cache[key] = make_pair(value, _used.begin());
        }
    
    private:
        typedef list<int> LI;
        // pair value with its key in _used
        typedef pair<int, LI::iterator> PII;
        // mapping value to its key
        typedef unordered_map<int, PII> HPII;
        
        /* To reorganized the recentlu used sequence. */
        void touch(HPII::iterator it) {
            int key = it->first;
            _used.erase(it->second.seond);
            _used.push_front(key);
            it->second.second = _used.begin();
        }

        LI _used; // memorized the used sequence
        HPII _cahce;
        int _capacity;
};

int main() {
    LRUCache c(100);

}
