// #135 Candy
//
// There are N children standing in a line. Each child is assigned a rating
// value.
//
// You are giving candies to these children subjected to the following
// requirements:
//
// Each child must have at least one candy.
//
// Children with a higher rating get more candies than their neighbors.
//
// What is the minimum candies you must give?


class Solution {

  public:
    int candy(const std::vector<int>& ratings)
    {
        // Every one has at least one candy.

        std::vector<int> counts(ratings.size(), 1);

        // Iterate from left to right and make sure the one has higher rating
        // gets more candy.

        for (int i = 1; i < ratings.size(); ++i) {
            if ((ratings[i] > ratings[i - 1]) && (counts[i] <= counts[i - 1])) {
                counts[i] = counts[i - 1] + 1;
            }
        }

        // Iterate from right to left and make sure the one has higher rating
        // gets more candy.

        for (int i = ratings.size() - 2; i >= 0; --i) {
            if ((ratings[i] > ratings[i + 1]) && (counts[i] <= counts[i + 1])) {
                counts[i] = counts[i + 1] + 1;
            }
        }

        // Calculate the total number of candies.

        int sum = 0;
        for (int i = 0; i < counts.size(); ++i) {
            sum += counts[i];
        }
        return sum;
    }
};
