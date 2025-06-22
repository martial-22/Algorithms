class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        constexpr int undefinedPos = -1;
        std::array<int, 256> symbolToLastPos;
        symbolToLastPos.fill(undefinedPos);

        int score = 0;
        int begin = 0;

        for (int i = 0; i <= s.length(); ++i) {
            score = std::max(score, i - begin);
            if (i == s.length()) {
                break;
            }

            if (symbolToLastPos[s[i]] >= begin) {
                begin = symbolToLastPos[s[i]] + 1;
            }
            symbolToLastPos[s[i]] = i;
        }
        return score;
    }
};
