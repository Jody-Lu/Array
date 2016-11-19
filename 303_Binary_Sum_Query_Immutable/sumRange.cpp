class NumArray {
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        sums.resize(n + 1);
        sums[0] = 0;
        for(int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int i, int j) {
        return (sums[j + 1] - sums[i]);
    }

private:
    // sums[i] = sum(nums[0]...nums[i-1])
    vector<int> sums;
};
