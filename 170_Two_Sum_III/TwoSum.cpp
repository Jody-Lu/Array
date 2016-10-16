#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    _mapping[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(auto it = _mapping.begin(); it != _mapping.end(); it++) {
	        int gap = value - it->first;
	        auto itt = _mapping.find(gap);
	        if(itt != _mapping.end()) {
	            if(itt != it) return true;
	            else if(it->second > 1) return true;
	        }
	    }
	    return false;
	}
private:
    unordered_map<int, int> _mapping;
};

int main() {
    TwoSum t;
    t.add(3);
    t.add(1);
    t.add(2);
    cout << t.find(3) << endl;
}
