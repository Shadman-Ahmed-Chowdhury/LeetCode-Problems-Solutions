// Problem link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/

// My solution:
class Solution {
public:
    int maxScore(string s) {
        int zeroCount = 0;
        int oneCount = count(s.begin(), s.end(), '1');
        int ans = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == '1') {
                oneCount--;
            } else {
                zeroCount++;
            }

            ans = max(ans, oneCount + zeroCount);
        }
        return ans;
    }
};