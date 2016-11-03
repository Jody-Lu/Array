#include <iostream>
#include <vector>

using namespace std;

vector<int> printRepeating(vector<int>& nums) {
    int XOR = nums[0];
    int x = 0, y = 0, n = nums.size();
    int set_bit;

    // xor nums[0, 1, 2, ... , n - 1]
    for(int i = 1; i < n; i++) {
        XOR ^= nums[i];
    }

    // xor [1, ..., n]
    for(int i = 1; i <= (n - 2); i++) {
        XOR ^= i;
    }

    // Now, XOR = x^y, where x, y is our target
    // Find set_bit
    set_bit = XOR & ~(XOR - 1);

    for(int i = 0; i < n; i++) {
        if(nums[i] & set_bit) {
            x ^= nums[i];
        }
        else {
            y ^= nums[i];
        }
    }

    for(int i = 1; i <= (n - 2); i++) {
        if(i & set_bit) {
            x ^= i;
        }
        else {
            y ^= i;
        }
    }

    vector<int> res;
    res.push_back(x);
    res.push_back(y);
    return res;
}


int main() {
    int arr[] = {4, 2, 4, 5, 2, 3, 1};
    vector<int> nums(arr, arr + 7);
    vector<int> res = printRepeating(nums);

    for(int n : res) {
        cout << n << " ";
    }

    cout << endl;
    return 0;
}
