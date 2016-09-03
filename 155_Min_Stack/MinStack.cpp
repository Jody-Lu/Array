#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    public:
        MinStack() {}

        void push(int x) {
            if(s2.empty() || x <= getMin()) s2.push(x);
            s1.push(x);
        }
        void pop() {
            if(s1.top() == getMin()) s2.pop();
            s1.pop();
        }
        int top() { return s1.top(); }
        int getMin() { return s2.top(); }

    private:
        stack<int> s1;
        stack<int> s2;
};


int main() {
    return 0;
}
