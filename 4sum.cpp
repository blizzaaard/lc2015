// #18 4Sum
//
// Given an array S of n integers, are there elements a, b, c, and d in S such
// that a + b + c + d = target? Find all unique quadruplets in the array which
// gives the sum of target.
//
// Note:
//
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤
// b ≤ c ≤ d)
//
// The solution set must not contain duplicate quadruplets.
//
//     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
//
//     A solution set is:
//     (-1,  0, 0, 1)
//     (-2, -1, 1, 2)
//     (-2,  0, 0, 2)


#include <list>
#include <vector>
#include <iostream>
#include <unordered_map>

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

void print(const vector<int>& nums, const vector<pair<int, int> >& pairs)
{
    for (int i = 0; i < pairs.size(); ++i) {
        cout << nums[pairs[i].first] << ", " << nums[pairs[i].second] << endl;
    }
}

void print(const vector<int>& nums,
           const unordered_map<int, vector<pair<int, int> > >& pairs)
{
    for (unordered_map<int, vector<pair<int, int> > >::const_iterator
            it = pairs.begin(); it != pairs.end(); ++it)
    {
        cout << it->first << endl;

        for (int i = 0; i < it->second.size(); ++i) {
            cout << '\t'
                 << nums[it->second[i].first] << '('
                 << it->second[i].first
                 << "), "
                 << nums[it->second[i].second] << '('
                 << it->second[i].second
                 << ')'
                 << endl;
        }
    }
}

class Solution_O2 {

  public:
    vector<vector<int> > fourSum(vector<int> &nums, int target)
    {
        vector<vector<int> > result;

        sort(nums.begin(), nums.end());

        typedef unordered_map<int, list<pair<int, int> > > Pairs;
        Pairs pairs(nums.size() * nums.size());

        for (int i = 0; i < nums.size(); ++i){
            for (int j = i + 1; j < nums.size(); ++j) {
                int sum = nums[i] + nums[j];
                pair<Pairs::iterator, bool> ret =
                    pairs.insert(make_pair(sum, list<pair<int, int> >()));
                ret.first->second.push_back(make_pair(i, j));
            }
        }

//        print(nums, pairs);

//        typedef unordered_map<int, Pairs::const_iterator> Dict;
//        Dict dict;
//        for (Pairs::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
//        {
//            Dict::iterator jt = dict.find(it->first);
//            if (dict.end() == jt) {
//                dict.insert(make_pair(target - it->first, it));
//            } else {
//                list<pair<int, int> > p1 = it->second;
//                list<pair<int, int> > p2 = jt->second->second;
//                for (list<pair<int, int> >::const_iterator
//                        mt = p1.begin(); mt != p1.end(); ++mt)
//                {
//                    for (list<pair<int, int> >::const_iterator
//                            nt = p2.begin(); nt != p2.end(); ++nt)
//                    {
//                        if (mt->second < nt->first
//                        ||  nt->second < mt->first)
//                        {
//                            //cout << nums[p1[i].first]  << ", "
//                            //     << nums[p1[i].second] << ", "
//                            //     << nums[p2[j].first]  << ", "
//                            //     << nums[p2[j].second]
//                            //     << endl;
//                            result.resize(result.size() + 1);
//                            result.back().push_back(nums[mt->first]);
//                            result.back().push_back(nums[mt->second]);
//                            result.back().push_back(nums[nt->first]);
//                            result.back().push_back(nums[nt->second]);
//                        }
//                    }
//                }
//                //print(nums, jt->second->second);
//                //print(nums, it->second);
//            }
//        }
        return result;
    }
};

