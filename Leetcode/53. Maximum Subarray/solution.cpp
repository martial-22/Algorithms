class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int minSum = 0;
        int diff = std::numeric_limits<int>::min();

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            diff = std::max(sum, std::max(sum - minSum, diff));

            minSum = std::min(sum, minSum);
        }
        return diff;
    }
};