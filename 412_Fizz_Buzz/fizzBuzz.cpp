class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i = 1; i <= n; i++) {
            string tmp = "";
            if(i % 3 == 0) {
                tmp.append("Fizz");
            }
            if(i % 5 == 0) {
                tmp.append("Buzz");
            }
            res.push_back(tmp.empty()? to_string(i) : tmp);
        }

        return res;
    }
};