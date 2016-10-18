#include <unordered_map>
#include <list>
#include <utility>

using namespace std;


class LRUCache {
    public:
        LRUCache(int capacity): _capacity(capacity) {}

        int get(int key) {
            auto it = _cache.find(key);
            if(it == _cache.end())
                return -1;
            touch(it);
            return it->second.first;
        }

        void set(int key, int value) {
            auto it = _cache.find(key);
            if(it != _cache.end()) touch(it);
            else {
                if(_cache.size() == _capacity) {
                    _cache.erase(_used.back());
                    _used.pop_back();
                }
                _used.push_front(key);
            }
            // same key may map to different value.
            _cache[key] = make_pair(value, _used.begin());
        }

    private:
        typedef list<int> LI;
        // pair<value, key iterator>
        typedef pair<int, LI::iterator> PII;
        typedef unordered_map<int, PII> HIPII;

        void touch(HIPII::iterator it) {
            int key = it->first;
            // that's why map'a value is (value, iterator) pair.
            _used.erase(it->second.second);
            _used.push_front(key);
            it->second.second = _used.begin();
        }

        HIPII _cache;
        LI _used;
        int _capacity;
};


int main() {
    return 0;
}
