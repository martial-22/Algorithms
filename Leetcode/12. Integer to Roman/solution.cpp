class Solution {
public:

    struct RomanValues {
        char one;
        char five;
    };

    string intToRoman(int num) {

        // Mapping degree -> values
        constexpr int numDegrees = 4;
        std::array<RomanValues, numDegrees> degreeToValues;

        degreeToValues[0] = {'I', 'V'};
        degreeToValues[1] = {'X', 'L'};
        degreeToValues[2] = {'C', 'D'};
        degreeToValues[3] = {'M', ' '};

        string result;

        int degree = 0;

        while (num != 0) {
            int value = num % 10;
            RomanValues romanValues = degreeToValues[degree];

            // Add symbols in reverse order
            switch (value) {
                case 4: {
                    result.push_back(romanValues.five);
                    result.push_back(romanValues.one);
                    break;
                }
                case 9: {
                    result.push_back(degreeToValues[degree + 1].one);
                    result.push_back(romanValues.one);
                    break;
                }
                default: {
                    if (value >= 5) {
                        value -= 5;
                        while (value > 0) {
                            result.push_back(romanValues.one);
                            value--;
                        }
                        result.push_back(romanValues.five);
                    }
                    else {
                        while (value > 0) {
                            result.push_back(romanValues.one);
                            value--;
                        }
                    }
                    break;
                }
            }

            num = num / 10;
            degree++;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};