class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int maxLength = 0, currentCost = 0, start = 0;

        for (int end = 0; end < n; ++end) {
            currentCost += abs(s[end] - t[end]);

            while (currentCost > maxCost) {
                currentCost -= abs(s[start] - t[start]);
                start++;
            }

            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};
