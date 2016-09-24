#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

class NestedIterator {
    public:
        NestedIterator(vector<NestedInteger> &nestedList) {
            int n = nestedList.size();
            if(n == 0) return;
            deque<NestedInteger> curr, next;
            curr.push_back(nestedList[0]);
            int i = 1;
            while(!curr.empty()) {
                while(!curr.empty()) {
                    NestedInteger top = curr.back();
                    curr.pop_back();
                    if(top.isInteger()) {
                        if(next.empty()) 
                            items.push_front(top.getInteger());
                        else
                            next.push_front(top);
                    }
                    else {
                        vector<NestedInteger> tmp = top.getList();
                        for(int i = tmp.size() - 1; i >= 0; i--)
                            next.push_front(tmp[i]);
                    }
                }
                if(i < nestedList.size() && next.empty()) {
                    next.push_front(nestedList[i]);
                    i += 1;
                }
                swap(curr, next);
            }
        }

        int next() {
            int val = items.back();
            items.pop_back();
            return val;
        }

        bool hasNext() {
            return items.empty();
        }

    private:
        vector<int> items;

};

int main() {
    return 0;
}

