#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

// On the same line: either with the same x-value or the same y-value
// horizontal, vertical, lint
struct Point
{
	int x;
	int y;
	Point(): x(0), y(0) {}
	Point(int a, int b): x(a), y(b) {}
};


class Solution
{
public:
	int maxPoints(vector<Point>& points)
	{
		int result = 0;
		map<pair<int, int>, int> count;
		map<int, int> x_axis;
		map<int, int> y_axis;
		map<pair<double, double>, vector<pair<int, int> > > tilt;
		// m, b
		// construct two hash table

		for(int i = 0; i < points.size(); ++i)
		{
			count[pair<int, int>(points[i].x, points[i].y)]++;
		}
		
		// x_axis -- vertical
		for(int i = 0; i < points.size(); ++i)
		{
			x_axis[points[i].x]++;
		}
		// y_axis -- horizontal
		for(int i = 0; i < points.size(); ++i)
		{
			y_axis[points[i].y]++;
		}

		// tilt -- class by tilt ratio
		for(int i = 0; i < points.size(); ++i)
		{
			for(int j = i + 1; j < points.size(); ++j)
			{
				if(points[j].x - points[i].x == 0 || points[j].y - points[i].y == 0) continue;


				// m and b may be floating number
				double tilt_ratio = double((points[j].y - points[i].y)) / double((points[j].x - points[i].x));
				double b = double((points[j].x * points[i].y - points[i].x * points[j].y)) / double((points[j].x - points[i].x));
				pair<double, double> line(tilt_ratio, b);

				if(find(tilt[line].begin(), tilt[line].end(), pair<int, int>(points[j].x, points[j].y)) == tilt[line].end())
				{

					//cout << count[pair<int, int>(points[j].x, points[j].y)] << endl;
					for(int k = 0; k < count[pair<int, int>(points[j].x, points[j].y)]; ++k)
						tilt[line].push_back(pair<int, int>(points[j].x, points[j].y));
				}

				if(find(tilt[line].begin(), tilt[line].end(), pair<int, int>(points[i].x, points[i].y)) == tilt[line].end())
				{

					//cout << count[pair<int, int>(points[i].x, points[i].y)] << endl;
					for(int k = 0; k < count[pair<int, int>(points[i].x, points[i].y)]; ++k)
				    	tilt[line].push_back(pair<int, int>(points[i].x, points[i].y));
				}
			}
		}

		
		for(map<int, int>::iterator it = x_axis.begin();
			it != x_axis.end();
			++it)
		{
			if(it -> second > result)
				result = it -> second;
		}

		for(map<int, int>::iterator it = y_axis.begin();
			it != y_axis.end();
			++it)
		{
			if(it -> second > result)
				result = it -> second;
		}
		

		for(map<pair<double, double>, vector<pair<int, int> > >::iterator it = tilt.begin();
			it != tilt.end();
			++it)
		{
			if((it -> second).size() > result)
				result = (it -> second).size();
		}

		return result;
	}
};

int main()
{
	//map<int, int> mapping;
	//mapping[0]++;
	//cout << mapping[0] << endl;
	double a = double(23) / double(70);
	cout << a << endl;
	return 0;
}