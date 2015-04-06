#include <iostream>
#include <vector>
#include <unordered_map>

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
 	Point(int a, int b) : x(a), y(b) {}
 };
 
class Solution {
  public:
    int maxPoints(std::vector<Point> &points) {
    	if (3 > points.size()) {
    		return points.size();
    	}
        int maximum = 0;
        for (int i = 0; i < points.size(); ++i) {
            int localMax = 0;
            typedef std::unordered_map<double, int> Hash;
            Hash hash;
            int yAxisCount  = 0;
            int samePtCount = 0;
            for (int j = i + 1; j < points.size(); ++j) {
                double deltaX = points[i].x - points[j].x;
                double deltaY = points[i].y - points[j].y;
                if (0 == deltaX && 0 == deltaY) {
                	++samePtCount;
                } else if (0 == deltaX) {
                	++yAxisCount;
                } else {
                	double k = deltaY / deltaX;
                	std::pair<Hash::iterator, bool> ret =
                				 hash.insert(std::make_pair(k, 0));
                	++ret.first->second;
                	std::cout << "(" << points[i].x << "," << points[i].y
                			  << ") - (" << points[j].x << "," << points[j].y
                			  << "): " << k
                			  << std::endl;
                }
            }
            for (Hash::const_iterator it  = hash.begin();
            						  it != hash.end();
            						++it)
            {
            	localMax = std::max(localMax, it->second);
            }
            localMax = std::max(localMax, yAxisCount);
            localMax += (samePtCount + 1); // self
            maximum = std::max(maximum, localMax);
        }
        return maximum;
    }
};

int main()
{
	/*
	{
		std::vector<Point> points;
		points.push_back(Point(1, 1));
		points.push_back(Point(2, 2));
		points.push_back(Point(2, 2));
		points.push_back(Point(0, 0));
		points.push_back(Point(1, 3));

		Solution s;
		std::cout << s.maxPoints(points) << std::endl;
	}

	{
		std::vector<Point> points;
		points.push_back(Point(2, 3));
		points.push_back(Point(3, 3));
		points.push_back(Point(-5, 3));

		Solution s;
		std::cout << s.maxPoints(points) << std::endl;
	}
	*/

	{
		std::vector<Point> points;
		points.push_back(Point(84, 250));
		points.push_back(Point(0, 0));
		points.push_back(Point(1, 0));

		points.push_back(Point(0, -70));
		points.push_back(Point(0, -70));
		points.push_back(Point(1, -1));

		points.push_back(Point(21, 10));
		points.push_back(Point(42, 90));
		points.push_back(Point(-42, -230));

		Solution s;
		std::cout << s.maxPoints(points) << std::endl;
	}

	return 0;
}