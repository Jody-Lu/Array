#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename Key, typename Value>
class ST {
    public:
        ST() { N = 0; }
    
        void put(Key key, Value val) {
            _keys.push_back(key);
            _values.push_back(val);
            N++;
        }

        Value get(Key key) {
            if(isEmpty()) return (Value)NULL;
            int i = rank(key);
            if(i < N && _keys[i] == key) return _values[i];
            else return (Value)NULL;
        }

        bool contains(Key key) {
            
        }
        
        void del(Key key) {
            
        }
        
        bool isEmpty() {
            return _keys.empty() && _values.empty();
        }
        int size() {
            
        }
    private:
        int rank(Key key) {
            /* Binary Search */
            int lo  = 0, hi = N - 1;
            while(lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if(key == mid) return mid;
                if(key > mid) lo = mid + 1;
                else hi = mid - 1;
            }
            return lo;
        }

        vector<Key> _keys;
        vector<Value> _values;
        int N;

};


int main() {
    ST<int, char> st;
    string s = "ABCDEFGHIJK";
    for(int i = 0; i < s.size(); i++)
        st.put(i, s[i]);
    
    cout << st.get(3) << endl;
}
