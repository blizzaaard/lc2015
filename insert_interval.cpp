// #57 Insert Intervals
//
// Given a set of non-overlapping intervals, insert a new interval into the
// intervals (merge if necessary).
//
// You may assume that the intervals were initially sorted according to their
// start times.
//
// Example 1:
//
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//
// Example 2:
//
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
// [1,2],[3,10],[12,16].
//
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].


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

class Solution {

  public:
    std::vector<Interval> insert(const std::vector<Interval>& intervals,
                                 const Interval&              newInterval)
    {
        std::vector<Interval> result;

        Interval tempInterval(newInterval);

        for (std::vector<Interval>::const_iterator
                it  = intervals.begin();
                it != intervals.end();
              ++it)
        {
            if (tempInterval.end < it->start) {
                //         it
                //       +----+
                // +---+
                //  new
                result.push_back(tempInterval);
                result.insert(result.end(), it, intervals.end());
                return result;
            } else if (tempInterval.start > it->end) {
                //   it
                // +----+
                //        +---+
                //         new
                result.push_back(*it);
            } else {
                //   it              it
                // +----+    OR    +----+
                //    +---+      +---+
                //     new        new
                tempInterval.start = std::min(tempInterval.start, it->start);
                tempInterval.end   = std::max(tempInterval.end,   it->end);
            }
        }
        result.push_back(tempInterval);

        return result;
    }
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        Interval tmp = newInterval;
        for (vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); ) {
            if (tmp.end < it->start) {
                intervals.insert(it, tmp);
                return intervals;
            } else if (tmp.start > it->end) {
                ++it;
            } else {
                tmp.start = min(tmp.start, it->start);
                tmp.end = max(tmp.end, it->end);
                intervals.erase(it);
            }
        }
        intervals.push_back(tmp);
        return intervals;
    }
};

int main()
{
    Solution s;
    {
        std::vector<Interval> intervals;
        intervals.push_back(Interval(1, 3));
        intervals.push_back(Interval(6, 9));

        print(s.insert(intervals, Interval(2, 5)));
    }
    {
        std::vector<Interval> intervals;
        intervals.push_back(Interval(1, 2));
        intervals.push_back(Interval(3, 5));
        intervals.push_back(Interval(6, 7));
        intervals.push_back(Interval(8, 10));
        intervals.push_back(Interval(12, 16));

        print(s.insert(intervals, Interval(4, 9)));
    }

    return 0;
}
