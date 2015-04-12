#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& num, int start, int end, int pivot)
{
    for (int i = start; i < end + 1; ++i) {
        std::cout << num[i];
        if (i == pivot) {
            std::cout << "*";
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

class Solution {

    int partition(vector<int>& num, int start, int end)
    {
         int i = start, j = end + 1;
         int v = num[i];
         while (1) {
             while (num[++i] < v) if (i == end)   break;
             while (v < num[--j]) if (j == start) break;
             if (i >= j) break;
             swap(num[i], num[j]);
         }
         swap(num[start], num[j]);
         return j;
    }

    void nth_element(vector<int>& num, int start, int end, int n)
    {
        if (start == end) return;
        int pivot = partition(num, start, end);
        if (n == pivot)     return;
        else if (n < pivot) nth_element(num, start, pivot - 1, n);
        else                nth_element(num, pivot + 1, end, n);
    }

  public:
    int majorityElement(vector<int> &num)
    {
        int n = num.size();
        int mid = n / 2;
        nth_element(num, 0, n - 1, mid);
        return num[mid];
    }
};

class Solution1 {
    // This one uses a different partition function which doesn't do well with
    // array containing all same elements because unlike the previous partition
    // function, this one always return the last element as the pivot for an
    // array containing all same elements.

    int partition(vector<int>& num, int start, int end)
    {
        int x = num[end];
        int i = start - 1;
        for (int j = start; j < end; ++j) {
            if (num[j] <= x) {
                ++i;
                swap(num[i], num[j]);
            }
        }
        swap(num[i + 1], num[end]);
        return i + 1;
    }

    void nth_element(vector<int>& num, int start, int end, int n)
    {
        if (start == end) return;
        int pivot = partition(num, start, end);
        if (n == pivot)     return;
        else if (n < pivot) nth_element(num, start, pivot - 1, n);
        else                nth_element(num, pivot + 1, end, n);
    }

  public:
    int majorityElement(vector<int> &num)
    {
        int n = num.size();
        int mid = n / 2;
        nth_element(num, 0, n - 1, mid);
        return num[mid];
    }
};

int main()
{
    Solution1 s;
    {
        vector<int> num;
        num.push_back(-1);
        num.push_back(100);
        num.push_back(2);
        num.push_back(100);
        num.push_back(100);
        num.push_back(4);
        num.push_back(100);
        std::cout << s.majorityElement(num) << std::endl;
    }
    {
        vector<int> num;
        for (int i = 0; i < 100000; ++i) {
            num.push_back(1);
        }
        std::cout << s.majorityElement(num) << std::endl;
    }
    {
        vector<int> num;
        num.push_back(2147483647);

        num.push_back(2);
        num.push_back(2);

        num.push_back(32);
        num.push_back(32);
        num.push_back(58);
        num.push_back(32);
        num.push_back(32);
        num.push_back(32);
        num.push_back(32);
        num.push_back(32);
        num.push_back(50);
        num.push_back(77);
        num.push_back(77);
        num.push_back(32);
        num.push_back(32);
        num.push_back(32);
        num.push_back(51);
        num.push_back(32);
        num.push_back(61);
        num.push_back(32);
        num.push_back(32);
        num.push_back(88);
        num.push_back(44);
        num.push_back(32);
        num.push_back(7);
        num.push_back(32);
        num.push_back(32);
        num.push_back(92);
        num.push_back(28);
        num.push_back(1);
        num.push_back(32);
        num.push_back(32);
        num.push_back(44);
        num.push_back(97);
        num.push_back(99);
        num.push_back(32);
        num.push_back(1);
        num.push_back(40);
        num.push_back(32);
        num.push_back(20);
        num.push_back(32);
        num.push_back(68);
        num.push_back(85);
        num.push_back(32);
        num.push_back(32);
        num.push_back(32);
        num.push_back(32);
        num.push_back(98);
        num.push_back(13);
        num.push_back(32);
        num.push_back(32);
        num.push_back(7);
        num.push_back(74);
        num.push_back(32);
        num.push_back(32);
        num.push_back(52);
        num.push_back(32);
        num.push_back(86);
        num.push_back(28);
        num.push_back(45);
        num.push_back(73);
        num.push_back(19);
        num.push_back(32);
        num.push_back(32);
        num.push_back(27);
        num.push_back(32);
        num.push_back(83);
        num.push_back(32);
        num.push_back(68);
        num.push_back(94);
        num.push_back(32);
        num.push_back(32);
        num.push_back(32);
        num.push_back(32);
        num.push_back(27);
        num.push_back(24);
        num.push_back(32);
        num.push_back(32);
        num.push_back(96);
        num.push_back(32);
        num.push_back(99);
        num.push_back(60);
        num.push_back(46);
        num.push_back(32);
        num.push_back(22);
        num.push_back(71);
        num.push_back(25);
        num.push_back(32);
        num.push_back(32);
        num.push_back(32);
        num.push_back(32);
        num.push_back(53);
        num.push_back(54);
        num.push_back(26);
        num.push_back(32);
        num.push_back(32);
        num.push_back(32);
        num.push_back(32);
        num.push_back(13);
        num.push_back(32);
        num.push_back(23);
        num.push_back(6);
        std::cout << s.majorityElement(num) << std::endl;
    }
    return 0;
}
