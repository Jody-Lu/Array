#include <iostream>

using namespace std;

class Solution {
	public:
    	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
            int interA_x = E, interA_y = B; // bottom left
            int interB_x = C , interB_y = H; // top right
            int tersectArea = (interB_y - interA_y) * (interB_x - interA_x);
            int areaA = (D - B) * (C -A);
            int areaB = (H - F) * (G - E);
            return areaA + areaB - tersectArea;
    	}
};
