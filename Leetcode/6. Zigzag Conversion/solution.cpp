class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        std::string result;
        result.reserve(s.size());

        for (int r = 0; r < numRows; ++r) {
            int shift1 = (numRows - r) * 2 - 2;
            int shift2 = (r + 1) * 2 - 2;

            // true = shift1, false = shift2
            bool shiftType = true;

            int i = r;
            while (i < s.size()) {
                result.push_back(s[i]);
                if (r == 0 || r == numRows - 1) {
                    i += numRows * 2 - 2;
                }
                else {
                    i += shiftType ? shift1 : shift2;
                    shiftType = !shiftType;
                }
            }
        }
        return result;
    }
};