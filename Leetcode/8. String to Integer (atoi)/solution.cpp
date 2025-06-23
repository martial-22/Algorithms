class Solution {
public:
    int myAtoi(string s) {
        constexpr int undefined = -1;

        // Find begin and end of the number
        int first = undefined, last = undefined;

        // And define the sign of the number
        bool isNegative = false;
        {
            auto isDigit = [](char c) { return c >= '0' && c <= '9'; };

            bool numberBegins = false;
            
            for (int i = 0; i < s.size(); ++i) {
                char c = s[i];
                
                if (!numberBegins) {
                    // Ignore leading spaces
                    if (c == ' ') {
                        continue;
                    }

                    // Remember signs before numbers
                    if ((c == '-' || c == '+') && i + 1 < s.size() && isDigit(s[i + 1])) {
                        isNegative = c == '-';
                    }
                    else if (isDigit(c)) {
                        first = i;
                        numberBegins = true;
                    }
                    else {
                        return 0;
                    }
                }
                else {
                    if (!isDigit(c)) {
                        last = i - 1;
                        break;
                    }
                }
            }
        }

        // Process results after finding boarders of number
        if (last == undefined) {
            if (first == undefined) {
                return 0;
            }
            else {
                last = s.size() - 1;
            }
        }

        // Skip leading nulls
        for (int i = first; i <= last; ++i) {
            if (s[i] == '0') {
                first = i;
            }
            else {
                break;
            }
        }

        long long int result = 0;

        int constexpr max = std::numeric_limits<int>::max();
        int constexpr min = std::numeric_limits<int>::min();

        // Parse the number from last symbol to first
        long long int degree = 1;
        for (int i = last; i >= first; --i) {
            result += degree * (s[i] - '0');

            if (!isNegative && (result > max || degree > max)) {
                return max;
            }
            if (isNegative && (-result < min || -degree < min)) {
                return min;
            }

            degree *= 10;
        }

        return isNegative ? -result : result;
    }
};
