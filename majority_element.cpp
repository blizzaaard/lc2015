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
             while (num[++i] < v) if (i == end) break;
             while (v < num[--j]) if (j == start) break;
             if (i >= j) break;
             swap(num[i], num[j]);
         }
         swap(num[start], num[j]);
         return j;
    }

    int nth_element(vector<int>& num, int start, int end, int n)
    {
        if (start == end) {
            return num[start];
        }
        int pivot = partition(num, start, end);
        std::cout << start << "," << end << ":" << pivot << "|" << n << std::endl;
        print(num, start, end, pivot);
        int numLeft = pivot - start;
        if (n == numLeft) return num[pivot];
        else if (n < numLeft) return nth_element(num, start, pivot - 1, n);
        else return nth_element(num, pivot + 1, end, n - numLeft - 1);
    }

  public:
    int majorityElement(vector<int> &num) {
        int mid = num.size() / 2;
        return nth_element(num, 0, num.size() - 1, mid);
    }
};

int main()
{
    vector<int> num;

    num.push_back(2147483647);

//    num.push_back(2);
//    num.push_back(2);

//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(58);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(50);
//    num.push_back(77);
//    num.push_back(77);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(51);
//    num.push_back(32);
//    num.push_back(61);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(88);
//    num.push_back(44);
//    num.push_back(32);
//    num.push_back(7);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(92);
//    num.push_back(28);
//    num.push_back(1);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(44);
//    num.push_back(97);
//    num.push_back(99);
//    num.push_back(32);
//    num.push_back(1);
//    num.push_back(40);
//    num.push_back(32);
//    num.push_back(20);
//    num.push_back(32);
//    num.push_back(68);
//    num.push_back(85);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(98);
//    num.push_back(13);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(7);
//    num.push_back(74);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(52);
//    num.push_back(32);
//    num.push_back(86);
//    num.push_back(28);
//    num.push_back(45);
//    num.push_back(73);
//    num.push_back(19);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(27);
//    num.push_back(32);
//    num.push_back(83);
//    num.push_back(32);
//    num.push_back(68);
//    num.push_back(94);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(27);
//    num.push_back(24);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(96);
//    num.push_back(32);
//    num.push_back(99);
//    num.push_back(60);
//    num.push_back(46);
//    num.push_back(32);
//    num.push_back(22);
//    num.push_back(71);
//    num.push_back(25);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(53);
//    num.push_back(54);
//    num.push_back(26);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(32);
//    num.push_back(13);
//    num.push_back(32);
//    num.push_back(23);
//    num.push_back(6);

    Solution s;
    std::cout << s.majorityElement(num) << std::endl;
    return 0;
}
