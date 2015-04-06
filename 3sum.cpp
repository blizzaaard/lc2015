#include <vector>
#include <iostream>

class Solution {
  public:
    std::vector<std::vector<int> > threeSum_A(std::vector<int> &num) {
        std::vector<std::vector<int> > results;
        if (3 > num.size()) {
            return results;
        }
        std::sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 2; ++i) {
            if (i != 0 && num[i] == num[i - 1]) {
                continue;
            }
            int left = i + 1, right = num.size() - 1;
            while (left < right) {
                if (0 == num[i] + num[left] + num[right]) {
                    std::vector<int> result;
                    result.push_back(num[i]);
                    result.push_back(num[left]);
                    result.push_back(num[right]);

                    if (results.empty()
                    ||  (results.back()[0] != num[i]
                      || results.back()[1] != num[left]
                      || results.back()[2] != num[right]))
                    {
                        results.push_back(result);
                    }

                    do {
                        ++left;
                        --right;
                    } while (left < right && num[right] == num[right + 1]
                                          && num[left]  == num[left - 1]);
                } else if (0 < num[i] + num[left] + num[right]) {
                    do {
                        --right;
                    } while (left < right && num[right] == num[right + 1]);
                } else {
                    do {
                        ++left;
                    } while (left < right && num[left] == num[left - 1]);
                }
            }
        }
        return results;
    }

    std::vector<std::vector<int> > threeSum(std::vector<int> &num) {
        std::vector<std::vector<int> > results;
        if (3 > num.size()) {
            return results;
        }
        std::sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 2; ++i) {
            if (i != 0 && num[i] == num[i - 1]) {
                continue;
            }
            int left = i + 1, right = num.size() - 1;
            while (left < right) {
                if (0 == num[i] + num[left] + num[right]) {
                    if (results.empty()
                    ||  (results.back()[0] != num[i]
                      || results.back()[1] != num[left]
                      || results.back()[2] != num[right]))
                    {
                        std::vector<int> result;
                        result.push_back(num[i]);
                        result.push_back(num[left]);
                        result.push_back(num[right]);
                        results.push_back(result);
                    }

                    ++left;
                    --right;
                } else if (0 < num[i] + num[left] + num[right]) {
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return results;
    }
};

void print(const std::vector<std::vector<int> >& results)
{
    std::cout << "RESULT = " << std::endl;
    for (int i = 0; i < results.size(); ++i) {
        for (int j = 0; j < results[i].size(); ++j) {
            std::cout << results[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

using namespace std;

class Solution1 {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); ++i) {
            if (0 != i && num[i - 1] == num[i]) continue;
            int start = i + 1, end = num.size() - 1;
            while (start < end) {
                // No need to check if num[end] is duplicated or not
                // if (end != num.size() - 1 && num[end] == num[end + 1]) {
                //    --end;
                //    continue;
                // }
                if (start != i + 1 && num[start - 1] == num[start]) {
                    ++start;
                    continue;
                }
                if (num[start] + num[end] + num[i] == 0) {
                    int n = result.size();
                    result.resize(n + 1);
                    result[n].push_back(num[i]);
                    result[n].push_back(num[start]);
                    result[n].push_back(num[end]);
                    --end;
                    ++start;
                } else if (num[start] + num[end] + num[i] > 0) {
                    --end;
                } else {
                    ++start;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution1 s;
    {
        std::vector<int> num;
        num.push_back(0);
        num.push_back(-1);
        num.push_back(-1);
        num.push_back(0);
        num.push_back(1);
        num.push_back(1);
        print(s.threeSum(num));
    }
    /*
    {
        std::vector<int> num;
        num.push_back(-1);
        num.push_back(0);
        num.push_back(1);
        num.push_back(2);
        num.push_back(-1);
        num.push_back(-4);
        print(s.threeSum(num));
    }
    {
        std::vector<int> num;
        num.push_back(-1);
        num.push_back(0);
        num.push_back(1);
        num.push_back(2);
        num.push_back(-1);
        num.push_back(-4);
        print(s.threeSum(num));
    }
    {
        std::vector<int> num;
        num.push_back(-1);
        num.push_back(0);
        num.push_back(1);
        num.push_back(2);
        num.push_back(-1);
        num.push_back(-4);
        num.push_back(-1);
        print(s.threeSum(num));
    }
    {
        std::vector<int> num;
        num.push_back(-3);
        num.push_back(-3);
        num.push_back(-3);
        num.push_back(6);
        print(s.threeSum(num));
    }
    {
        std::vector<int> num;
        print(s.threeSum(num));
    }
    {
        std::vector<int> num;
        num.push_back(-3);
        print(s.threeSum(num));
    }
    {
        std::vector<int> num;
        num.push_back(-3);
        num.push_back(-3);
        print(s.threeSum(num));
    }
    */

    return 0;
}
