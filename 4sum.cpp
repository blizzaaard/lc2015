#include <vector>
#include <iostream>

class Solution {
  public:
    std::vector<std::vector<int> > fourSum(std::vector<int> &num, int target) {
        std::vector<std::vector<int> > results;
        if (4 > num.size()) {
            return results;
        }
        std::sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 3; ++i) {
            if (i != 0 && num[i] == num[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < num.size() - 2; ++j) {
                if (j != i + 1 && num[j] == num[j - 1]) {
                    continue;
                }
                int left = j + 1, right = num.size() - 1;
                while (left < right) {
                    int sum = num[i] + num[j] + num[left] + num[right];
                    if (target == sum) {
                        if (results.empty() || (results.back()[0] != num[i]
                                             || results.back()[1] != num[j]
                                             || results.back()[2] != num[left]
                                             || results.back()[3] != num[right]))
                        {
                            std::vector<int> result;
                            result.push_back(num[i]);
                            result.push_back(num[j]);
                            result.push_back(num[left]);
                            result.push_back(num[right]);
                            results.push_back(result);
                        }
                        ++left;
                        --right;
                    } else if (target < sum) {
                        --right;
                    } else {
                        ++left;
                    }
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
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); ++i) {
            if (i != 0 && num[i] == num[i - 1]) continue;
            for (int j = i + 1; j < num.size(); ++j) {
                if (j != i + 1 && num[j] == num[j - 1]) continue;
                int start = j + 1, end = num.size() - 1;
                while (start < end) {
                    if (start != j + 1 && num[start] == num[start - 1]) {
                        ++start;
                        continue;
                    }
                    int sum = num[i] + num[j] + num[start] + num[end];
                    if (sum - target == 0) {
                        result.resize(result.size() + 1);
                        result.back().push_back(num[i]);
                        result.back().push_back(num[j]);
                        result.back().push_back(num[start]);
                        result.back().push_back(num[end]);
                        ++start;
                        --end;
                    } else if (sum - target > 0) --end;
                    else ++start;
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
        num.push_back(1);
        num.push_back(0);
        num.push_back(-1);
        num.push_back(0);
        num.push_back(-2);
        num.push_back(2);

        print(s.fourSum(num, 0));
    }
    {
        std::vector<int> num;
        num.push_back(-1);
        num.push_back(0);
        num.push_back(1);
        num.push_back(2);
        num.push_back(-1);
        num.push_back(-4);
        print(s.fourSum(num, -1));
    }
    {
        std::vector<int> num;
        print(s.fourSum(num, 0));
    }
    {
        std::vector<int> num;
        num.push_back(-3);
        print(s.fourSum(num, 0));
    }
    {
        std::vector<int> num;
        num.push_back(-3);
        num.push_back(-3);
        print(s.fourSum(num, 0));
    }
    {
        std::vector<int> num;
        num.push_back(-3);
        num.push_back(-3);
        num.push_back(-3);
        print(s.fourSum(num, 0));
    }

    return 0;
}
