#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// http://stackoverflow.com/questions/1761626/weighted-random-numbers

using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) != m.end()) {
            return false;
        }
        nums.emplace_back(val);
        m[val].emplace_back(nums.size() - 1);
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    // ******
    bool remove(int val) {
        if(m.find(val) == m.end()) {
            return false;
        }
        int last = nums.back();
        int idx_val =  m[val].back();   
        m[val].pop_back();
        
        if(m[val].empty()) {
            m.erase(val);
        }

        nums[idx_val] = last;
        m[last].erase(nums.size() - 1);
        m[last].emplace_back(idx_val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int random = rand() % nums.size();
        for(auto it = m.begin(); it != m.end(); it++) {
            random -= (it->second).size();
            if(random < 0) {
                return it->first;
            }
        }
    }
private:
    vector<int> nums;
    unordered_map<int, vector<int> > m;
};
