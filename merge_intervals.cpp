// #56 Merge Intervals
//
// Given a collection of intervals, merge all overlapping intervals.
//
// For example,
//
// Given [1,3],[2,6],[8,10],[15,18],
//
// return [1,6],[8,10],[15,18].


#include <iostream>
#include <vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

void print(const std::vector<Interval>& intervals)
{
    for (int i = 0; i < intervals.size(); ++i) {
        std::cout << "("  << intervals[i].start
                  << ", " << intervals[i].end
                  << ") ";
    }
    std::cout << std::endl;
}

struct Comp {
    bool operator()(const Interval& lhs, const Interval& rhs) const
    {
        return (lhs.start < rhs.start) ? true : false;
    }
};

class Solution {

  public:
    std::vector<Interval> merge(std::vector<Interval>& intervals)
    {
        std::vector<Interval> result;

        if (intervals.empty()) {
            return result;
        }

        // Sort the intervals by their starting point.

        std::sort(intervals.begin(), intervals.end(), Comp());

        int start = intervals[0].start;
        int end   = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start > end) {
                result.push_back(Interval(start, end));
                start = intervals[i].start;
                end   = intervals[i].end;
            } else {
                end = std::max(end, intervals[i].end);
            }
        }
        result.push_back(Interval(start, end));

        return result;
    }
};

int main()
{
    std::vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(2, 6));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));

    Solution s;
    print(s.merge(intervals));

    return 0;
}
