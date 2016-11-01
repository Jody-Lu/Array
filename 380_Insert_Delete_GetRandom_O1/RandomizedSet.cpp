#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // val exists
        if(m.find(val) != m.end()) {
            return false;
        }
        _nums.emplace_back(val);
        m[val] = _nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end()) {
            return false;
        }
        int last = _nums.back();
        // move last element to val
        m[last] = m[val];
        _nums[m[val]] = last;
        _nums.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return _nums[rand() % _nums.size()];
    }
private:
    vector<int> _nums;
    unordered_map<int, int> m;
};
