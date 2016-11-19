class Solution {
public:

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        // corner case:
        if(n == 0) { return 0; }
        return countRangeSumHelper(nums, 0, n - 1, lower, upper);
    }

private:
    int countRangeSumHelper(vector<int>& nums, int begin, int end, int lower, int upper) {
        int mid = begin + (end - begin) / 2;
        int left, right, l = nums[mid], r = nums[mid + 1], count = 0;

        if(begin < end) {
            left = countRangeSumHelper(nums, begin, mid, lower, upper);
            right = countRangeSumHelper(nums, mid + 1, end, lower, upper);
        }
        else {
            return isValid(nums[begin], lower, upper);
        }

        long midSum = l + r, tmp;
        if(isValid(midSum, lower, upper)) { count++; }

        // left
        tmp = midSum;
        for(int i = mid - 1; i >= begin; i--) {
            tmp += nums[i];
            if(isValid(tmp, lower, upper)) {
                count++;
            }
        }

        // right
        tmp = midSum;
        for(int i = mid + 2; i <= end; i++) {
            tmp += nums[i];
            if(isValid(tmp, lower, upper)) {
                count++;
            }
        }

        // tmp = nums[mid] + nums[mid + 1]
        tmp = midSum;
        for(int i = mid - 1; i >= begin; i--) {
            tmp += nums[i];
            long tmptmp = tmp;
            for(int j = mid + 2; j <= end; j++) {
                tmptmp += nums[j];
                if(isValid(tmptmp, lower, upper)) {
                    //cout << tmp << " A: " << i << " " << j << endl;
                    count++;
                }
            }
        }
        //cout << left << " " << right << " " << count << endl;
        return (left + right + count);
    }

    bool isValid(long val, long lower, long upper) {
        return (val >= lower && val <= upper);
    }

};