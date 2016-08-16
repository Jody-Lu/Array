#include <vector>
#include <unordered_map>

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
	public:
    	int maxPoints(vector<Point>& points) {
            if(points.size() == 1) return 1; // the case when there is only one point.
            int result = 0;
            for(int i = 0; i < points.size(); i++) {
                int samePoint = 1;
                unordered_map<double, int> map;
                for(int j = i + 1; j < points.size(); j++) {
                    if(points[i].x == points[j].x && points[i].y == points[j].y) {
                        samePoint++;
                    }
                    else if(points[i].x == points[j].x) {
                        map[INT_MAX]++;
                    }
                    else {
                        double slope = double(positions[i].y - positions[j].y) / double(positions[i].x - positions[j].x);
                        map[slope]++;
                    }
                    int localMax = 0;
                    for(auto it = map.begin(); it != map.end(); it++) {
                        localMax = max(localMax, it->second);
                    }
                    localMax += samePoint;
                    result = max(result, localMax);
                }
            }
            return result;
    	}
};
