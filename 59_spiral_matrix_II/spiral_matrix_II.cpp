#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        if(n == 0) { return res; }

        int beginX = 0, endX = n - 1;
        int beginY = 0, endY = n - 1;
        int count = 1;

        while(true) {
            for(int i = beginX; i <= endX; i++) {
                res[beginY][i] = count;
                count++;
            }

            if(++beginY > endY) { break; }

            for(int i = beginY; i <= endY; i++) {
                res[i][endX] = count;
                count++;
            }

            if(--endX < beginX) { break; }

            for(int i = endX; i >= beginX; i--) {
                res[endY][i] = count;
                count++;
            }

            if(--endY < beginY) { break; }

            for(int i = endY; i >= beginY; i--) {
                res[i][beginX] = count;
                count++;
            }

            if(++beginX > endX) { break; }
        }

        return res;
    }
};

int main()
{
	int  n = 3;
	Solution sol;
	vector<vector<int> > result;
	result = sol.generateMatrix(n);

	for(vector<vector<int> >::iterator it = result.begin();
		it != result.end();
		it++)
	{
		for(vector<int>::iterator itt = (*it).begin();
			itt != (*it).end();
			itt++)
		{
			cout << *(itt) << " ";
		}
		cout << endl;
	}

}