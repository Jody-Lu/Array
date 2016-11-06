#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "()())()";
    cout << s << endl;
    char tmp = *(s.begin() + 3);
    s.erase(s.begin() + 3);
    cout << s << endl;
    s.insert(s.begin() + 3, tmp);
    cout << s << endl;
}
