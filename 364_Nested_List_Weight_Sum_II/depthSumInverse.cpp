class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> res;
        int sum = 0;

        for(auto ins : nestedList) {
            depthSumInverseHelper(res, 0, ins);
        }

        for(int i = res.size() - 1, level = 1; i >= 0; i--, level++) {
            sum += (level * res[i]);
        }

        return sum;
    }

private:

    void depthSumInverseHelper(vector<int>& res, int depth, NestedInteger ins) {
        if(res.size() < (depth + 1)) {
            res.resize(depth + 1);
        }

        if(ins.isInteger()) {
            res[depth] += ins.getInteger();
        }
        else {
            for(auto nes : ins.getList()) {
                depthSumInverseHelper(res, depth + 1, nes);
            }
        }
    }
};