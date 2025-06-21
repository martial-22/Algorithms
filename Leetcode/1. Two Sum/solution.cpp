class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> valueToIndex;
        valueToIndex.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            int value = target - nums[i];

            auto iter = valueToIndex.find(value);
            if (iter != valueToIndex.end()) {
                return { iter->second, i  };
            }
            valueToIndex[nums[i]] = i;
        }
        return {};
    }
};
