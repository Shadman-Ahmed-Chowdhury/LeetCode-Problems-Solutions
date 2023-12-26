// Problem link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

// My solution:
class Solution {
public:
    const int mod = (int)pow(10, 9) + 7;
    int numRollsToTarget(int n, int k, int target) {
        vector <vector<int>> dp(n + 1, vector <int> (target + 1, -1));
        return helperFunction(n, k, target, dp);
    }

    int helperFunction(int n, int k, int target, vector <vector <int>>& dp) {
        if(n < 0 || target < 0) 
            return 0;
        if(n == 0 && target == 0) 
            return 1;
        if(dp[n][target] != -1) 
            return dp[n][target] % mod;
        int totalWays = 0;
        for(int i = 1; i <= k; i++) {
            if(i <= target) {
                totalWays = (totalWays + helperFunction(n - 1, k, target - i, dp)) % mod;
            }
        }
        dp[n][target] = totalWays % mod;
        return totalWays % mod;
    }
};