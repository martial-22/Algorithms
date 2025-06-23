class Solution {
public:
    int reverse(int x) {
        constexpr int maxInt = std::numeric_limits<int>::max();
        constexpr int minInt = std::numeric_limits<int>::min();

        constexpr int maxIntDividedBy10 = maxInt / 10;
        constexpr int minIntDividedBy10 = minInt / 10;

        int result = 0;
        std::uint8_t degree = 0;
        while (x != 0) {
            int digit = x % 10;

            if (degree >= 9) {
                if (result > maxIntDividedBy10 || result < minIntDividedBy10) {
                    return 0;
                }
                if (result == maxIntDividedBy10 && std::abs(maxInt - result) < digit) {
                    return 0;
                }
                if (result == minIntDividedBy10 && std::abs(minInt - result) < std::abs(digit)) {
                    return 0;
                }
            }
            
            result = result * 10 + digit;
            x = x / 10;

            ++degree;
        }
        return result;
    }
};