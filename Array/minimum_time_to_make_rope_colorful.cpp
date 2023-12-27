// Problem link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/

// My solution:
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int totalTime = 0;
        int i = 0;
        int j = 0;

        while(i < n && j < n) {
            int current = 0;
            int currentMax = 0;

            while(colors[i] == colors[j] && j < n) {
                currentMax = max(currentMax, neededTime[j]);
                current += neededTime[j++];
            }
            totalTime += current - currentMax;
            i = j;
        }
        return totalTime;
    }
};