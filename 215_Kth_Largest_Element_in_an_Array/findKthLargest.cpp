#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
    	int findKthLargest(vector<int>& nums, int k) {
        	return select(nums, nums.size() - k);
    	}
    private:
    	int select(vector<int> aList, int k) {
            int lo = 0, hi = aList.size() - 1;
            int m = medianOf3(aList, lo, lo + (hi - lo)/2, hi);
            exch(aList, m, lo);

            while(hi > lo) {
                int j = partition(aList, lo, hi);
                if(j < k)      lo = j + 1;
                else if(j > k) hi = j - 1;
                else           return aList[k];
            }
            return aList[k];
        }

        int partition(vector<int>& aList, int lo, int hi) {
            int i = lo, j = hi + 1;
            while(true) {
                /*Find item on left to swap. */
                while(aList[++i] < aList[lo])
                    /* aList is sorted. */
                    if(i == hi) break;

                /* Find item on right to swap. */
                while(aList[lo] < aList[--j])
                    /* aList is sorted. */
                    if(j == lo) break;

                /* Check if pointers cross. */
                if(i >= j) break;

                exch(aList, i, j);
            }
            /* Swap with partioning item. */
            exch(aList, lo, j);

            /* Return index of item now known to be in-place. */
            return j;
        }

        int medianOf3(vector<int>& a, int lo, int mid, int hi) {
            if(a[lo] < a[mid]) {
                if(a[lo] >= a[hi])
                    return lo;
                else if(a[mid] < a[hi])
                    return mid;
            }
            else {
                if(a[lo] < a[hi])
                    return lo;
                else if(a[mid] >= a[hi])
                    return mid;

            }
            return hi;
        }

        void exch(vector<int>& aList, int i, int j) {
            int tmp = aList[i];
            aList[i] = aList[j];
            aList[j] = tmp;
        }
};