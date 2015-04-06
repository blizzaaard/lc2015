// #34 Search for a Range
//
// Given a sorted array of integers, find the starting and ending position of a
// given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].


#include <vector>
#include <iostream>

void print(const std::vector<int>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

class Solution {

  public:
    std::vector<int> searchRange(int A[], int n, int target)
    {
        std::vector<int> result;
        int left  = -1;
        int right = -1;

        // Find the left bound.

        int start = 0;
        int end   = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                if (0 == mid || A[mid - 1] != A[mid]) {
                    left = mid;
                    break;
                } else {
                    end = mid - 1;
                }
            } else if (A[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // Find the right bound.

        start = 0;
        end   = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                if (n - 1 == mid || A[mid] != A[mid + 1]) {
                    right = mid;
                    break;
                } else {
                    start = mid + 1;
                }
            } else if (A[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        result.push_back(left);
        result.push_back(right);

        return result;
    }
};

using namespace std;

class Solution1 {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int left = -1, right = -1;
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == A[mid]) {
                if (0 == mid || A[mid - 1] != A[mid]) {
                    left = mid;
                    break;
                } else end = mid - 1;
            } else if (target < A[mid]) end = mid - 1;
            else start = mid + 1;
        }
        start = 0;
        end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == A[mid]) {
                if (n - 1 == mid || A[mid] != A[mid + 1]) {
                    right = mid;
                    break;
                } else start = mid + 1;
            } else if (target < A[mid]) end = mid - 1;
            else start = mid + 1;
        }
        vector<int> result;
        result.push_back(left);
        result.push_back(right);
        return result;
    }
};

int main()
{
    Solution1 s;
    {
        int A[] = { 1 };
        print(s.searchRange(A, sizeof A / sizeof *A, 0));
    }
    {
        int A[] = { 5, 7, 7, 8, 8, 10 };
        print(s.searchRange(A, sizeof A / sizeof *A, 8));
    }
    return 0;
}
