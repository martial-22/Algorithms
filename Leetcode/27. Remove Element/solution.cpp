class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = 0;
        for (int i = 0, j = nums.size() - 1; i <= j;) {
            if (nums[j] == val) {
                ++n;
                --j;
            }
            else  {
                if (nums[i] == val) {
                    std::swap(nums[i], nums[j]);
                }
                ++i;
            }
        }
        return nums.size() - n;
    }
};
