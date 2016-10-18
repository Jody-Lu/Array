class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int n = digits.size();
        int carry = 0;

        // no carry bit
        if(++digits[n - 1] < 10)
            return digits;

        for(int i = n - 1; i >= 0; i--) {
            int tmp = digits[i];
            digits[i] = (digits[i] + carry) % 10;
            carry = (tmp + carry) / 10;
        }

        if(carry > 0) digits.insert(digits.begin(), carry);

        return digits;
    }
};