int main()
{
//    Solution_O2 s;
    Solution s;
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

    {
        std::vector<int> num;
        num.push_back(91277418);
        num.push_back(66271374);
        num.push_back(38763793);
        num.push_back(4092006);
        num.push_back(11415077);
        num.push_back(60468277);
        num.push_back(1122637);
        num.push_back(72398035);
        num.push_back(-62267800);
        num.push_back(22082642);
        num.push_back(60359529);
        num.push_back(-16540633);
        num.push_back(92671879);
        num.push_back(-64462734);
        num.push_back(-55855043);
        num.push_back(-40899846);
        num.push_back(88007957);
        num.push_back(-57387813);
        num.push_back(-49552230);
        num.push_back(-96789394);
        num.push_back(18318594);
        num.push_back(-3246760);
        num.push_back(-44346548);
        num.push_back(-21370279);
        num.push_back(42493875);
        num.push_back(25185969);
        num.push_back(83216261);
        num.push_back(-70078020);
        num.push_back(-53687927);
        num.push_back(-76072023);
        num.push_back(-65863359);
        num.push_back(-61708176);
        num.push_back(-29175835);
        num.push_back(85675811);
        num.push_back(-80575807);
        num.push_back(-92211746);
        num.push_back(44755622);
        num.push_back(-23368379);
        num.push_back(23619674);
        num.push_back(-749263);
        num.push_back(-40707953);
        num.push_back(-68966953);
        num.push_back(72694581);
        num.push_back(-52328726);
        num.push_back(-78618474);
        num.push_back(40958224);
        num.push_back(-2921736);
        num.push_back(-55902268);
        num.push_back(-74278762);
        num.push_back(63342010);
        num.push_back(29076029);
        num.push_back(58781716);
        num.push_back(56045007);
        num.push_back(-67966567);
        num.push_back(-79405127);
        num.push_back(-45778231);
        num.push_back(-47167435);
        num.push_back(1586413);
        num.push_back(-58822903);
        num.push_back(-51277270);
        num.push_back(87348634);
        num.push_back(-86955956);
        num.push_back(-47418266);
        num.push_back(74884315);
        num.push_back(-36952674);
        num.push_back(-29067969);
        num.push_back(-98812826);
        num.push_back(-44893101);
        num.push_back(-22516153);
        num.push_back(-34522513);
        num.push_back(34091871);
        num.push_back(-79583480);
        num.push_back(47562301);
        num.push_back(6154068);
        num.push_back(87601405);
        num.push_back(-48859327);
        num.push_back(-2183204);
        num.push_back(17736781);
        num.push_back(31189878);
        num.push_back(-23814871);
        num.push_back(-35880166);
        num.push_back(39204002);
        num.push_back(93248899);
        num.push_back(-42067196);
        num.push_back(-49473145);
        num.push_back(-75235452);
        num.push_back(-61923200);
        num.push_back(64824322);
        num.push_back(-88505198);
        num.push_back(20903451);
        num.push_back(-80926102);
        num.push_back(56089387);
        num.push_back(-58094433);
        num.push_back(37743524);
        num.push_back(-71480010);
        num.push_back(-14975982);
        num.push_back(19473982);
        num.push_back(47085913);
        num.push_back(-90793462);
        num.push_back(-33520678);
        num.push_back(70775566);
        num.push_back(-76347995);
        num.push_back(-16091435);
        num.push_back(94700640);
        num.push_back(17183454);
        num.push_back(85735982);
        num.push_back(90399615);
        num.push_back(-86251609);
        num.push_back(-68167910);
        num.push_back(-95327478);
        num.push_back(90586275);
        num.push_back(-99524469);
        num.push_back(16999817);
        num.push_back(27815883);
        num.push_back(-88279865);
        num.push_back(53092631);
        num.push_back(75125438);
        num.push_back(44270568);
        num.push_back(-23129316);
        num.push_back(-846252);
        num.push_back(-59608044);
        num.push_back(90938699);
        num.push_back(80923976);
        num.push_back(3534451);
        num.push_back(6218186);
        num.push_back(41256179);
        num.push_back(-9165388);
        num.push_back(-11897463);
        num.push_back(92423776);
        num.push_back(-38991231);
        num.push_back(-6082654);
        num.push_back(92275443);
        num.push_back(74040861);
        num.push_back(77457712);
        num.push_back(-80549965);
        num.push_back(-42515693);
        num.push_back(69918944);
        num.push_back(-95198414);
        num.push_back(15677446);
        num.push_back(-52451179);
        num.push_back(-50111167);
        num.push_back(-23732840);
        num.push_back(39520751);
        num.push_back(-90474508);
        num.push_back(-27860023);
        num.push_back(65164540);
        num.push_back(26582346);
        num.push_back(-20183515);
        num.push_back(99018741);
        num.push_back(-2826130);
        num.push_back(-28461563);
        num.push_back(-24759460);
        num.push_back(-83828963);
        num.push_back(-1739800);
        num.push_back(71207113);
        num.push_back(26434787);
        num.push_back(52931083);
        num.push_back(-33111208);
        num.push_back(38314304);
        num.push_back(-29429107);
        num.push_back(-5567826);
        num.push_back(-5149750);
        num.push_back(9582750);
        num.push_back(85289753);
        num.push_back(75490866);
        num.push_back(-93202942);
        num.push_back(-85974081);
        num.push_back(7365682);
        num.push_back(-42953023);
        num.push_back(21825824);
        num.push_back(68329208);
        num.push_back(-87994788);
        num.push_back(3460985);
        num.push_back(18744871);
        num.push_back(-49724457);
        num.push_back(-12982362);
        num.push_back(-47800372);
        num.push_back(39958829);
        num.push_back(-95981751);
        num.push_back(-71017359);
        num.push_back(-18397211);
        num.push_back(27941418);
        num.push_back(-34699076);
        num.push_back(74174334);
        num.push_back(96928957);
        num.push_back(44328607);
        num.push_back(49293516);
        num.push_back(-39034828);
        num.push_back(5945763);
        num.push_back(-47046163);
        num.push_back(10986423);
        num.push_back(63478877);
        num.push_back(30677010);
        num.push_back(-21202664);
        num.push_back(-86235407);
        num.push_back(3164123);
        num.push_back(8956697);
        num.push_back(-9003909);
        num.push_back(-18929014);
        num.push_back(-73824245);

        for (int i = 0; i < 1000; ++i) {
            size_t old_count = num.size();
            num.resize(2 * old_count);
            std::copy_n(num.begin(), old_count, num.begin() + old_count);
        }

        s.fourSum(num, -236727523);
    }

    return 0;
}
