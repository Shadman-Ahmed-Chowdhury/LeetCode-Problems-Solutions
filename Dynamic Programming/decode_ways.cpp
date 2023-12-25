// Problem link: https://leetcode.com/problems/decode-ways/description/

// My solution:
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n == 0 || s[0] == '0') {
            return 0;
        }

        vector <int> dp(2, 1);
        for(int i = 1; i < n; i++) {
            int count = 0;
            if(s[i] != '0')
                count += dp[1];
            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                count += dp[0];
            }
            dp[0] = dp[1];
            dp[1] = count;
        }
        return dp[1];
    }
};