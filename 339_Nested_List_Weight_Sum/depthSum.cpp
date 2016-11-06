class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int res = 0;

        for(int i = 0; i < nestedList.size(); i++) {
            depthSumHelper(res, 1, nestedList[i]);
        }

        return res;
    }

    void depthSumHelper(int& res, int depth, NestedInteger ins) {
        if(ins.isInteger()) {
            res += depth * ins.getInteger();
            return;
        }

        vector<NestedInteger> li = ins.getList();

        for(int i = 0; i < li.size(); i++) {
            depthSumHelper(res, depth + 1, li[i]);
        }
    }
};