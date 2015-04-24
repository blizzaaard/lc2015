// #164 Maximum Gap
//
// Given an unsorted array, find the maximum difference between the successive
// elements in its sorted form.
//
// Try to solve it in linear time/space.
//
// Return 0 if the array contains less than 2 elements.
//
// You may assume all elements in the array are non-negative integers and fit
// in the 32-bit signed integer range.


#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Bucket {

    bool m_isEmpty;
    int  m_min;
    int  m_max;

    explicit Bucket()
    : m_isEmpty(true)
    {
    }
};

class Solution {

  public:
    int maximumGap(vector<int> &num)
    {
        if (2 > num.size()) return 0;

        // Get the maximum and minimum of the input array

        int maximum = num[0], minimum = num[0];
        for (int i = 1; i < num.size(); ++i) {
            maximum = max(maximum, num[i]);
            minimum = min(minimum, num[i]);
        }

        // Get the bucket length and count

        int bucketLen   = ceil((maximum - minimum)
                        / static_cast<double>(num.size() - 1));
        int bucketCount = (maximum - minimum) / bucketLen + 1;

        // Put each element into the bucket

        vector<Bucket> buckets(bucketCount);

        for (int i = 0; i < num.size(); ++i) {
            int bucketNum = (num[i] - minimum) / bucketLen;
            Bucket& bucket = buckets[bucketNum];
            if (bucket.m_isEmpty) {
                bucket.m_isEmpty = false;
                bucket.m_min     = num[i];
                bucket.m_max     = num[i];
            } else {
                bucket.m_min = min(bucket.m_min, num[i]);
                bucket.m_max = max(bucket.m_max, num[i]);
            }
        }

        // Calculate the maximum gap

        Bucket& prevBucket = buckets[0];
        int maxGap = 0;
        for (int i = 1; i < buckets.size(); ++i) {
            if (!buckets[i].m_isEmpty) {
                maxGap = max(maxGap, buckets[i].m_min - prevBucket.m_max);
                prevBucket = buckets[i];
            }
        }

        return maxGap;
    }
};

int main()
{
    Solution s;
    {
        vector<int> num;
        num.push_back(100);
        num.push_back(3);
        num.push_back(2);
        num.push_back(1);
        cout << s.maximumGap(num) << endl;
    }
    return 0;
}
