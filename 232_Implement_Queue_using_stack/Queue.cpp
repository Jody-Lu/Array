#include <stack>

using namespace std;

class Queue {
    public:
        void push(int x) {
            _input.push(x);
        }

        void pop() {
            peek();
            _output.pop();
        }

        int peek() {
            if(_output.empty()) {
                while(_input.size()) {
                    _output.push(_input.top());
                    _input.pop();
                }
            }
            return _output.top();
        }

        bool empty() {
            return _input.empty() && _output.empty();
        }
    private:
        stack<int> _input;
        stack<int> _output;
};

int main() {
    return 0;
}
