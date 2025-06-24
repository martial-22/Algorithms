class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;

        for (int i = 0; i < nums.size() - 1;) {
            int next = i + 1;

            for (int j = i + 1; j <= i + nums[i]; ++j) {
                if (j >= nums.size() - 1) {
                    next = nums.size() - 1;
                    break;
                }
                if (nums[j] + j >= nums[next] + next) {
                    next = j;
                }
            }
            ++count;
            i = next;
        }
        return count;
    }
};