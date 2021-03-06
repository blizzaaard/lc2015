// #134 Gas Station
//
// There are N gas stations along a circular route, where the amount of gas at
// station i is gas[i].
//
// You have a car with an unlimited gas tank and it costs cost[i] of gas to
// travel from station i to its next station (i+1). You begin the journey with
// an empty tank at one of the gas stations.
//
// Return the starting gas station's index if you can travel around the circuit
// once, otherwise return -1.
//
// Note:
//
// The solution is guaranteed to be unique.


class Solution {

  public:
    int canCompleteCircuit(const std::vector<int>& gas,
                           const std::vector<int>& cost)
    {
        int start = 0;
        int left  = 0;
        int sum   = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum  += (gas[i] - cost[i]);
            left += (gas[i] - cost[i]);
            if (0 > sum) {
                start = i + 1;
                sum = 0;
            }
        }
        if (left < 0) {
            start = -1;
        }
        return start;
    }
};
