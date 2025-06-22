class Solution {
public:
    string longestPalindrome(string s) {
        
        int begin = 0;
        int end = 0;

        auto findPalindrome = [&begin, &end, &s] (int l, int r) {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (end - begin < r - l) {
                    begin = l;
                    end = r;
                }
                --l;
                ++r;
            }
        };

        for (int i = 0; i < s.size(); ++i) {
            // Check 'odd' palindroms:
            findPalindrome(i - 1, i + 1);

            // Check 'even' palindroms:
            findPalindrome(i, i + 1);
        }

        return s.substr(begin, end - begin + 1);
    }
};
