class Solution {
public:
    // 0 -> 0, 1 -> 1, 6 -> 9, 8 -> 8, 9 -> 6
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        int n = num.size();

        for(int l = 0, r = n - 1; l <= r; l++, r--) {
            if(m.find(num[l]) == m.end() || m[num[l]] != num[r]) {
                return false;
            }
        }

        return true;
    }
};