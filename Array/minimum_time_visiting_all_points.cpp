// Problem link: https://leetcode.com/problems/minimum-time-visiting-all-points/description/

// My solution:
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int timeToReach = 0;
        for(int i = 0; i < n - 1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = points[i + 1][0];
            int y2 = points[i + 1][1];

            timeToReach += max(abs(x1 - x2), abs(y1 - y2));
        }
        return timeToReach;
    }
};