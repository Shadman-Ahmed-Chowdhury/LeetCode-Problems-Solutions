// Problem link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

// My solution:
class Solution {
public:
    int dp[301][11];
    int helperFunction(vector<int>& jobDifficulty, int n, int idx, int d) {
        if (d == 1) {
            int maxD = jobDifficulty[idx];
            for(int i = idx; i < n; i++) {
                maxD = max(maxD, jobDifficulty[i]);
            }
            return maxD;
        }

        if(dp[idx][d] != -1) {
            return dp[idx][d];
        }
        int maxD = jobDifficulty[idx];
        int finalResult = INT_MAX;

        for(int i = idx; i <= n - d; i++) {
            maxD = max(maxD, jobDifficulty[i]);

            int result = maxD + helperFunction(jobDifficulty, n, i + 1, d - 1);

            finalResult = min(finalResult, result);
        }
        return dp[idx][d] = finalResult;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        memset(dp, -1, sizeof(dp));
        return helperFunction(jobDifficulty, n, 0, d);
    }
};