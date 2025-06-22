class Solution {
public:
    string longestPalindrome(string s) {
        // Solution by dynamic 
        std::vector<bool> dp, dpStored;

        dp.reserve(s.size());
        dpStored.reserve(s.size());

        int maxPDFirst = 0;
        int maxPDLast = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            dp.assign(s.size(), false);
            dp[i] = true;

            for (int j = i + 1; j < s.size(); ++j) {
                const int substrFirst = i + 1;
                const int substrLast = j - 1;

                if (substrFirst < substrLast) {
                    dp[j] = s[i] == s[j] && dpStored[substrLast];
                }
                else {
                    dp[j] = s[i] == s[j];
                }

                if (dp[j] && maxPDLast - maxPDFirst <= j - i) {
                    maxPDFirst = i;
                    maxPDLast = j;
                }
            }
            dpStored = std::move(dp);
        }

        return s.substr(maxPDFirst, maxPDLast - maxPDFirst + 1);
    }
};
