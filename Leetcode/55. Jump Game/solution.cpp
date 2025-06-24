class Solution {
public:
    bool canJump(vector<int>& nums) {

        int fuel = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (fuel < 0) {
                return false;
            }
            else if (nums[i] > fuel) {
                fuel = nums[i];
            }
            fuel--;
        }
        return true;
    }
};